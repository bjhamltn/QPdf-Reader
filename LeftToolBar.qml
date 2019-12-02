import QtQuick 2.12
import QtQuick.Controls 2.12
Rectangle{
    id: left_toolPane
    width: 45;
    anchors.left: parent.left
    anchors.leftMargin: 0
    anchors.top: toolBar.bottom;
    anchors.topMargin: 0
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 0
    color: bgColor_toolPanels
    z:2;
    MouseArea{
        anchors.fill: parent;
        hoverEnabled: true;
    }
    Column{
        y: 0
        spacing: 12
        width: parent.width
        anchors.top: parent.top;
        anchors.topMargin: 50;
        Rectangle{
            width: parent.width;
            height: width;
            color:toolBarBtnBg
            RoundButton
            {
                flat: false
                background: Image
                {
                    source: "ic1"
                }

                display: AbstractButton.IconOnly
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
            MouseArea{
                anchors.fill: parent;
                onPressed: {
                    outlinePanel.state  = "closed";
                    searchResultsView.state = "closed";
                    folders.state  = folders.state === "closed"? "" : "closed";
                }
            }
        }
        Rectangle{
            width: parent.width;
            height: width;
            color:toolBarBtnBg
            RoundButton
            {
                flat: false
                background: Image
                {
                    source: "ic3"
                }
                display: AbstractButton.IconOnly
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
            MouseArea{
                anchors.fill: parent;
                onPressed: {
                    folders.state  = "closed";
                    searchResultsView.state = "closed";
                    outlinePanel.state  = outlinePanel.state === ""? "closed" : "";

                }
            }
        }
        Rectangle{
            width: parent.width;
            height: width;
            color:toolBarBtnBg

            RoundButton
            {
                flat: false
                background: Image
                {
                    source: fitSrchIcon
                }
                display: AbstractButton.IconOnly
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
            MouseArea{
                anchors.fill: parent;
                onPressed: {
                    folders.state = outlinePanel.state = "closed";
                    searchResultsView.state = searchResultsView.state === "open" ? "closed" : "open";
                }
            }
        }
    }
    Rectangle {
        id: rectangle3
        width: 1
        color: border_color_outerEdge;
        border.width: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
    }
}

