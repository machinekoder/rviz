//
// Created by alexander on 9/17/20.
//

#ifndef RVIZ_QUICK_RVIZ_VIEW_H
#define RVIZ_QUICK_RVIZ_VIEW_H

#include "quick_rviz_object.h"

#include "view_controller.h"

namespace rviz {

class QuickRvizView: public QuickRvizObject
{
  Q_OBJECT

public:
  explicit QuickRvizView(QObject* parent = Q_NULLPTR);
  ~QuickRvizView() override;

public Q_SLOTS:

  void setPropertyValue(const QString &key, const QVariant &value);

Q_SIGNALS:
  void viewCreated();

private Q_SLOTS:
  void initialize() override;
  void initView();

private:
  bool initialized_;
  ViewController* view_;
};

}  // namespace rviz

#endif // RVIZ_QUICK_RVIZ_VIEW_H
