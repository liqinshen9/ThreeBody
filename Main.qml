import QtQuick
import Backend 1.0
import Paint 1.0

Window {
    //Can be considered a QQuickItem
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    View {
        id: root
        width: parent.width
        height: parent.height
        PaintBall {
            x:30
            y:30
            width: 100
            height: 100
        }
    }
}
