import QtQuick 2.0
import QtQuick.Controls 2.0
import ros.rviz 1.0

ApplicationWindow {
  id: root
  width: 1024
  height: 768
  visible: true

  Rectangle {
    anchors.fill: parent
    color: "lightblue"

    RenderWindow {
      id: renderWindow
      anchors.fill: parent
      anchors.margins: 20
    }
  }

  VisualizationFrame {
    id: visualizationFrame
    anchors.fill: parent
    renderWindow: renderWindow
  }

  RvizDisplay {
    id: axesDisplay
    property string activeFrame: "world"
    frame: visualizationFrame
    classLookupName: "rviz/Axes"
    name: "Axes"
    onDisplayCreated: {
      setPropertyValue("Reference Frame", activeFrame)
      setPropertyValue("Length", 0.3)
      setPropertyValue("Radius", 0.03)
    }
  }

  RvizTools {
    id: tools
    frame: visualizationFrame
    toolNames: ["rviz/Interact", "rviz/MoveCamera"]

    onToolsCreated: {
      setCurrentTool("rviz/Interact")
    }
  }

  RvizOptions {
    fixedFrame: "world"
    backgroundColor: "black"
    frame: visualizationFrame
  }

  RvizView {
    frame: visualizationFrame
    onViewCreated: {
      setPropertyValue("Distance", 2.5)
      setPropertyValue("Yaw", Math.PI * 1.75)
      setPropertyValue("Pitch", Math.PI * 0.25)
      setPropertyValue("Focal Point/X", 0.5)
      setPropertyValue("Focal Point/Y", -0.5)
      setPropertyValue("Focal Point/Z", 1.0)
    }
  }
}
