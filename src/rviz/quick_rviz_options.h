//
// Created by alexander on 9/17/20.
//

#ifndef RVIZ_QUICK_RVIZ_OPTIONS_H
#define RVIZ_QUICK_RVIZ_OPTIONS_H

#include "quick_rviz_object.h"

namespace rviz
{

class QuickRvizOptions: public QuickRvizObject
{
  Q_OBJECT
  Q_PROPERTY(QString fixedFrame READ getFixedFrame WRITE setFixedFrame NOTIFY fixedFrameChanged)
  Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
  Q_PROPERTY(int frameRate READ getFrameRate WRITE setFrameRate NOTIFY frameRateChanged)
  Q_PROPERTY(bool defaultLight READ getDefaultLight WRITE setDefaultLight NOTIFY defaultLightChanged)

public:
  explicit QuickRvizOptions(QObject* parent = Q_NULLPTR);
  ~QuickRvizOptions() override;

  const QString getFixedFrame();
  const QColor getBackgroundColor();
  int getFrameRate();
  bool getDefaultLight();

public Q_SLOTS:
  void setFixedFrame(const QString &frame);
  void setBackgroundColor(const QColor &color);
  void setFrameRate(int fps);
  void setDefaultLight(bool value);

Q_SIGNALS:
  void fixedFrameChanged(const QString &frame);
  void backgroundColorChanged(const QColor &color);
  void frameRateChanged(int fps);
  void defaultLightChanged(bool value);

private Q_SLOTS:
  void initialize() override;
  void updateProperties();

private:
  bool initialized_;
  QString fixedFrame_;
  QColor backgroundColor_;
  int frameRate_;
  bool defaultLight_;
};

}  // namespace rviz
#endif // RVIZ_QUICK_RVIZ_OPTIONS_H
