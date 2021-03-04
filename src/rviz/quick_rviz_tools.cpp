//
// Created by alexander on 9/17/20.
//
#include "quick_rviz_tools.h"

#include "visualization_manager.h"
#include "tool_manager.h"

namespace rviz
{

QuickRvizTools::QuickRvizTools(QObject* parent)
  : QuickRvizObject(parent)
  , initialized_(false)
{
  connect(this, &QuickRvizTools::toolNamesChanged, this, &QuickRvizTools::initTools);
}

QuickRvizTools::~QuickRvizTools()
{
  removeTools();
}

const QStringList QuickRvizTools::getToolNames()
{
  return toolNames_;
}

void QuickRvizTools::setToolNames(const QStringList& toolNames)
{
  if (toolNames_ == toolNames) {
    return;
  }
  toolNames_ = toolNames;
  Q_EMIT toolNamesChanged();
}

bool QuickRvizTools::setCurrentTool(const QString& name)
{
  if (tools_.count(name) == 0) {
    return false;
  }
  auto tool = tools_[name];
  const auto toolManager = getFrame()->getManager()->getToolManager();
  toolManager->setCurrentTool(tool);
  return true;
}

void QuickRvizTools::initialize()
{
  initialized_ = true;

  if (tools_.empty()) {
    initTools();
  }
}

void QuickRvizTools::removeTools()
{
  const auto frame = getFrame();
  if (frame)
  {
    const auto toolManager = frame->getManager()->getToolManager();
    toolManager->removeAll();
  }
  tools_.clear();
}

void QuickRvizTools::initTools()
{
  if (!initialized_) {
    return;
  }

  removeTools();

  const auto toolManager = getFrame()->getManager()->getToolManager();
  for (const auto &name: toolNames_) {
    auto tool = toolManager->addTool(name);
    if (tool) {
      tools_[name] = tool;
    }
  }

  if (!tools_.empty()) {
    Q_EMIT toolsCreated();
  }
}

}  // namespace rviz
