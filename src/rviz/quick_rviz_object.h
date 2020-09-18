//
// Created by alexander on 9/16/20.
//
#ifndef RVIZ_QUICK_RVIZ_OBJECT_H
#define RVIZ_QUICK_RVIZ_OBJECT_H

#include <QObject>

#include "quick_visualization_frame.h"

namespace rviz {

class QuickRvizObject: public QObject
{
  Q_OBJECT
  Q_PROPERTY(QuickVisualizationFrame* frame READ getFrame WRITE setFrame NOTIFY frameChanged)

public:
  explicit QuickRvizObject(QObject* parent = Q_NULLPTR);
  ~QuickRvizObject() override;

  QuickVisualizationFrame* getFrame();

public Q_SLOTS:
  void setFrame(QuickVisualizationFrame *frame);

Q_SIGNALS:
  void frameChanged(QuickVisualizationFrame* frame);

private Q_SLOTS:
  virtual void initialize();

private:
  QuickVisualizationFrame* frame_;
};

}  // namespace rviz
#endif // RVIZ_QUICK_RVIZ_OBJECT_H
