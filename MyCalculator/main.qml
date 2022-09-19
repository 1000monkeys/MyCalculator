import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: mainWindow
    visible: true
    width: 278
    height: 328
    title: qsTr("Calculator by Kjell Vos in C++/Qt/QML")
    property real pixelDensity: Screen.pixelDensity

    Item {
        focus: true
        id: keyboardInputArea
        width: mainWindow.width
        height: mainWindow.height

        Keys.onReleased:
        {
            //console.log("Key pressed # " + event.text);
            console.log(Screen.pixelDensity);
            console.log((parent.width - (style.margin * 2)) *  mainWindow.pixelDensity);
        }
    }

    Style
    {
        id: style
    }

    //Text/input/result
    Rectangle {
        id: resultBox


        x: style.margin
        y: style.margin
        width: (parent.width - (style.margin * 2))
        height: style.btnHeight

        color: "black"

        border.color: "gray"
        border.width: style.borderWidth
    }

    Item {
        id: buttons
        Button {
            x: style.margin * 2 + style.btnWidth * 1
            y: style.margin + style.btnHeight * 1

            width: style.btnWidth
            height: style.btnHeight

            text: "mc"
            fontSize: 28
        }
        Button {
            x: style.margin * 2 + style.btnWidth * 2
            y: style.margin + style.btnHeight * 1

            width: style.btnWidth
            height: style.btnHeight

            text: "m-"
            fontSize: 28
        }
        Button {
            x: style.margin * 2 + style.btnWidth * 3
            y: style.margin + style.btnHeight * 1

            width: style.btnWidth
            height: style.btnHeight

            text: "m+"
            fontSize: 28
        }

        Button {
            x: style.margin * 2 + style.btnWidth * 4
            y: style.margin + style.btnHeight * 2

            width: style.btnWidth
            height: style.btnHeight

            text: "\\"
            fontSize: 42
        }
        Button {
            x: style.margin * 2 + style.btnWidth * 4
            y: style.margin + style.btnHeight * 3

            width: style.btnWidth
            height: style.btnHeight

            text: "*"
            fontSize: 42
        }
        Button {
            x: style.margin * 2 + style.btnWidth * 4
            y: style.margin + style.btnHeight * 4

            width: style.btnWidth
            height: style.btnHeight

            text: "-"
            fontSize: 42
        }
        Button {
            x: style.margin * 2 + style.btnWidth * 4
            y: style.margin + style.btnHeight * 5

            width: style.btnWidth
            height: style.btnHeight

            text: "+"
            fontSize: 42
        }
    }
}
