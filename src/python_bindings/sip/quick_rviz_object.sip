namespace rviz {

class QuickRvizObject: public QObject
{
%TypeHeaderCode
#define ROS_PACKAGE_NAME "rviz"
#include <rviz/quick_rviz_object.h>
%End

public:
  explicit QuickRvizObject(QObject* parent = Q_NULLPTR);

  rviz::QuickVisualizationFrame* getFrame();

};

};
