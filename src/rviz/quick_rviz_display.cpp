//
// Created by alexander on 9/16/20.
//
#include "quick_rviz_display.h"
#include "visualization_manager.h"

namespace rviz
{

QuickRvizDisplay::QuickRvizDisplay(QObject* parent)
  : QuickRvizObject(parent)
  , created_(false)
  , display_(nullptr)
{
  connect(this, &QuickRvizDisplay::classLookupNameChanged, this, &QuickRvizDisplay::initDisplay);
  connect(this, &QuickRvizDisplay::nameChanged, this, &QuickRvizDisplay::initDisplay);
}

QuickRvizDisplay::~QuickRvizDisplay()
{
  destroy();
}

const QString QuickRvizDisplay::getClassLookupName()
{
  return classLookupName_;
}

const QString QuickRvizDisplay::getName()
{
  return name_;
}

bool QuickRvizDisplay::getCreated()
{
  return created_;
}

void QuickRvizDisplay::setClassLookupName(const QString& name)
{
  if (name == classLookupName_) {
    return;
  }
  classLookupName_ = name;
  Q_EMIT classLookupNameChanged(name);
}

void QuickRvizDisplay::setName(const QString& name)
{
  if (name == name_) {
    return;
  }
  name_ = name;
  Q_EMIT nameChanged(name);
}

void QuickRvizDisplay::initialize()
{
  initialized_ = true;
  if (!display_) {
    initDisplay();
  }
}

void QuickRvizDisplay::setPropertyValue(const QString& key, const QVariant& value)
{
  if (!created_) {
    return;
  }
  auto keys = key.split('/');
  Property *prop = display_;
  for (const auto &k: keys) {
    prop = prop->subProp(k);
  }
  prop->setValue(value);
}

void QuickRvizDisplay::initDisplay()
{
  if (!initialized_) {
    return;
  }

  if (display_) {
    destroy();
  }

  if (name_.isEmpty() or classLookupName_.isEmpty()) {
    return;
  }

  display_ = nullptr;
  const auto frame = getFrame();
  if (!frame) {
    return;
  }
  const auto visManager = frame->getManager();
  display_ = visManager->createDisplay(classLookupName_, name_, true);
  if (display_) {
    created_ = true;
    Q_EMIT createdChanged(true);
    Q_EMIT displayCreated();
  }
}
void QuickRvizDisplay::destroy()
{
  if (!display_) {
    return;
  }

  display_->getParent()->takeChild(display_);
  display_->deleteLater();
  display_ = nullptr;
}

}  // namespace rviz
