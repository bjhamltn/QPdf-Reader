import QtQuick 2.12
import  QtQuick.Controls 2.12

Frame{
    id:workspace
    visible: true
    clip: false
    padding: 0
    anchors.top:  parent.top;
    anchors.bottom: parent.bottom;
    anchors.right: parent.right;    
    background: Rectangle{
        border.width: 0;
        color: "#00000000";
    }
}
