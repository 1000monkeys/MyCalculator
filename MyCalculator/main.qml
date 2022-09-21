import QtQuick 2.9
import QtQuick.Window 2.2

import Logic 1.0

Window {
    id: mainWindow
    visible: true
    width: 268
    height: 264
    title: qsTr("Calculator by Kjell Vos in C++/Qt/QML")

    Item {
        focus: true
        id: keyboardInputArea
        width: mainWindow.width
        height: mainWindow.height

        Keys.onReleased:
        {
            console.log("Key pressed # " + event.text);
        }
    }

    Style
    {
        id: style
    }

    Logic {
        id: logic
    }

    //Text/input/result
    Rectangle {
        id: resultBox

        x: style.margin
        y: style.margin
        width: (parent.width - (style.margin * 3) - style.btnWidth)
        height: 45

        color: "white"

        border.color: "black"
        border.width: style.borderWidth

        Text {
            id: resultText
            anchors.leftMargin: 15
            anchors.rightMargin: 15
            anchors.fill: parent
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
            text: logic.inputString
            color: "black"
            font.pixelSize: 32
            font.family: "Open Sans Regular"
            fontSizeMode: Text.Fit
        }
    }

    Item {
        id: buttons
        Button {
            x: resultBox.width + style.margin * 2
            y: 0

            width: style.btnWidth
            height: style.btnHeight

            text: "C"
            fontSize: 28
            onClicked: {
                logic.removeLast();
            }
        }

        /* 111 */
        Button {
            x: style.margin
            y: (style.margin + style.btnWidth) * 1

            width: style.btnWidth
            height: style.btnHeight

            text: "m+"
            fontSize: 28
            onClicked: {
                logic.memoryPlus();
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 1
            y: (style.margin + style.btnWidth) * 1

            width: style.btnWidth
            height: style.btnHeight

            text: "7"
            fontSize: 28
            onClicked: {
                logic.inputString = text;
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 2
            y: (style.margin + style.btnWidth) * 1

            width: style.btnWidth
            height: style.btnHeight

            text: "8"
            fontSize: 28
            onClicked: {
                logic.inputString = text;
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 3
            y: (style.margin + style.btnWidth) * 1

            width: style.btnWidth
            height: style.btnHeight

            text: "9"
            fontSize: 28
            onClicked: {
                logic.inputString = text;
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 4
            y: (style.margin + style.btnWidth) * 1

            width: style.btnWidth
            height: style.btnHeight

            text: "/"
            fontSize: 42
            onClicked: {
                logic.inputString = text;
            }
        }

        /* 222 */
        Button {
            x: style.margin
            y: (style.margin + style.btnWidth) * 2

            width: style.btnWidth
            height: style.btnHeight

            text: "m-"
            fontSize: 28
            onClicked: {
                logic.memoryMinus();
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 1
            y: (style.margin + style.btnWidth) * 2

            width: style.btnWidth
            height: style.btnHeight

            text: "4"
            fontSize: 28
            onClicked: {
                logic.inputString = text;
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 2
            y: (style.margin + style.btnWidth) * 2

            width: style.btnWidth
            height: style.btnHeight

            text: "5"
            fontSize: 28
            onClicked: {
                logic.inputString = text;
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 3
            y: (style.margin + style.btnWidth) * 2

            width: style.btnWidth
            height: style.btnHeight

            text: "6"
            fontSize: 28
            onClicked: {
                logic.inputString = text;
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 4
            y: (style.margin + style.btnWidth) * 2

            width: style.btnWidth
            height: style.btnHeight

            text: "*"
            fontSize: 42
            onClicked: {
                logic.inputString = text;
            }
        }

        /* 333 */
        Button {
            x: style.margin
            y: (style.margin + style.btnWidth) * 3

            width: style.btnWidth
            height: style.btnHeight

            text: "mc"
            fontSize: 28
            onClicked: {
                logic.memoryClear();
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 1
            y: (style.margin + style.btnWidth) * 3

            width: style.btnWidth
            height: style.btnHeight

            text: "1"
            fontSize: 28
            onClicked: {
                logic.inputString = text;
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 2
            y: (style.margin + style.btnWidth) * 3

            width: style.btnWidth
            height: style.btnHeight

            text: "2"
            fontSize: 28
            onClicked: {
                logic.inputString = text;
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 3
            y: (style.margin + style.btnWidth) * 3

            width: style.btnWidth
            height: style.btnHeight

            text: "3"
            fontSize: 28
            onClicked: {
                logic.inputString = text;
            }
        }

        /* 444 */
        Button {
            x: style.margin
            y: (style.margin + style.btnWidth) * 4

            width: style.btnWidth
            height: style.btnHeight

            text: "ce"
            fontSize: 42
            onClicked: {
                logic.clear();
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 4
            y: (style.margin + style.btnWidth) * 3

            width: style.btnWidth
            height: style.btnHeight

            text: "-"
            fontSize: 42
            onClicked: {
                logic.inputString = text;
            }
        }

        Button {
            x: style.margin + (style.margin + style.btnWidth) * 1
            y: (style.margin + style.btnWidth) * 4

            width: style.btnWidth
            height: style.btnHeight

            text: "."
            fontSize: 28
            onClicked: {
                logic.inputString = text;
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 2
            y: (style.margin + style.btnWidth) * 4

            width: style.btnWidth
            height: style.btnHeight

            text: "0"
            fontSize: 28
            onClicked: {
                logic.inputString = text;
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 3
            y: (style.margin + style.btnWidth) * 4

            width: style.btnWidth
            height: style.btnHeight

            text: "="
            fontSize: 28
            onClicked: {
                logic.calculate();
            }
        }
        Button {
            x: style.margin + (style.margin + style.btnWidth) * 4
            y: (style.margin + style.btnWidth) * 4

            width: style.btnWidth
            height: style.btnHeight

            text: "+"
            fontSize: 42
            onClicked: {
                logic.inputString = text;
            }
        }
    }
}
