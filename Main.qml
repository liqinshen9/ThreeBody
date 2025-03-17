import QtQuick
import Backend 1.0
import Paint 1.0

Window {
    //Can be considered a QQuickItem
    width: 900
    height: 700
    visible: true
    title: qsTr("Hello World")

    View {
        id: root
        width: parent.width
        height: parent.height

        Component.onCompleted: {
            initialize()
        }
    }
}
