import QtQuick 2.3

Rectangle {
    id: button
    signal clicked
    border.color: "black"
    width: 50
    height: 50
    color: "gray"
    property real textHeight: height - 8
    property alias text: text.text
    property alias fontSize: text.font.pixelSize

    scale:  mouseArea.containsMouse ? 0.95 : 1.0
    border.width: mouseArea.containsMouse ? 7 : 3
    smooth: mouseArea.containsMouse  

    Text {
        id: text
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        text: text
        font.pixelSize: fontSize
        height: parent.textHeight
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: button.clicked()
    }
}
