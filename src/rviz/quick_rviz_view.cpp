//
// Created by alexander on 9/17/20.
//
#include "quick_rviz_view.h"

#include "visualization_manager.h"
#include "view_manager.h"

namespace rviz {

QuickRvizView::QuickRvizView(QObject* parent)
  : QuickRvizObject(parent)
  , initialized_(false)
  , view_(nullptr)
{
}

QuickRvizView::~QuickRvizView()
{
}

void QuickRvizView::setPropertyValue(const QString& key, const QVariant& value)
{
  auto keys = key.split('/');
  Property *prop = view_;
  for (const auto &k: keys) {
    prop = prop->subProp(k);
  }
  prop->setValue(value);
}

void QuickRvizView::initialize()
{
  initialized_ = true;

  if (!view_) {
    initView();
  }
}

void QuickRvizView::initView()
{
  if (!initialized_) {
    return;
  }

  view_ = getFrame()->getManager()->getViewManager()->getCurrent();
  Q_EMIT viewCreated();
}

}  // namespace rviz
