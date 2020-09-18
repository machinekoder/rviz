//
// Created by alexander on 9/16/20.
//
#include "quick_rviz_object.h"

namespace rviz
{

QuickRvizObject::QuickRvizObject(QObject* parent)
  : QObject(parent)
  , frame_(nullptr)
{

}

QuickRvizObject::~QuickRvizObject()
{
}

void QuickRvizObject::initialize()
{
}

QuickVisualizationFrame* QuickRvizObject::getFrame()
{
  return frame_;
}

void QuickRvizObject::setFrame(QuickVisualizationFrame* frame)
{
  if (frame_ == frame) {
    return;
  }
  frame_ = frame;
  Q_EMIT frameChanged(frame);

  if (frame->isInitialized()) {
    initialize();
  }
  else {
    connect(frame_, &QuickVisualizationFrame::initializedChanged, this, &QuickRvizObject::initialize);
  }
}

}  // namespace rviz
