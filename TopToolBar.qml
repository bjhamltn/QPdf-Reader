import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls 1.2 as V1
import QtQuick.Controls.Styles 1.4
Frame{
    id:toolBar
    width: parent.width;
    height: 50;
    padding: 0;
    z:100;
    property alias pageNumbersTotal: txt_TotalPageNumbers;
    property alias pageNumberCurrent: txt_currentPageNumber;
    property alias themeSwitcher: themeSwitch
    Rectangle{
        id:toolBarbg;
        color: bgColor_toolPanels;
        anchors.fill: parent;
        border.width: 0;
        z:1
    }

    Switch {
        id: themeSwitch;
        text: "Light";

        anchors.left: parent.left;
        anchors.leftMargin: 0;

        anchors.top:parent.top;
        anchors.verticalCenter: parent.verticalCenter;
        z:1
        indicator: Rectangle {
            implicitWidth: 48;
            implicitHeight: 26;
            x: themeSwitch.leftPadding;
            y: parent.height / 2 - height / 2;
            radius: 13;
            color: "#ada0a0";
            Rectangle {
                id:numb;
                x: 0;
                width: 26;
                height: 26;
                radius: 13;
                state: themeSwitch.checked? "enabled" : "";
                color: "#ffffff";
                border.color: "#ada0a0";
                states: [
                    State {
                        name: "enabled";
                        PropertyChanges {target: numb;  x:  parent.width - width; }
                        PropertyChanges {target: numb;  color: "#ada0a0" }
                        PropertyChanges {target: numb.parent;  color:  "#3d3d3d" }
                    }
                ]
                transitions: Transition {
                    reversible: true;
                    from: "";
                    to: "enabled";
                    NumberAnimation{
                        properties: "x"
                        duration: 100; easing.type: Easing.InOutBounce;
                    }
                }
            }

        }
        contentItem:Text {

            text: themeSwitch.checked ? "Dark" : themeSwitch.text;
            font: themeSwitch.font
            color: themeSwitch.checked ? "white" : "black"
            verticalAlignment: Text.AlignVCenter
            leftPadding: themeSwitch.indicator.width + themeSwitch.spacing
        }
        onCheckedChanged: {

            swipeView.setNegMode(checked);
            bgColor_toolPanels     = !checked?bgColor_toolPanels_light   :bgColor_toolPanels_dark;
            toolBarBtnBg           = !checked?toolBarBtnBg_light         :toolBarBtnBg_dark;
            border_color_outerEdge = !checked?border_color_outerEdge_light:border_color_outerEdge_dark;
            toolbarBtnSect_bg = !checked?toolbarBtnSect_bg_light:toolbarBtnSect_bg_dark;
            toolbarBtnSect_bg_li = !checked?toolbarBtnSect_bg_li_light:toolbarBtnSect_bg_dark;
            fitWidthIcon  = !checked?     fitWidthIcon_light       :        fitWidthIcon_drk     ;
            fitHightIcon  = !checked?     fitHightIcon_light       :        fitHightIcon_drk     ;
            fitSrchIcon   = !checked?     fitSrchIcon_light        :        fitSrchIcon_drk       ;
            highlightColor = !checked? highlightColor_light:highlightColor_dark;
            listPanel_bg  = !checked? listPanel_bg_light:listPanel_bg_dark;
            listPanel_item_bg = !checked? listPanel_item_bg : listPanel_item_bg_dark;
            listPanel_row_bg  = !checked? listPanel_row_bg_light:listPanel_row_bg_dark;
            search_row_bg  = !checked? search_row_bg_light:search_row_bg_dark;
            fontcolor = listPanel_text_color  = !checked? listPanel_text_color_light:listPanel_text_color_dark;
            sidepanel_header_bg  = !checked? sidepanel_header_bg_light:sidepanel_header_bg_dark;
            applicationWindow_bg  = !checked? applicationWindow_bg_light : applicationWindow_bg_dark;
            bookmarkIcon  = !checked? bookmarkIcon_light : bookmarkIcon_dark;


            for(var i = 0; i< pdfSwipeViewModel.count ;i++)
            {
                var pageName = pdfSwipeViewModel.get(i).name;
                pdfSwipeViewModel.set(i, {name:pageName, fit:fitMode, neg:checked, ssid:Date.now(), scle:""});
            }

        }
    }


    Rectangle{
        id: toolbarBtnSect
        anchors.right:  btns_pagefit.left;
        anchors.verticalCenter: parent.verticalCenter;
        anchors.rightMargin: 10;
        width:row_pageInfo.width+10;
        height: row_pageInfo.height+10;
        color: toolbarBtnSect_bg_li;
        z:1

        Row{
            id: row_pageInfo
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10;
            width: 280;
            V1.TextField {
                id: txt_currentPageNumber;
                width: 100;
                validator: IntValidator{bottom: 0; top: pageCnt;}
                inputMethodHints: Qt.ImhDigitsOnly;
                horizontalAlignment: Text.AlignRight;
                anchors.verticalCenter: parent.verticalCenter

                font.family: appFont;
                font.pointSize: 14;
                text: "";
                style:TextFieldStyle{
                    textColor: "black"
                    background: Rectangle {
                        color: "#ffffff"
                        radius: 0
                        border.color: "#00000000"
                        border.width: 1
                    }
                }
                onTextChanged: {
                    if(!acceptableInput)
                    {
                        text = "";
                        return;
                    }
                }
            }
            Text {
                text: qsTr("/");
                anchors.verticalCenter: parent.verticalCenter
                font.family: appFont;
                font.pointSize: 14;
                color: "#666666";
            }
            Text {
                id: txt_TotalPageNumbers;
                text: pageCnt;
                anchors.verticalCenter: parent.verticalCenter
                font.family: appFont;
                font.pointSize: 14;
                color: "#666666";
                width: 100;
            }

            z:2
        }

        Button{
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            text: "Go";

            contentItem: Text{
                text: parent.text;
                font.family: "Avenir Next LT W04 Regular"
                color: "#999999";
                font.letterSpacing: 2
                font.pointSize: 12;
                verticalAlignment: Text.AlignVCenter;
            }

            background:  Rectangle{
                color: "#20ffffff"
                radius: 0
                border.color: "#00000000"
                anchors.fill: parent
            }
            onClicked: {
                var x = txt_currentPageNumber.text;
                if(x !== ""){
                    x = Number(x)
                    swipeView.gotoPage(x);
                }
            }

        }
    }

    Rectangle{
        id:btns_pagefit;
        width:row_Bnts.width+30;
        height: row_Bnts.height+10;
        color: toolbarBtnSect_bg;
        anchors.verticalCenter: parent.verticalCenter;
        anchors.rightMargin: 10;
        anchors.right: parent.right;
        z:1
        Row{
            id:row_Bnts;
            anchors.verticalCenter: parent.verticalCenter;
            anchors.horizontalCenter: parent.horizontalCenter;
            spacing:50;
            Button{
                display: AbstractButton.IconOnly;
                background: Image {
                    source: fitWidthIcon;
                }
                onClicked: {
                    fitMode = 0;
                    swipeView.changeDefaultSize(swipeView.width-(flickmargin*2), swipeView.height, fitMode);
                    for(var i = 0; i< pdfSwipeViewModel.count ;i++)
                    {
                        var pageName = pdfSwipeViewModel.get(i).name;
                        pdfSwipeViewModel.set(i, {name:pageName, fit:0, neg:night, ssid:Date.now(), scle:""});
                    }
                }
            }
            Button{
                display: AbstractButton.IconOnly
                background: Image {
                    source: fitHightIcon;
                }
                onClicked: {
                    fitMode = 1;
                    swipeView.changeDefaultSize(swipeView.width-(flickmargin*2), swipeView.height, fitMode);
                    for(var i = 0; i< pdfSwipeViewModel.count ;i++)
                    {
                        var pageName = pdfSwipeViewModel.get(i).name;
                        pdfSwipeViewModel.set(i, {name:pageName, fit:1 , neg:night, ssid:Date.now(), scle:""});
                    }
                }
            }
        }
    }





    Rectangle
    {
        height: 1;
        anchors.bottom: parent.bottom;
        width: parent.width;
        color: border_color_outerEdge;
        border.width: 0
        z:1
    }

}
