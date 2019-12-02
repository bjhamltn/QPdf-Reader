import QtQuick 2.13
import QtQuick.Controls 2.13
Item {
    property var listModel;
    property var listType;
    property var itemHeight;
    itemHeight: 85/2;
    anchors.fill: parent;
    function  gotoDetailsX(citem){
         gotoDetails(citem);
    }




ListView{
    id:listViewBase;
    spacing:0;
    anchors.fill: parent;
    clip: true;
    model: listModel;    
    boundsBehavior : Flickable.StopAtBounds ;
    highlightFollowsCurrentItem :false;
    highlight:  Rectangle {
        z:0        
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.leftMargin: 0;
        anchors.rightMargin: 0;
        height: itemHeight;
        color: highlightColor;
        radius: 0;
        y: listViewBase.currentItem.y
        Behavior on y {
            NumberAnimation {
                duration: 300;
                easing.type: Easing.OutExpo;
            }
        }
    }     
    delegate: Item {
        width: parent.width;
        height: itemHeight;
        id:citem
        property var fleet: model.modelData.fleet;
        property var documents: model.modelData.documents;
        property var namingConvention: model.modelData.NamingConvention;
        property var filePath: model.modelData.contentDir+"/"+namingConvention;
        property var description: model.modelData.Description;
        property var docAcronym: model.modelData.DocAcronym;
        property var inProduction: model.modelData.InProduction;        
        property var itemIdx: index;
        Rectangle{
            id:bgRect
            width: parent.width;
            height: parent.height;
            color: themeSwitch.checked? "#7f1a1a1a": "#7fd5f6ff";
        }
        Column{
            id:col_content;
            width: parent.width;            
            anchors.verticalCenter: bgRect.verticalCenter
            Text {
                id:text_main
                x: 5/devicePixelRatio
                text: listType === "fleets" ? fleet : docAcronym;
                font.pixelSize: listType === "fleets" ? ui_FontSize_lrg : ui_FontSize_lrg;
                width: parent.width;                
                color: listPanel_text_color;
                horizontalAlignment: Text.AlignHCenter;
            }
            Text {
                x: 5/devicePixelRatio
                id:subText;
                height: listType === "fleets" ? 0 : text_main.height;
                text: listType === "fleets" ? "" : description;
                font.pixelSize: ui_FontSize_Med;
                width: parent.width;                
                color: listPanel_text_color;
                horizontalAlignment: Text.AlignHCenter;
            }
        }
        MouseArea{
            anchors.fill: bgRect            
            onClicked: {
                listViewBase.currentIndex = index;
                gotoDetailsX(citem);
            }

        }        
    }
}


}
