import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls 1.2 as V1
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

MasterPage
{
    id: mainWindow
    visible: true;
    width: 1200;
    height: 800;
    visibility: ApplicationWindow.Maximized;
    flags:  Qt.Window | Qt.FramelessWindowHint;

    ListModel{id:pdfSrcModel}
    ListModel{id:tocModel}
    ListModel{id:emptymodel}
    ListModel{id:searchResults}

    function refreshPDFView(){
        for(var i = 0; i< pdfSrcModel.count ;i++)
        {
            var pageName = pdfSrcModel.get(i).name;
            pdfSrcModel.set(i, {name:pageName, fit:fitMode, neg:themeSwitch.checked, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
        }
    }

    Drawer{
        id:drawer_top;
        dim:false;
        width: parent.width;
        height: 90/devicePixelRatio;
        dragMargin :90/devicePixelRatio;
        edge: Qt.TopEdge;
        background: Rectangle{
            visible: false;
        }
        ShaderEffectSource {
            id: effectSource_topDrawer;
            sourceItem: workspace;
            height: drawer_top.height+drawer_top.y
            width: parent.width;
            anchors.bottom: parent.bottom;
            sourceRect: Qt.rect(0,0, width, height);
        }
        FastBlur{
            anchors.fill: effectSource_topDrawer;
            source: effectSource_topDrawer;
            radius: 50/devicePixelRatio;
        }
        Frame{
            z:100
            id:toolBar
            anchors.fill: parent;
            padding: 0;
            property var selectedToolFit: bnt_fitWidth;
            background: Rectangle{
                anchors.fill: parent;
                color: bgColor_toolPanels;
                opacity: mainWindow.translucentOpacity;
            }
            Rectangle {
                height: 1/devicePixelRatio;
                color: border_color_outerEdge;
                anchors.bottom: parent.bottom;
                width: parent.width;
            }
            Rectangle {
                z:0
                id:highlightedTool_2;
                anchors.top: parent.top;
                height: parent.height;
                width: toolBar.selectedToolFit.width;
                color: selectTool_bg;
                radius: 0;
                x: toolBar.selectedToolFit.x + rowToolBarBnts.x;
                Behavior on x {
                    NumberAnimation {
                        duration: 250;
                        easing.type:  Easing.InOutQuad;
                    }
                }

            }
            Item {
                anchors.left: parent.left;
                anchors.right: row_pageInfo.left;
                height: parent.height;
                Row{
                    id:rowToolBarBnts;
                    height: parent.height;
                    anchors.horizontalCenter: parent.horizontalCenter;
                    anchors.verticalCenter: parent.verticalCenter;
                    property var iconWidth : height;
                    property var iconWidth_bg : iconWidth*0.6;

                    spacing: iconWidth*0.7;

                    Rectangle{
                        id:themeSwitch_base;
                        width: 140/devicePixelRatio;
                        height: parent.height;
                        anchors.verticalCenter: parent.verticalCenter;
                        color:"#00000000";
                        Switch {
                            anchors.fill: parent;
                            id: themeSwitch;
                            indicator: Rectangle {
                                id:switchGrove
                                implicitWidth: parent.width
                                implicitHeight: ui_FontSize_lrg*1.5;
                                radius: switch_radius;
                                color: "#ada0a0";
                                anchors.horizontalCenter: parent.horizontalCenter;
                                anchors.verticalCenter: parent.verticalCenter;
                                clip: true;
                                Rectangle {
                                    id:numb;
                                    x: 0;
                                    width: switchGrove.implicitHeight;
                                    height: switchGrove.implicitHeight;
                                    radius: switchGrove.radius;
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
                                            duration: 250; easing.type: Easing.InOutQuad;
                                        }
                                    }
                                }
                                Text {
                                    width: switchGrove.width - numb.width;
                                    horizontalAlignment: Text.AlignHCenter;
                                    color: fontcolor;
                                    anchors.verticalCenter: numb.verticalCenter
                                    font.pixelSize:ui_FontSize_Med;
                                    anchors.right: numb.left;
                                    text: "Night" ;
                                }
                                Text {
                                    width: switchGrove.width - numb.width;
                                    horizontalAlignment: Text.AlignHCenter;
                                    color: fontcolor;
                                    anchors.verticalCenter: numb.verticalCenter
                                    anchors.left: numb.right;
                                    font.pixelSize:ui_FontSize_Med;
                                    text:  "Light";
                                }

                            }
                            onCheckedChanged: {
                                swipeView.setNegMode(checked);

                                selectTool_bg = !checked?selectTool_bg_light   :selectTool_bg_dark;
                                bgColor_toolPanels     = !checked?bgColor_toolPanels_light   :bgColor_toolPanels_dark;
                                toolBarBtnBg           = !checked?toolBarBtnBg_light         :toolBarBtnBg_dark;
                                border_color_outerEdge = !checked?border_color_outerEdge_light:border_color_outerEdge_dark;
                                toolbarBtnSect_bg = !checked?toolbarBtnSect_bg_light:toolbarBtnSect_bg_dark;
                                toolbarBtnSect_bg_li = !checked?toolbarBtnSect_bg_li_light:toolbarBtnSect_bg_dark;
                                fitWidthIcon  = !checked?     fitWidthIcon_light       :        fitWidthIcon_drk     ;
                                fitHightIcon  = !checked?     fitHightIcon_light       :        fitHightIcon_drk     ;
                                fitSrchIcon   = !checked?     fitSrchIcon_light        :        fitSrchIcon_drk       ;

                                bmIcon   = !checked?     bmIcon_light        :        bmIcon_drk       ;
                                libIcon   = !checked?     libIcon_light        :        libIcon_drk       ;

                                bntColor = !checked? bntColor_light:bntColor_dark;
                                highlightColor = !checked? highlightColor_light:highlightColor_dark;
                                listPanel_bg  = !checked? listPanel_bg_light:listPanel_bg_dark;
                                listPanel_item_bg = !checked? listPanel_item_bg : listPanel_item_bg_dark;
                                listPanel_row_bg  = !checked? listPanel_row_bg_light:listPanel_row_bg_dark;
                                search_row_bg  = !checked? search_row_bg_light:search_row_bg_dark;
                                fontcolor = listPanel_text_color  = !checked? listPanel_text_color_light:listPanel_text_color_dark;
                                sidepanel_header_bg  = !checked? sidepanel_header_bg_light:sidepanel_header_bg_dark;
                                applicationWindow_bg  = !checked? applicationWindow_bg_light : applicationWindow_bg_dark;
                                bookmarkIcon  = !checked? bookmarkIcon_light : bookmarkIcon_dark;
                                rotateIcon  = !checked? rotateIcon_light : rotateIcon_dark;
                                rectlabelFleets.color =!checked?"#ebf0f5": "#000";

                                for(var i = 0; i< pdfSrcModel.count ;i++)
                                {
                                    var pageName = pdfSrcModel.get(i).name;
                                    pdfSrcModel.set(i, {name:pageName, fit:fitMode, neg:checked, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                                }

                            }
                        }

                    }

                    Rectangle{
                        id:bnt_fitWidth
                        height: parent.height;
                        width:height;
                        color:toolBarBtnBg;
                        Image {
                            fillMode: Image.PreserveAspectFit;
                            anchors.horizontalCenter: parent.horizontalCenter;
                            anchors.verticalCenter: parent.verticalCenter;
                            source: fitWidthIcon;
                            height: rowToolBarBnts.iconWidth_bg
                        }
                        MouseArea{
                            anchors.fill: parent;
                            onClicked: {
                                toolBar.selectedToolFit = bnt_fitWidth;
                                fitMode = 0;
                                scleValue = "";
                                swipeView.changeDefaultSize(swipeView.width-(flickmargin*2), swipeView.height, fitMode);
                                for(var i = 0; i< pdfSrcModel.count ;i++)
                                {
                                    var pageName = pdfSrcModel.get(i).name;
                                    pdfSrcModel.set(i, {name:pageName, fit:0, neg:night, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                                }
                            }
                        }
                    }

                    Rectangle{
                        id:bnt_fitHeight
                        height: parent.height;
                        width:height;
                        color:toolBarBtnBg;
                        Image {
                            fillMode: Image.PreserveAspectFit;
                            anchors.horizontalCenter: parent.horizontalCenter;
                            anchors.verticalCenter: parent.verticalCenter;
                            source: fitHightIcon;
                            height: rowToolBarBnts.iconWidth_bg
                        }
                        MouseArea{
                            anchors.fill: parent;
                            onClicked: {
                                toolBar.selectedToolFit = bnt_fitHeight;
                                fitMode = 1;
                                scleValue = "";
                                swipeView.changeDefaultSize(swipeView.width-(flickmargin*2), swipeView.height, fitMode);
                                for(var i = 0; i< pdfSrcModel.count ;i++)
                                {
                                    var pageName = pdfSrcModel.get(i).name;
                                    pdfSrcModel.set(i, {name:pageName, fit:1 , neg:night, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                                }
                            }
                        }
                    }
                    Rectangle{
                        id:bnt_rotate;
                        height: parent.height;
                        width:height;
                        color:toolBarBtnBg;
                        Behavior on rotation{
                            NumberAnimation{
                                duration: 250;
                                easing.type: Easing.InOutQuad;
                            }
                        }
                        Image {
                            fillMode: Image.PreserveAspectFit;
                            anchors.horizontalCenter: parent.horizontalCenter;
                            anchors.verticalCenter: parent.verticalCenter;
                            source: rotateIcon;
                            height: rowToolBarBnts.iconWidth_bg
                        }
                        MouseArea{
                            anchors.fill: parent;
                            onClicked: {
                                if(rotenum == 3)
                                {
                                    bnt_rotate.rotation = 0;
                                    rotenum = -1;
                                }
                                rotenum++;
                                var a = rotenum * 90
                                bnt_rotate.rotation=a;
                                for(var i = 0; i< pdfSrcModel.count ;i++)
                                {
                                    var pageName = pdfSrcModel.get(i).name;
                                    pdfSrcModel.set(i, {name:pageName, fit:1 , neg:night, ssid:Date.now(), scle:scleValue, angle:a});
                                }

                            }
                        }
                    }

                    Rectangle{
                        id:cropSwitch_base;
                        width: 170/devicePixelRatio;
                        height: parent.height;
                        color:"#00000000";
                        Switch {
                            anchors.fill: parent;
                            id: cropSwitch;
                            indicator: Rectangle {
                                id:cropGrove
                                implicitWidth: parent.width
                                implicitHeight: ui_FontSize_lrg*1.5;
                                radius: switch_radius;
                                color: switchGrove.color;
                                anchors.horizontalCenter: parent.horizontalCenter;
                                anchors.verticalCenter: parent.verticalCenter;
                                clip: true;
                                Rectangle {
                                    id:cropnumb;
                                    x: 0;
                                    width:  cropGrove.implicitHeight;
                                    height: cropGrove.implicitHeight;
                                    radius: cropGrove.radius;
                                    state: cropSwitch.checked? "enabled" : "";
                                    color: numb.color;
                                    border.color:numb.border.color;
                                    states: [
                                        State {
                                            name: "enabled";
                                            PropertyChanges {target: cropnumb;  x:  parent.width - width; }
                                        }
                                    ]
                                    transitions: Transition {
                                        reversible: true;
                                        from: "";
                                        to: "enabled";
                                        NumberAnimation{
                                            properties: "x"
                                            duration: 250; easing.type: Easing.InOutQuad;
                                        }
                                    }
                                }
                                Text {
                                    width: cropGrove.width - cropnumb.width;
                                    horizontalAlignment: Text.AlignHCenter;
                                    color: fontcolor;
                                    anchors.verticalCenter: cropnumb.verticalCenter
                                    font.pixelSize:ui_FontSize_Med;
                                    anchors.right: cropnumb.left;
                                    text: "Cropped" ;
                                }
                                Text {
                                    width: cropGrove.width - cropnumb.width;
                                    horizontalAlignment: Text.AlignHCenter;
                                    color: fontcolor;
                                    anchors.verticalCenter: cropnumb.verticalCenter
                                    font.pixelSize:ui_FontSize_Med;
                                    anchors.left: cropnumb.right;
                                    text:  "Full Size";
                                }
                            }

                            onCheckedChanged: {
                                enableCropMode(checked);
                                for(var i = 0; i< pdfSrcModel.count ;i++)
                                {
                                    var pageName = pdfSrcModel.get(i).name;
                                    pdfSrcModel.set(i, {name:pageName, fit:fitMode, neg:checked, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                                }
                            }

                        }

                    }

                }

            }
            Row{
                id: row_pageInfo;
                anchors.right: parent.right;
                anchors.verticalCenter: parent.verticalCenter;
                spacing: 5/devicePixelRatio;
                V1.TextField {
                    id: txt_currentPageNumber;
                    width: 100/devicePixelRatio;
                    validator: IntValidator{bottom: 0; top: pageCnt;}
                    inputMethodHints: Qt.ImhDigitsOnly;
                    horizontalAlignment: Text.AlignRight;
                    anchors.verticalCenter: parent.verticalCenter;
                    font.family: appFont;
                    font.pixelSize:ui_FontSize_lrg;
                    style:TextFieldStyle{
                        textColor: fontcolor;
                        background: Rectangle {
                            color: themeSwitch.checked? "#7f404040": "#7fddff00"
                            radius: 0;
                            anchors.margins: 0;
                            Rectangle {
                                height: 1/devicePixelRatio;
                                width: parent.width;
                                color: border_color_outerEdge;
                                anchors.bottom: parent.bottom;
                            }
                        }
                    }

                    onEditingFinished: {
                        focus = false;
                        var x = txt_currentPageNumber.text;
                        if(x !== ""){
                            x = Number(x);
                            x = Math.max(1,x);
                            swipeView.gotoPage(x);
                        }
                    }
                    onFocusChanged: {
                        if(focus){
                            selectAll();
                        }
                    }

                    onTextChanged: {
                        if(!acceptableInput)
                        {
                            text = "0";
                            return;
                        }
                    }
                }
                Text {
                    font.bold: true;
                    text: qsTr(":");
                    anchors.verticalCenter: parent.verticalCenter;
                    font.family: appFont;
                    font.pixelSize:ui_FontSize_lrg;
                    color: "#666666";
                    padding: 0;
                }
                V1.TextField {
                    readOnly: true;
                    id: txt_TotalPageNumbers;
                    width: 100/devicePixelRatio;
                    inputMethodHints: Qt.ImhDigitsOnly;
                    horizontalAlignment: Text.AlignLeft;
                    anchors.verticalCenter: parent.verticalCenter;
                    font.family: appFont;
                    font.pixelSize:ui_FontSize_lrg;
                    text: "0";
                    style:TextFieldStyle{
                        textColor: fontcolor;
                        background: Rectangle {
                            color: themeSwitch.checked? "#00404040": "#00ffffff"
                            radius: 0;
                            anchors.margins: 0;
                        }
                    }
                }
            }
        }

    }



    Drawer{
        clip: true;
        id:drawer_left
        dim:false;
        visible: true;
        property var defaultWidth : 90/devicePixelRatio;
        property var selectedPanel:nullPanel;
        property var rightPos: selectedPanel.x+selectedPanel.width
        width: Math.max(selectedPanel.width+90,defaultWidth);
        height: parent.height
        dragMargin: 90;
        edge: Qt.LeftEdge;
        Behavior on width{
            NumberAnimation {
                duration: leftPanel_transitionDuration
                easing.type: Easing.InOutQuad
            }
        }
        background: Rectangle{
            color: "#00000000";
        }
        onClosed: {
            //width=defaultWidth;
        }
        Item {
            width: 0;
            anchors.left: parent.left;
            id: nullPanel;
        }


        Rectangle{
            id: left_toolPane;
            width: 90/devicePixelRatio;
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top;
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            color: bgColor_toolPanels
            z:200;
            property var selectedTool: boundingRect_documentSelector;
            property var iconHeight : width*0.6;
            Item{
                anchors.fill: parent;
                anchors.topMargin: 30/devicePixelRatio;
                Rectangle {
                    z:0
                    id:highlightedTool;
                    anchors.left: parent.left;
                    width: parent.width;
                    height: width;
                    color: selectTool_bg;
                    radius: 0;
                    y: left_toolPane.selectedTool.y;
                    Behavior on y {
                        NumberAnimation {
                            duration: 250;
                            easing.type: Easing.InOutQuad;
                        }
                    }
                }
                Column{
                    id:bnts_layout;
                    anchors.top: parent.top;
                    width: parent.width;
                    spacing: width*0.7;
                    Rectangle{
                        id:boundingRect_documentSelector;
                        width: parent.width;
                        height: width;
                        color:toolBarBtnBg;
                        Image
                        {
                            anchors.horizontalCenter: parent.horizontalCenter;
                            anchors.verticalCenter: parent.verticalCenter;
                            fillMode: Image.PreserveAspectFit;
                            height:left_toolPane.iconHeight;
                            source: libIcon;
                        }
                        MouseArea{
                            anchors.fill: parent;
                            onPressed: {
                                drawer_left.selectedPanel = fleetFolders;
                                outlinePanel.state  = "closed";
                                searchResultsView.state = "closed";
                                //drawer_left.width = fleetFolders.state == "closed"?  drawer_left.defaultWidth+leftPanelWidth : drawer_left.defaultWidth;
                                fleetFolders.state  = fleetFolders.state == "closed"? "" : "closed";
                                left_toolPane.selectedTool = parent.parent;

                            }
                        }
                    }

                    Rectangle{
                        id: boundingRect_outlinePanelButton;
                        width: parent.width;
                        height: width;
                        color: toolBarBtnBg;
                        Image
                        {
                            anchors.horizontalCenter: parent.horizontalCenter;
                            anchors.verticalCenter: parent.verticalCenter;
                            fillMode: Image.PreserveAspectFit;
                            height:left_toolPane.iconHeight;
                            source:bmIcon
                        }
                        MouseArea{
                            anchors.fill: parent;
                            onPressed: {
                                drawer_left.selectedPanel = outlinePanel;
                                fleetFolders.state  = "closed";
                                searchResultsView.state = "closed";
                                //drawer_left.width = outlinePanel.state == "closed"?  drawer_left.defaultWidth+outlinePanelWidth : drawer_left.defaultWidth;
                                outlinePanel.state  = outlinePanel.state == ""? "closed" : "";
                                left_toolPane.selectedTool = boundingRect_outlinePanelButton;
                            }
                        }
                    }

                    Rectangle{
                        id:bounding_rect_searchButton;
                        width: parent.width;
                        height: width;
                        color:toolBarBtnBg;
                        Image
                        {
                            fillMode: Image.PreserveAspectFit;
                            anchors.horizontalCenter: parent.horizontalCenter;
                            anchors.verticalCenter: parent.verticalCenter;
                            height:left_toolPane.iconHeight;
                            source: fitSrchIcon;
                        }
                        MouseArea{
                            anchors.fill: parent;
                            onPressed: {
                                drawer_left.selectedPanel = searchResultsView;
                                left_toolPane.selectedTool = bounding_rect_searchButton;
                                fleetFolders.state = outlinePanel.state = "closed";
                                //drawer_left.width = searchResultsView.state == "closed"?  drawer_left.defaultWidth+searchPanelWidth : drawer_left.defaultWidth;
                                searchResultsView.state = searchResultsView.state == "open" ? "closed" : "open";
                                //if(searchResultsView.state == "open")
                                //{
                                //    swipeView.restoredWidth  = swipeView.currentItem.children[0].children[1].children[0].children[0].children[0].children[0].width;
                                //}
                            }
                        }
                    }
                }
            }
            Rectangle {
                id: left_toolPane_righTBorder
                width: 1/devicePixelRatio;
                color: border_color_outerEdge;
                border.width: 0;
                anchors.bottom: parent.bottom;
                anchors.bottomMargin: 0;
                anchors.top: parent.top;
                anchors.topMargin: 0;
                anchors.right: parent.right;
                anchors.rightMargin: 0;
            }

        }



            ShaderEffectSource {
                id: effectSource_fleetFolders;
                anchors.fill: fleetFolders;
                sourceItem: workspace;
                sourceRect: Qt.rect(x,y, width, height);
            }
            FastBlur{
                anchors.fill: effectSource_fleetFolders;
                source: effectSource_fleetFolders;
                radius: 50;
            }
            Frame{
                id: fleetFolders;
                width: leftPanelWidth;
                clip: true;
                padding: 0;
                leftPadding: 0;
                topPadding: 0;
                anchors.left: left_toolPane.right;
                anchors.leftMargin: drawer_left.defaultWidth;
                anchors.bottom: parent.bottom;
                anchors.bottomMargin: 0;
                anchors.top: parent.top;
                anchors.topMargin: 0;
                background: Rectangle{
                    color: listPanel_bg;
                    opacity: translucentOpacity;
                }

                state:"closed";
                states: [
                    State{
                        name: "closed"
                        PropertyChanges { target: fleetFolders; anchors.leftMargin: -fleetFolders.width -left_toolPane.width }
                        PropertyChanges { target: swipeViewMouseArea; enabled:false; }
                    },
                    State{
                        name: ""
                        PropertyChanges { target: fleetFolders; anchors.leftMargin: 0 }
                        PropertyChanges { target: swipeViewMouseArea; enabled:true; }
                    }
                ]
                transitions: [
                    Transition {
                        to: "closed";
                        from: "";
                        reversible: true;
                        NumberAnimation{ properties: "anchors.leftMargin, opacity" ; duration:leftPanel_transitionDuration ; easing.type: Easing.InOutQuad}
                    }
                ]

                property var selectedFleet;



                Rectangle{
                    id:rectlabels;
                    height: 70/devicePixelRatio;
                    width: parent.width;
                    color: sidepanel_header_bg;
                    state : activeFleet === "" ? "" : "documents";
                    Rectangle{
                        visible: activeFleet === "";
                        id:rectlabelFleets;
                        width: parent.width;
                        height: parent.height;
                        y:0;
                        x:0;
                        color: "#ebf0f5"
                        Text {
                            id: labelFleets;
                            font.pixelSize:ui_FontSize_lrg;
                            text: qsTr("Fleets")
                            anchors.right: parent.right;
                            anchors.rightMargin: 0.5*labelFleets.width;
                            anchors.bottom:parent.bottom;
                            anchors.bottomMargin:10/devicePixelRatio;
                            font.family: appFont;
                            color: fontcolor;
                        }
                        MouseArea{
                            anchors.fill: parent;
                            onClicked: {
                                rectlabels.state= filesPanels.state = pane_documentSelector.state = "";
                            }
                        }
                    }
                    Rectangle{
                        id:rectlabelDocuments;
                        width:parent.width;
                        height: parent.height;
                        anchors.left: rectlabelFleets.right;
                        anchors.leftMargin: 25/devicePixelRatio
                        color: "#00000000";
                        y:0;
                        Text {
                            id: labelDocuments;
                            font.pixelSize:ui_FontSize_lrg;
                            text: activeFleet === "" ?  fleetFolders.selectedFleet+": Documents" : activeFleet +":" + " Documents";
                            anchors.left: parent.left;
                            anchors.rightMargin: 10/devicePixelRatio;
                            anchors.bottom:parent.bottom;
                            anchors.bottomMargin:10/devicePixelRatio;
                            font.family: appFont;
                            color: fontcolor;
                        }
                    }
                    Rectangle{
                        height: 1/devicePixelRatio;
                        color: border_color_outerEdge;
                        width: parent.width;
                        anchors.bottom: parent.bottom
                    }
                    states: State {
                        name: "documents";
                        PropertyChanges { target: labelFleets; anchors.bottomMargin: 10/devicePixelRatio}
                        PropertyChanges { target: rectlabelFleets; x: -rectlabelFleets.width + 1.5*labelFleets.width +labelFleets.anchors.rightMargin }
                        //PropertyChanges { target: rectlabelDocuments; x: 0; }
                    }
                    transitions: [
                        Transition {
                            to: "documents";
                            reversible: true;
                            ParallelAnimation{
                                NumberAnimation{properties: "x, anchors.bottomMargin, scale"; duration:250; easing.type: Easing.InOutQuad}
                                ColorAnimation{target: labelFleets; duration:250; easing.type: Easing.InOutQuad}
                            }
                        }
                    ]
                }


                Frame {
                    visible: activeFleet === "";
                    id: pane_documentSelector
                    anchors.fill: parent
                    anchors.topMargin: rectlabels.height;
                    padding: 0;
                    background: Rectangle{
                        visible: false;
                    }

                    LocationList{
                        id: listView_fleets;
                        listModel: docLibModel;
                        listType: "fleets";
                        itemHeight:120/devicePixelRatio;
                        function gotoDetails(citem){
                            listView1.listModel = citem.documents;
                            fleetFolders.selectedFleet = citem.fleet;
                            filesPanels.state = filesPanels.state == 'onscreen_files' ?  "" : 'onscreen_files';
                            pane_documentSelector.state = pane_documentSelector.state == 'offscreen' ?  "" :  'offscreen';
                            rectlabels.state = "documents";
                        }
                    }
                    states:State {
                        name: "offscreen";
                        PropertyChanges { target: pane_documentSelector; anchors.leftMargin: -pane_documentSelector.width }
                        PropertyChanges { target: listView_fleets; opacity: 0.1 }
                    }

                    transitions: Transition {
                        from: ""; to: "offscreen"; reversible: true
                        NumberAnimation { properties: "anchors.leftMargin, opacity"; duration: leftPanel_transitionDuration; easing.type: Easing.InOutQuad }
                    }
                }
                Frame {
                    id: filesPanels;
                    x: width;
                    anchors.bottom: parent.bottom;
                    anchors.top: parent.top;
                    width: parent.width;
                    anchors.topMargin: rectlabels.height;
                    padding: 0;
                    state: activeFleet !== "" ? "onscreen_files" : "";
                    background: Rectangle{
                        visible: false;
                    }

                    LocationList{
                        id: listView1;
                        listType: "docs"
                        property var docItem;
                        listModel: configuredFleetDocs;
                        itemHeight:120/devicePixelRatio;
                        Timer{
                            id:time_loadPdf;
                            interval: 200;
                            repeat: false;
                            running: false;
                            onTriggered: {
                                swipeView.loadPdf(listView1.docItem.filePath);
                            }
                        }
                        function gotoDetails(citem){
                            docItem = citem;
                            swipeView.visible = false;
                            time_loadPdf.start();
                        }
                    }
                    states:State {
                        name: "onscreen_files";
                        PropertyChanges { target: filesPanels;x: 0 }
                    }
                    transitions: Transition {
                        from: ""; to: "onscreen_files"; reversible: true
                        NumberAnimation { properties: "x"; duration: leftPanel_transitionDuration; easing.type: Easing.InOutQuad }
                    }
                }

                Rectangle{
                    color: "#00000000";
                    anchors.fill: parent;
                    Rectangle{
                        anchors.right: parent.right;
                        anchors.top: parent.top;
                        height: parent.height;
                        color: border_color_outerEdge;
                        width: 1/devicePixelRatio;
                    }

                }

            }


            ShaderEffectSource {
                id: effectSource;
                sourceItem: workspace;
                anchors.fill: outlinePanel;
                sourceRect: Qt.rect(x,y, width, height);
            }
            FastBlur{
                id: blur;
                anchors.fill: effectSource;
                source: effectSource;
                radius: 50/devicePixelRatio;
            }
            PdfOutline{
                id:outlinePanel;
                outlineloaded:false;
                treemodelFlat: pdfoutline_flat;
                padding: 0;
                clip: true;
                width:  outlinePanelWidth;
                anchors.left: left_toolPane.right;
                anchors.top: left_toolPane.top;
                anchors.bottom: parent.bottom;
                background: Rectangle{
                    color: listPanel_bg;
                    opacity: translucentOpacity;
                    Rectangle{
                        anchors.right: parent.right;
                        anchors.top: parent.top;
                        height: parent.height;
                        color: border_color_outerEdge;
                        width: 1/devicePixelRatio;
                    }
                }
                state:"closed";
                states: [
                    State{
                        name: "closed"
                        PropertyChanges { target: outlinePanel; anchors.leftMargin: -outlinePanel.width -left_toolPane.width }
                        PropertyChanges { target: swipeViewMouseArea; enabled:false; }
                    },
                    State{
                        name: ""
                        PropertyChanges { target: outlinePanel; anchors.leftMargin: 0 }
                        PropertyChanges { target: swipeViewMouseArea; enabled:true; }
                    }
                ]
                transitions: [
                    Transition {
                        to: "closed";
                        from: "";
                        reversible: true;
                        NumberAnimation{ properties: "anchors.leftMargin, opacity" ; duration:leftPanel_transitionDuration ; easing.type: Easing.InOutQuad}
                    }
                ]
            }

            ShaderEffectSource {
                id: effectSource_search;
                sourceItem: workspace;
                anchors.fill: searchResultsView;
                sourceRect: Qt.rect(x,y, width, height);
            }
            FastBlur{
                anchors.fill: effectSource_search;
                source: effectSource_search;
                radius: 50/devicePixelRatio;
            }
            Frame{
                id:searchResultsView
                anchors.top:parent.top;
                anchors.left: left_toolPane.right;
                anchors.bottom: parent.bottom ;
                width:  searchPanelWidth ;
                padding: 0;
                z:100;
                state: "closed"
                states: [State {
                        name: "open"
                        PropertyChanges {
                            target: searchResultsView
                            anchors.leftMargin: 0;
                        }
                        PropertyChanges {
                            target: handle_textSearch
                            x:0;
                        }
                        PropertyChanges { target: swipeViewMouseArea; enabled:true; }
                    },
                    State {
                        name: "closed"
                        PropertyChanges {
                            target: searchResultsView
                            anchors.leftMargin: -searchResultsView.width;
                        }
                        PropertyChanges { target: swipeViewMouseArea; enabled:false; }
                    }
                ]
                transitions: Transition {
                    from: "closed";
                    to: "open";
                    reversible: true;
                    ParallelAnimation{
                        NumberAnimation {
                            target: searchResultsView
                            property: "anchors.leftMargin"
                            duration: leftPanel_transitionDuration;
                            easing.type: Easing.InOutQuad
                        }
                    }
                }

                background: Rectangle{border.width: 0; color: listPanel_bg; opacity:translucentOpacity }

                Rectangle{
                    id:handle_textSearch
                    border.width: 0;
                    height: 70/devicePixelRatio;
                    width: searchResultsView.width;
                    y:-1/devicePixelRatio;
                    z:10;
                    clip:true;
                    color: themeSwitch.checked? "#404040" : "#7fddff00";
                    Item {
                        anchors.fill: parent;
                        anchors.rightMargin: bnt_clearResults.width+bnt_clearResults.anchors.rightMargin;

                        V1.TextField{
                            id:searchInput;
                            font.pixelSize:ui_FontSize_Med;
                            font.family: appFont;
                            anchors.fill: parent;
                            anchors.rightMargin: 0;
                            verticalAlignment:TextInput.AlignVCenter;
                            horizontalAlignment: TextInput.AlignHCenter;
                            property var busy: false;
                            style:TextFieldStyle{
                                textColor: fontcolor;
                                background: Rectangle {
                                    color: "#00000000"
                                    radius: 0;
                                    border.color: "#00000000";
                                    border.width: 1/devicePixelRatio;
                                }
                            }

                            onAccepted: {
                                focus = false;
                                handle_textSearch.state="closed";
                                if(text!=="" && !busy)
                                {
                                    searchInput.busy = true;
                                    searchProgress.value = 0;
                                    searchResults.clear();
                                    gc();
                                    searhPDF(text);
                                }
                            }
                        }
                        Label{
                            id:searchPlaceholderText;
                            text: "Touch Here to Search";
                            font.pixelSize:ui_FontSize_Med;
                            opacity: 1;
                            color : fontcolor;
                            anchors.horizontalCenter: parent.horizontalCenter;
                            anchors.verticalCenter: parent.verticalCenter;
                            state: (searchInput.focus || searchInput.text!="") ? "unfocused" : "focused";
                            states: [
                                State {
                                    name: "focused"
                                    PropertyChanges {
                                        target:  searchPlaceholderText;
                                        opacity:1;
                                    }
                                },
                                State {
                                    name: "unfocused"
                                    PropertyChanges {
                                        target:  searchPlaceholderText;
                                        opacity:0;
                                    }
                                }
                            ]
                            transitions:
                                Transition {
                                from: "focused"
                                to: "unfocused"
                                reversible: true;
                                PropertyAnimation{
                                    target: searchPlaceholderText;
                                    properties: "opacity"
                                    duration: 250;
                                    easing.type: Easing.InOutQuad;
                                }
                            }

                        }
                    }

                    Button{
                        id:bnt_clearResults;
                        text: searchInput.busy ? "Stop" : "Clear";
                        font.pixelSize: ui_FontSize_Med;
                        anchors.right: parent.right;
                        anchors.rightMargin: (searchInput.busy |  searchResults.count > 0) ?  0 : -width;
                        height: parent.height;
                        width: parent.width/7;
                        Behavior on anchors.rightMargin{

                            NumberAnimation {
                                duration: 200
                                easing.type: Easing.OutExpo
                            }
                        }

                        onClicked: {
                            if(searchInput.busy)
                            {
                                appController.cancelSearch();
                                searchInput.busy = false;
                            }
                            else
                            {
                                appController.clearSearchTerm();
                                searchProgress.value=0;
                                searchResults.clear();
                                searchInput.text="";
                                refreshPDFView();
                            }

                        }
                        Rectangle{
                            color: border_color_outerEdge;
                            anchors.left: parent.left;
                            height: parent.height;
                            width: 1;
                        }

                    }

                    Rectangle{
                        height: 1/devicePixelRatio;
                        width: parent.width;
                        anchors.bottom: parent.bottom;
                        color: border_color_outerEdge;
                    }
                }


                Column{
                    id: column
                    spacing:0
                    width: parent.width;
                    anchors.bottom: parent.bottom;
                    anchors.top: handle_textSearch.bottom;
                    anchors.topMargin: 0;
                    ProgressBar{
                        id:searchProgress
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        value:0;
                        from:0;
                        to:pageCnt;
                        background: Rectangle {
                               color: "#e6e6e6"
                               radius: 0
                           }

                           contentItem: Item {
                               implicitHeight: 6
                               Rectangle {
                                   width: searchProgress.visualPosition * parent.width
                                   height: parent.height
                                   radius: 0
                                   color: themeSwitch.checked ? "yellow" : "blue"
                               }
                           }
                    }
                    ListView{
                        id:searchResultsList
                        model: searchResults;
                        anchors.right: parent.right
                        anchors.rightMargin: 1/devicePixelRatio
                        anchors.left: parent.left
                        anchors.leftMargin: 1/devicePixelRatio
                        height:searchResultsView.height-searchProgress.height - handle_textSearch.height -1;
                        spacing: 1/devicePixelRatio;
                        clip: true;
                        property var searchResultsList_itemHeight : 100/devicePixelRatio
                        delegate:  Item{
                            width: parent.width;
                            height: searchResultsList.searchResultsList_itemHeight+60;
                            Rectangle{
                                anchors.fill: parent;
                                color:search_row_bg;
                                opacity: 0.3;
                            }
                            Item {
                                width: parent.width;
                                height: searchResultsList.searchResultsList_itemHeight;
                                anchors.verticalCenter: parent.verticalCenter;
                                Column{
                                    spacing: 10/devicePixelRatio
                                    anchors.fill: parent;
                                    anchors.margins: 3/devicePixelRatio;
                                    anchors.rightMargin: 6/devicePixelRatio
                                    Text {
                                        width: parent.width;
                                        clip:truncated;
                                        text:  result;
                                        font.pixelSize:ui_FontSize_Med;
                                        color: fontcolor;
                                        elide: Text.ElideRight
                                        wrapMode: Text.WordWrap;
                                        maximumLineCount: 2;
                                    }
                                    Text {
                                        width: parent.width;
                                        clip:truncated;
                                        text:  "pg. " + page;
                                        font.pixelSize:ui_FontSize;
                                        horizontalAlignment: Text.AlignRight;
                                        color: fontcolor;
                                    }

                                }
                                MouseArea{
                                    anchors.fill: parent;
                                    Timer{
                                        id:t_loadPage;
                                        repeat: false;
                                        running: false;
                                        interval: 300
                                        onTriggered: {
                                            swipeView.gotoPage(page);
                                        }
                                    }

                                    onClicked: {
                                        searchResultsList.currentIndex = index;
                                        t_loadPage.start();
                                    }
                                }
                            }
                        }
                        highlightFollowsCurrentItem :false;
                        highlight:  Rectangle {
                            width: searchResultsList.width;
                            height: searchResultsList.currentItem.height;
                            color: highlightColor
                            radius: 0
                            y: searchResultsList.currentItem.y
                            Behavior on y {
                                NumberAnimation {
                                    duration: 300
                                    easing.type: Easing.OutExpo;
                                }
                            }
                        }
                    }
                }

                Rectangle{width: 1/devicePixelRatio; color: border_color_outerEdge; height: parent.height; anchors.right: parent.right; z:10}

            }

    }



    PDFViewer{
        id:workspace
        anchors.fill: parent;
        SwipeView
        {
            id: swipeView
            objectName: "swipeView";
            clip: true;
            anchors.fill: parent;
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            signal pdfChanged(string msg,var width, var height, var fit_mode);
            signal changeDefaultSize(var width, var height, var fit_mode);
            signal setNegMode(var isNegative);
            property var pageNoOffest: 0;
            property var lastindex: 0;
            property var pageLoaderActive: true;
            property var  restoredWidth: 0;
            Timer{
                id:sizeChangedTimer;
                interval: 510;
                repeat: false;
                running: false;
                onTriggered: {
                    swipeView.windowResized();
                }
            }
            onWidthChanged: {
                var temp_width  = 0;
                var resized_scale = 0;
                var wT = swipeView.currentItem.children[0].children[1].children[0].children[0].children[0].children[0].width;
                if(searchResultsView.state == "open"){
                    if(wT  > swipeView.width)
                    {
                        changeDefaultSize(width-(flickmargin*2), height, fitMode);
                        temp_width  = swipeView.currentItem.children[0].children[1].children[0].children[0].children[0].children[0].width;
                        resized_scale = (swipeView.width - (flickmargin*2)) / temp_width;

                        if(!sizeChangedTimer.running){
                            sizeChangedTimer.start();
                        }

                        swipeView.currentItem.children[0].children[1].children[0].children[0].children[0].children[0].height *= resized_scale;
                        swipeView.currentItem.children[0].children[1].children[0].children[0].children[0].children[0].width = swipeView.width - (flickmargin*2);

                        if(swipeView.currentIndex>0){
                            swipeView.itemAt(swipeView.currentIndex -1).children[0].children[1].children[0].children[0].children[0].children[0].height *= resized_scale;
                            swipeView.itemAt(swipeView.currentIndex -1).children[0].children[1].children[0].children[0].children[0].children[0].width = swipeView.width - (flickmargin*2);
                        }
                        if(swipeView.itemAt(swipeView.lastindex > swipeView.currentIndex) !== null )
                        {
                            swipeView.itemAt(swipeView.currentIndex +1).children[0].children[1].children[0].children[0].children[0].children[0].height *= resized_scale;
                            swipeView.itemAt(swipeView.currentIndex +1).children[0].children[1].children[0].children[0].children[0].children[0].width = swipeView.width - (flickmargin*2);
                        }
                    }
                }
                else{
                    if(swipeView.width <= swipeView.restoredWidth)
                    {
                        var newWidth = Math.min(swipeView.restoredWidth, swipeView.width - (flickmargin*2));
                        changeDefaultSize(newWidth, height, fitMode);
                        temp_width  = swipeView.currentItem.children[0].children[1].children[0].children[0].children[0].children[0].width;
                        resized_scale = newWidth / temp_width;

                        if(!sizeChangedTimer.running){
                            sizeChangedTimer.start();
                        }

                        swipeView.currentItem.children[0].children[1].children[0].children[0].children[0].children[0].height *= resized_scale;
                        swipeView.currentItem.children[0].children[1].children[0].children[0].children[0].children[0].width =  newWidth;
                        if(swipeView.currentIndex>0){
                            swipeView.itemAt(swipeView.currentIndex -1).children[0].children[1].children[0].children[0].children[0].children[0].height *= resized_scale;
                            swipeView.itemAt(swipeView.currentIndex -1).children[0].children[1].children[0].children[0].children[0].children[0].width = newWidth;
                        }
                        if(swipeView.itemAt(swipeView.lastindex > swipeView.currentIndex) !== null )
                        {
                            swipeView.itemAt(swipeView.currentIndex +1).children[0].children[1].children[0].children[0].children[0].children[0].height *= resized_scale;
                            swipeView.itemAt(swipeView.currentIndex +1).children[0].children[1].children[0].children[0].children[0].children[0].width = newWidth;
                        }

                    }
                }

            }
            onHeightChanged: {
                changeDefaultSize(width-(flickmargin*2), height, fitMode)
                if(!sizeChangedTimer.running){
                    sizeChangedTimer.start();
                }
            }
            function gotoPage(page){
                var fp =findPage(page-1);
                if(fp>-1)
                {
                    swipeView.setCurrentIndex(fp);
                    return;
                }

                var pagetoDisplay = page -1;
                var slots_needed = 3;
                var slots_available = currentIndex+1;
                var slots_2insert = Math.max(0, slots_needed - slots_available);
                var slots_2set = Math.max(0, slots_needed - slots_2insert);
                slots_2set = Math.min(slots_2set,slots_available);

                /*/
                first set the available slots.
                page - 1 is the zero based index of requested page
                /*/
                page = page - 1;
                var no_pages_to_add = false;
                var i=0
                var last_pageIdx;
                for(i = 0; i< slots_2set ; i++)
                {

                    var idx = currentIndex - i;
                    if(idx < 0  || page<0)
                    {
                        no_pages_to_add = true;
                        break;
                    }
                    pdfSrcModel.set(idx,{name:  page, fit:fitMode,neg:night, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                    last_pageIdx = idx;
                    page--;
                }


                //next insert the the new slots
                for( i = 0; i < slots_2insert;i++){

                    if(page > 0)
                    {
                        pdfSrcModel.insert(0,{name:  page, fit:fitMode,neg:night, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                        page--;
                    }
                    else{
                        no_pages_to_add = true;
                        break;
                    }
                }


                //the above was for the lower pages of the swipeView
                //now the upper pages have to be set or added
                var no_pages_to_add_up = false
                var modelIdx = findPage(pagetoDisplay)+1;
                var slots_needed_up = 3;
                var slots_available_up = pdfSrcModel.count - modelIdx +1;
                var slots_insert_up = Math.max(0, slots_needed_up - slots_available_up);
                var slots_set_up = slots_needed_up - slots_insert_up;
                slots_set_up = Math.min(slots_set_up,slots_available_up)

                //Just as was done for the down pages we first set the slots available
                page = pagetoDisplay+1;
                var last_pageIdx_up
                for(i=0;i<slots_set_up; i++)
                {
                    if(page < pageCnt)
                    {
                        pdfSrcModel.set(modelIdx,{name: page, fit:fitMode,neg:night, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                        last_pageIdx_up = modelIdx;
                        page++;
                        modelIdx++;
                    }
                    else
                    {
                        no_pages_to_add_up = true;
                        break
                    }
                }


                for(i=0;i< slots_insert_up; i++)
                {
                    if(page < pageCnt)
                    {
                        pdfSrcModel.append({name:  page, fit:fitMode, neg:night, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                        page++;
                    }
                    else
                    {
                        no_pages_to_add_up = true;
                        break
                    }
                }

                if(pagetoDisplay === pageCnt-1)
                {
                    last_pageIdx_up = findPage(pagetoDisplay);
                    while(pdfSrcModel.count > last_pageIdx_up+1 )
                    {

                        pdfSrcModel.remove(pdfSrcModel.count-1);
                    }
                }
                else if(slots_insert_up === 0)
                {
                    var amtRm =0;
                    last_pageIdx_up = findPage(pagetoDisplay)+slots_needed_up+1;
                    var idxLastPageAdded = findPage(page-1);
                    while(pdfSrcModel.count > idxLastPageAdded+1 )
                    {

                        pdfSrcModel.remove(pdfSrcModel.count-1);
                    }
                }
                if(pagetoDisplay === 0)
                {
                    last_pageIdx = findPage(pagetoDisplay);
                    pdfSrcModel.remove(0,last_pageIdx);
                }
                else if(slots_2insert===0)
                {
                    last_pageIdx = findPage(pagetoDisplay)-slots_2set;
                    if(last_pageIdx<0){
                        last_pageIdx = slots_2set - findPage(pagetoDisplay);
                    }
                    else{
                        last_pageIdx = last_pageIdx+1;
                    }

                    if(last_pageIdx > 0){
                        pdfSrcModel.remove(0,last_pageIdx);
                    }
                }


                modelIdx = findPage(pagetoDisplay);
                pageNoOffest = pagetoDisplay - modelIdx;
                lastindex = modelIdx;
                gc();

            }
            function findPage(page){
                for(var i=0;i< pdfSrcModel.count;i++)
                {
                    if(page === pdfSrcModel.get(i).name)
                    {
                        return i;
                    }
                }
                return -1;
            }
            function loadPdf(filePath){
                searchResults.clear();
                searchProgress.value = 0;
                searchInput.busy = false;
                searchInput.text = "";
                pageNoOffest =0;
                indx2PageMap = {};
                busy = true;
                lastindex = 0;
                rotenum= 0;
                bnt_rotate.rotation = 0;
                mRepeater.model = emptymodel;
                pdfSrcModel.clear();
                gc();
                swipeView.currentIndex = 0;
                pdfChanged(filePath,swipeView.width-(flickmargin*2), swipeView.height, fitMode)
                txt_TotalPageNumbers.text = pageCnt;
                for(var i=0; i< Math.min(3,pageCnt); i++)
                {
                    pdfSrcModel.append({name:i, fit:fitMode, neg:night, ssid:Date.now(), scle:scleValue, angle:0});
                }
                mRepeater.model = pdfSrcModel;

                busy =false;
                outlinePanel.outlineloaded = true;
            }
            function updateSwipModel(){
                var pagetoDisplay = pdfSrcModel.get(currentIndex).name;
                if(currentIndex>lastindex)
                {

                    var pagesToAdd = Math.min(3, pageCnt - pdfSrcModel.get( pdfSrcModel.count-1).name);
                    var finalCnt = pdfSrcModel.count + pagesToAdd;
                    while( pdfSrcModel.count <  finalCnt  )
                    {
                        var pageNumber = pdfSrcModel.get(pdfSrcModel.count-1).name+1;
                        if(pageNumber < pageCnt)
                        {
                            pdfSrcModel.append({"name":  pageNumber, fit:fitMode, neg:night, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                        }
                        else{
                            break;
                        }
                    }
                }
                else
                {
                    var nextBackPage =  pdfSrcModel.get(0).name - 1;
                    if(findPage(nextBackPage)<0  &&  nextBackPage >-1)
                    {
                        pdfSrcModel.insert(0,{"name":nextBackPage, fit:fitMode,neg:night, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                        pageNoOffest--;
                        return;
                    }
                }
                lastindex = currentIndex;
            }
            function windowResized(){
                for(var i = 0; i< pdfSrcModel.count ;i++)
                {
                    var pageName = pdfSrcModel.get(i).name;
                    pdfSrcModel.set(i, {name:pageName, fit:fitMode, neg:night, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                }
            }
            Connections{
                target: swipeView.contentItem
                onMovementEnded:{
                    swipeView.updateSwipModel();
                }
            }
            Repeater{
                id: mRepeater
                objectName:"mRepeater"
                anchors.fill: parent
                Loader
                {
                    asynchronous: true
                    id:pageLoader;
                    active: (SwipeView.isCurrentItem || SwipeView.isNextItem || SwipeView.isPreviousItem) && swipeView.pageLoaderActive;
                    sourceComponent:Item
                    {
                        id: element
                        anchors.fill: parent
                        anchors.margins: 0
                        width: swipeView.width;
                        height: swipeView.height;
                        Rectangle
                        {
                            id:swipeViewBg
                            color: "#00000000"
                            border.color: "#e6e6e6"
                            border.width: 0
                            x:flickmargin
                            y:-1
                            width: swipeView.width - (flickmargin*2);
                            height: swipeView.height+2;
                        }
                        Flickable
                        {
                            id:scrVw;
                            clip: true;
                            boundsBehavior : Flickable.StopAtBounds;
                            width: swipeView.width - (flickmargin*2);
                            height: swipeView.height;
                            x:(swipeView.width - width )/2;
                            contentHeight: pageArt.height;
                            contentWidth: pageArt.width;
                            onWidthChanged:
                            {
                                if(pageArt.width > scrVw.width)
                                {
                                    pageLayer.x = 0;
                                    scrVw.contentX = (pageArt.width - scrVw.width)/2;
                                }
                                else{
                                    pageLayer.x= scrVw.width/2 - pageLayer.width/2;
                                }
                            }
                            Frame{
                                id:pageLayer
                                width: pageArt.width
                                height: pageArt.height
                                x:(swipeView.width - (flickmargin*2)) - width/2
                                padding: 0;
                                background: Rectangle{
                                    border.width: 0;
                                    color: "#00000000";
                                    border.color: border_color_outerEdge;
                                }

                                onWidthChanged:
                                {
                                    var widthMax = swipeView.width - (flickmargin*2);
                                    if(pageArt.width > widthMax)
                                    {
                                        scrVw.width = swipeView.width - (flickmargin*2);
                                        pageLayer.x = 0;
                                        scrVw.contentX = (pageArt.width - scrVw.width)/2;
                                    }
                                    else{
                                        scrVw.width = pageArt.width;
                                        pageLayer.x= scrVw.width/2 - pageLayer.width/2;
                                    }
                                }
                                onHeightChanged:
                                {
                                    if(pageArt.height > scrVw.height)
                                    {
                                        pageLayer.y = 0;
                                        scrVw.contentY = 0;
                                    }
                                    else{
                                        pageLayer.y= scrVw.height/2 - pageLayer.height/2;
                                    }
                                }


                                Image {
                                    id:pageArt
                                    cache: true;
                                    fillMode: Image.PreserveAspectFit;
                                    transformOrigin: Image.Center;
                                    objectName: "pdfpage/"+name;
                                    property var isInView: swipeView.currentIndex == index;
                                    onIsInViewChanged: {
                                        var pdfInfo =  appController.getPageInfo(name);
                                        links.model = pdfInfo.links
                                    }

                                    property var requestedSize: { "width": 0, "height": 0 }
                                    source: "image://pdfpage/"+name+"?neg="+neg+"&fitmode="+fit+"&scale="+scle+"&ssid="+ssid+"&angle="+angle;
                                    onSourceSizeChanged: {
                                        var pdfInfo =  appController.getPageInfo(name);
                                        links.model = pdfInfo.links
                                        var w_hidpi =  sourceSize.width/devicePixelRatio_img;
                                        var h_hidpi =  sourceSize.height/devicePixelRatio_img;
                                        if(sourceSize.width>0)
                                        {
                                            width =  w_hidpi;
                                            height = h_hidpi;
                                        }
                                        if(true)
                                        {
                                            var widthMax = swipeView.width - (flickmargin*2);
                                            if(w_hidpi > widthMax)
                                            {
                                                scrVw.width = swipeView.width - (flickmargin*2);
                                                pageLayer.x = 0;
                                                scrVw.contentX = (w_hidpi - scrVw.width)/2;
                                            }
                                            else{
                                                scrVw.width = w_hidpi;
                                                pageLayer.x= scrVw.width/2 - pageLayer.width/2;
                                            }

                                            if(h_hidpi > scrVw.height)
                                            {
                                                pageLayer.y = 0;
                                                scrVw.contentY = 0;
                                            }
                                            else{
                                                pageLayer.y= scrVw.height/2 - pageLayer.height/2;
                                            }
                                        }

                                    }

                                    Rectangle {
                                        visible: false
                                        id: dummy
                                    }
                                    Component.onCompleted:{
                                        indx2PageMap[index] = pageArt;
                                        if(pageArt.width > scrVw.width)
                                        {
                                            pageLayer.x = 0;
                                            scrVw.contentX = (pageArt.width - scrVw.width)/2;
                                        }
                                        else{
                                            pageLayer.x= scrVw.width/2 - pageLayer.width/2;
                                        }
                                    }
                                    PinchArea{
                                        id: pincher
                                        anchors.fill: parent
                                        pinch.target: dummy
                                        pinch.maximumScale: 10
                                        pinch.minimumScale: 792 /pageArt.sourceSize.height
                                        pinch.dragAxis: Pinch.NoDrag
                                        onPinchUpdated: {
                                            pageArt.width = dummy.scale * pageArt.sourceSize.width
                                            pageArt.height = dummy.scale * pageArt.sourceSize.height
                                            if(pageArt.width > scrVw.width)
                                            {
                                                pageLayer.x = 0;
                                                scrVw.contentX = (pageArt.width - scrVw.width)/2;
                                            }
                                            else{
                                                pageLayer.x= scrVw.width/2 - width/2;
                                            }
                                        }

                                        onPinchFinished: {
                                            var pageName = pdfSrcModel.get(index).name;
                                            var size = getPageSize(pageName);
                                            var pageInfo = getPageInfo(pageName);
                                            var scale = dummy.scale;
                                            dummy.scale = 1;
                                            pageArt.requestedSize.width  = scale * pageArt.sourceSize.width;
                                            pageArt.requestedSize.height = scale * pageArt.sourceSize.height;
                                            pincher.pinch.minimumScale = 792 /pageArt.requestedSize.height;
                                            if(rotenum == 1 || rotenum == 3)
                                            {
                                                if(fitMode == 0){
                                                    scale = pageArt.requestedSize.width/size.height;

                                                }
                                                else{
                                                    scale = pageArt.requestedSize.height/size.width;
                                                }
                                            }
                                            else{
                                                if(fitMode == 0){
                                                    scale = pageArt.requestedSize.width/size.width;
                                                }
                                                else{
                                                    scale = pageArt.requestedSize.height/size.height;
                                                }
                                            }

                                            scleValue = scale+"";
                                            pdfSrcModel.set(index, {name:pageName, fit: fitMode , neg:night, ssid:Date.now(), scle:scleValue, angle:bnt_rotate.rotation});
                                            for(var i=0; i<pdfSrcModel.count;i++)
                                            {
                                                pdfSrcModel.get(i).scle = scleValue;
                                            }
                                        }
                                    }
                                }
                                Repeater{
                                    id:links;
                                    Rectangle{
                                        height: model.modelData.pos.height;
                                        width: model.modelData.pos.width;
                                        x:model.modelData.pos.x
                                        y:model.modelData.pos.y
                                        color:"#00000000"
                                        Rectangle{
                                            height: 1;
                                            color: "red"
                                            width: parent.width;
                                            anchors.bottom: parent.bottom;
                                        }

                                        MouseArea{
                                            anchors.fill: parent;
                                            onClicked: {
                                                swipeView.gotoPage(model.modelData.page);
                                            }
                                        }
                                    }
                                }

                                Rectangle{
                                    border.width: pageBorderWidth;
                                    anchors.margins: 1;
                                    color: "#00000000"
                                    anchors.fill: parent;
                                    border.color: border_color_outerEdge;
                                }

                            }
                        }
                    }
                    onLoaded: {
                        if(!swipeView.visible){
                            swipeView.visible = true;
                        }
                    }
                }
            }
        }


        MouseArea{
            id:swipeViewMouseArea
            Timer{
                id:closePanelsTimer;
                interval: 100;
                repeat: false;
                running: false;
                onTriggered: {
                    searchResultsView.state = fleetFolders.state = outlinePanel.state  ="closed";
                    drawer_left.selectedPanel = nullPanel;
                }
            }

            anchors.left: swipeView.left;
            anchors.leftMargin:  -40;
            anchors.top:  swipeView.top;
            anchors.right: parent.right;
            anchors.bottom: parent.bottom;
            enabled: false;
            hoverEnabled: true;
            onMouseXChanged: {
                if(containsMouse){
                    closePanelsTimer.start();
                }
            }

        }

        Row{
            id:navBnts;
            anchors.bottom: parent.bottom;
            anchors.right: parent.right;
            anchors.bottomMargin: 40/devicePixelRatio;
            anchors.rightMargin: 40/devicePixelRatio;
            spacing: 20/devicePixelRatio;
            property var image_width:   70/devicePixelRatio;
            property var image_height:  53/devicePixelRatio;
            opacity: 0.8
            Button{
                width: navBnts.image_width;
                height:navBnts.image_height;
                background:Image {
                    source: "ppage";
                    fillMode: Image.PreserveAspectFit;
                    width: sourceSize.width/devicePixelRatio_img
                    anchors.fill: parent;
                }
                onClicked: {
                    swipeView.decrementCurrentIndex();
                    swipeView.updateSwipModel();
                }
            }
            Button{
                width: navBnts.image_width;
                height:navBnts.image_height;
                background:Image {
                    source: "npage";
                    fillMode: Image.PreserveAspectFit;
                    width: sourceSize.width/devicePixelRatio_img
                }
                onClicked: {
                    swipeView.incrementCurrentIndex();
                    swipeView.updateSwipModel();
                }
            }
        }
    }




}
