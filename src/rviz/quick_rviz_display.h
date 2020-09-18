//
// Created by alexander on 9/16/20.
//

#ifndef RVIZ_QUICK_RVIZ_DISPLAY_H
#define RVIZ_QUICK_RVIZ_DISPLAY_H

#include "quick_rviz_object.h"
#include "visualization_manager.h"
#include "display.h"

namespace rviz
{

class QuickRvizDisplay: public QuickRvizObject
{
  Q_OBJECT
  Q_PROPERTY(QString classLookupName READ getClassLookupName WRITE setClassLookupName NOTIFY classLookupNameChanged)
  Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
  Q_PROPERTY(bool created READ getCreated NOTIFY createdChanged)

public:
  explicit QuickRvizDisplay(QObject* parent = Q_NULLPTR);
  ~QuickRvizDisplay() override;

  const QString getClassLookupName();
  const QString getName();
  bool getCreated();

public Q_SLOTS:
  void setClassLookupName(const QString &name);
  void setName(const QString &name);

  void setPropertyValue(const QString &key, const QVariant &value);

Q_SIGNALS:
  void classLookupNameChanged(const QString &name);
  void nameChanged(const QString &name);
  void createdChanged(bool created);
  void displayCreated();

private Q_SLOTS:
  void initialize() override;
  void initDisplay();
  void destroy();

private:
  bool initialized_;
  bool created_;
  Display *display_;
  QString classLookupName_;
  QString name_;
};

}  // namespace rviz
#endif // RVIZ_QUICK_RVIZ_DISPLAY_H
