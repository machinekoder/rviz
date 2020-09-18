//
// Created by alexander on 9/17/20.
//
#include "quick_rviz_options.h"

#include "visualization_manager.h"
#include "display_group.h"

namespace rviz
{

QuickRvizOptions::QuickRvizOptions(QObject *parent)
  : QuickRvizObject(parent)
  , initialized_(false)
  , backgroundColor_(QColor("black"))
  , frameRate_(30)
  , defaultLight_(true)
{

}

QuickRvizOptions::~QuickRvizOptions()
{
}

const QString QuickRvizOptions::getFixedFrame()
{
  return fixedFrame_;
}

const QColor QuickRvizOptions::getBackgroundColor()
{
  return backgroundColor_;
}

int QuickRvizOptions::getFrameRate()
{
  return frameRate_;
}

bool QuickRvizOptions::getDefaultLight()
{
  return frameRate_;
}

void QuickRvizOptions::setFixedFrame(const QString &frame)
{
  if (frame == fixedFrame_) {
    return;
  }
  fixedFrame_ = frame;
  Q_EMIT fixedFrameChanged(frame);
}

void QuickRvizOptions::setBackgroundColor(const QColor& color)
{
  if (color == backgroundColor_) {
    return;
  }
  backgroundColor_ = color;
  Q_EMIT backgroundColorChanged(color);
}

void QuickRvizOptions::setFrameRate(int fps)
{
  if (fps == frameRate_) {
    return;
  }
  frameRate_ = fps;
  Q_EMIT frameRateChanged(fps);
}

void QuickRvizOptions::setDefaultLight(bool value)
{
  if (value == defaultLight_) {
    return;
  }
  defaultLight_ = value;
  Q_EMIT defaultLightChanged(value);
}

void QuickRvizOptions::initialize()
{
  initialized_ = true;
  updateProperties();
}

void QuickRvizOptions::updateProperties()
{
  if (!initialized_ or !getFrame()) {
    return;
  }

  auto dpGroup = getFrame()->getManager()->getRootDisplayGroup()->subProp("Global Options");
  dpGroup->subProp("Fixed Frame")->setValue(fixedFrame_);
  dpGroup->subProp("Background Color")->setValue(backgroundColor_.name());
  dpGroup->subProp("Frame Rate")->setValue(frameRate_);
  dpGroup->subProp("Default Light")->setValue(defaultLight_);
}

}  // namespace rviz
