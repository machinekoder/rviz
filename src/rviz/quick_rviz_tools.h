//
// Created by alexander on 9/17/20.
//

#ifndef RVIZ_QUICK_RVIZ_TOOLS_H
#define RVIZ_QUICK_RVIZ_TOOLS_H

#include "quick_rviz_object.h"

#include "tool.h"

namespace rviz {

class QuickRvizTools: public QuickRvizObject
{
  Q_OBJECT
  Q_PROPERTY(QStringList toolNames READ getToolNames WRITE setToolNames NOTIFY toolNamesChanged)

public:
  explicit QuickRvizTools(QObject* parent = Q_NULLPTR);
  ~QuickRvizTools() override;

  const QStringList getToolNames();

public Q_SLOTS:
  void setToolNames(const QStringList &toolNames);
  bool setCurrentTool(const QString &name);

Q_SIGNALS:
  void toolNamesChanged();
  void toolsCreated();

private Q_SLOTS:
  void initialize() override;
  void initTools();

private:
  bool initialized_;
  std::map<QString, Tool*> tools_;
  QStringList toolNames_;

  void removeTools();
};

}  // namespace rviz

#endif // RVIZ_QUICK_RVIZ_TOOLS_H
