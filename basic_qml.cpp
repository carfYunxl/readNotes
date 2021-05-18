import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SwipeView {
          id: view
          currentIndex: pageIndicator.currentIndex
          anchors.fill: parent

          Page {
              title: qsTr("Home")
              header: ToolBar{
                  id:too
                  Row
                  {
                      ToolButton
                      {
                          id:openButton
                          text: "open"
                          onPressed: openButton.text = "pressed"
                      }
                      ToolButton
                      {
                          id:closeButton
                          text: "close"
                          //onClicked:
                      }
                      ToolButton
                      {
                          text: "save"
                      }
                  }


              }
              Label
              {
                  text: "hello"
                  anchors.fill: parent
                  anchors.centerIn: parent
                  color: "red"
              }
              footer: TabBar
              {
              }
          }
          Page {
              title: qsTr("Discover")
              header: ToolBar{
                  Row
                  {
                      ToolButton
                      {
                          text: "open"
                      }
                      ToolButton
                      {
                          text: "close"
                      }
                      ToolButton
                      {
                          text: "save"
                      }
                  }
              }
              Row
              {
                  Tumbler
                  {
                      id:t1
                      model:60
                  }
                  Tumbler
                  {
                      id:t2
                      model:12
                  }
                  Tumbler
                  {
                      id:t3
                      model:["AM","PM"]
                  }
              }
              footer: TabBar
              {
              }
          }
          Page {
              title: qsTr("Activity")
              header: ToolBar{
                  Row
                  {
                      ToolButton
                      {
                          text: "open"
                      }
                      ToolButton
                      {
                          text: "close"
                      }

                      ToolButton
                      {
                          text: "save"
                      }
                  }
              }
              Dial{
                  id:d
              }
              footer: TabBar
              {
                  TabButton{
                    text: qsTr("Home")
                  }
                  TabButton {
                            text: qsTr("Discover")
                        }
                        TabButton {
                            text: qsTr("Activity")
                        }
              }
          }
      }

      PageIndicator {
          id: pageIndicator
          interactive: true
          count: view.count
          currentIndex: view.currentIndex

          anchors.bottom: parent.bottom
          anchors.horizontalCenter: parent.horizontalCenter
      }


}