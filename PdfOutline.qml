import QtQuick 2.13
import QtQuick.Controls 2.13
Frame{
    id:ll;
    property alias rootParent: ll;
    property var treemodel;
    property var treemodelFlat;
    property var outlineloaded;
    property var rowH: 40/devicePixelRatio
    property var bookMarkcounter: 0;
    property var rowItemsArray: [];
    property var rowItemsMap: ({});

    onTreemodelChanged: {
        rowItemsArray =[];
        rowItemsMap = ({});
        bookMarkcounter = 0;
    }
    Text{
        id:textSize;
        font.pixelSize: ui_FontSize_lrg;
        opacity: 0;
    }
    property var textPadding: textSize.implicitHeight - ui_FontSize_lrg;
    NumberAnimation { id: anim; target: tocListView; property: "contentY"; duration: 500 ; easing.type: Easing.InOutQuad;}
    ListView{
        id:tocListView
        opacity: 1;
        anchors.fill: parent;
        anchors.topMargin: 0/devicePixelRatio;
        anchors.bottomMargin: anchors.topMargin;
        model: treemodelFlat;
        highlightFollowsCurrentItem :false;
        highlight:  Rectangle {
            z:0
            id:highlightdd;
            anchors.left: parent.left;
            anchors.right: parent.right;
            anchors.leftMargin: 0;
            anchors.rightMargin: 0;
            height: tocListView.currentItem.height;
            color: highlightColor;
            radius: 0;
            y: tocListView.currentItem.y
            Behavior on y {
                NumberAnimation {
                    duration: 300;
                    easing.type: Easing.OutExpo;
                }
            }
        }
        delegate:Component{
            Loader{
                id:itemloader;
                property var isExpanded: expanded;
                Timer{id:t_delayInactive;
                    interval: behavior_heightChange.duration+10;
                    repeat: false;
                    running: false;
                    onTriggered: {
                        itemloader.active = false;
                    }
                }
                onIsExpandedChanged: {
                    if(isExpanded)
                    {
                        active=true;
                    }
                    else{
                        height=0;
                        t_delayInactive.start();
                    }
                }
                active:false;
                width:tocListView.width;
                Behavior on height {
                    NumberAnimation {
                        id:behavior_heightChange;
                        duration: 0
                        easing.type: Easing.Linear
                    }
                }
                onActiveChanged:{
                    tocListView.forceLayout();
                    if(active==false){
                        height = 0;
                    }
                }
                sourceComponent:Item{
                    Component.onCompleted: {
                        itemloader.height =  Qt.binding(function()
                        {
                            var h = expanded ? (Math.max(60, sectionText.height) +60): 0;
                            return h;
                        });
                    }

                    id:thisItem;
                    width: parent.width;
                    height: parent.height;
                    clip:true;
                    property var fullHeight : (Math.max(60, sectionText.height) + 60);
                    property var pid: parentid;
                    Item {
                        anchors.fill: parent;
                        Rectangle{
                            id:itemBg;
                            anchors.fill: parent;
                            anchors.margins: 0;
                            color: themeSwitch.checked? "#7f1a1a1a": "#7fd5f6ff";
                        }
                        Item {
                            width: parent.width;
                            clip: true;
                            height: childrenRect.height;
                            anchors.verticalCenter: parent.verticalCenter;
                            Rectangle{

                                id:bb_icon;
                                anchors.right: sectionText.left;
                                anchors.rightMargin: 5;
                                width: 26;
                                height: 46;
                                anchors.top: sectionText.top;
                                anchors.topMargin: textPadding;
                                color: "#00000000";
                                Image{
                                    source: bookmarkIcon;
                                    fillMode: Image.PreserveAspectFit;
                                    anchors.verticalCenter: parent.verticalCenter;
                                    anchors.horizontalCenter: parent.horizontalCenter;
                                }
                            }
                            Text {
                                id:sectionText
                                anchors.right: parent.right;
                                anchors.rightMargin: 100/devicePixelRatio;
                                anchors.left: parent.left;
                                anchors.leftMargin: model.depth * 15 + 121;
                                verticalAlignment: Text.AlignTop;
                                wrapMode: Text.WrapAtWordBoundaryOrAnywhere;
                                anchors.top: parent.top;
                                font.pixelSize: ui_FontSize_lrg;
                                color: fontcolor;
                                text: qsTr(title);
                            }
                            Rectangle
                            {
                                visible: kids > 0;
                                height: 60/devicePixelRatio;
                                width: height;
                                anchors.right: bb_icon.left;
                                anchors.rightMargin: 10;
                                anchors.top: sectionText.top;
                                anchors.topMargin: textPadding;
                                radius: (width/2)/devicePixelRatio;
                                color: themeSwitch.checked? "#4d4d4d" : "#220b28";
                                MouseArea{
                                    anchors.fill: parent;

                                    function branchNode(itemCl,idx,mode)
                                    {
                                        var i = idx+1;
                                        i = Math.min(i, treemodelFlat.rowCount()-1);
                                        var item = treemodelFlat.get(i);
                                        var b = itemCl.expandedkids;
                                        b = !b;
                                        treemodelFlat.setData(idx,b, "261" );
                                        var targetDept = itemCl.depth+1;
                                        while(item.depth > itemCl.depth)
                                        {

                                            if(mode === "collapsed" )
                                            {
                                                treemodelFlat.setData(i,b, "261" );
                                                treemodelFlat.setData(i,b, "260" );
                                            }
                                            else if(targetDept === item.depth)
                                            {
                                                treemodelFlat.setData(i,b, "260" );
                                            }
                                            i+=1;
                                            if(i > treemodelFlat.rowCount()-1)
                                            {
                                                return;
                                            }

                                            item = treemodelFlat.get(i);
                                        }
                                    }

                                    onClicked: {
                                        var s = myBranch.state == "collapsed" ? "expanded" : "collapsed"
                                        myBranch.state = s;
                                        var itemCl = treemodelFlat.get(index);
                                        branchNode(itemCl,index, s);
                                        tocListView.currentIndex = index;
                                        t_rePositionList.start();

                                    }
                                    Timer{
                                        id:t_rePositionList
                                        interval: behavior_heightChange.duration;
                                        running: false;
                                        repeat: false;
                                        onTriggered: {
                                            if("expanded" === myBranch.state)
                                            {
                                                var pos = tocListView.contentY;
                                                var destPos;
                                                tocListView.positionViewAtIndex(tocListView.currentIndex, ListView.Center);
                                                destPos = Math.max(pos, tocListView.contentY);
                                                anim.from = pos;
                                                anim.to = destPos;
                                                anim.start();
                                            }
                                        }
                                    }
                                }
                                Image
                                {
                                    id:myBranch;
                                    anchors.verticalCenter: parent.verticalCenter;
                                    anchors.horizontalCenter:  parent.horizontalCenter;
                                    fillMode: Image.PreserveAspectFit;
                                    source: "bookmark_dwn";
                                    width: sourceSize.width/devicePixelRatio;
                                    state: expandedkids ? "expanded" : "collapsed";
                                    transitions: [
                                        Transition {
                                            from: "collapsed";
                                            to: "expanded";
                                            reversible: true;
                                            NumberAnimation{
                                                target: myBranch
                                                duration: 125;
                                                easing.type:  Easing.InOutQuad;
                                                properties: "rotation"
                                            }
                                        }
                                    ]
                                    states:[State {
                                            name: "expanded"
                                            PropertyChanges {
                                                target: myBranch;
                                                rotation: 90;
                                            }
                                        },
                                        State {
                                            name: "collapsed"
                                            PropertyChanges {
                                                target: myBranch;
                                                rotation: 0;
                                            }
                                        }
                                    ]
                                }
                            }
                        }
                        MouseArea{
                            height: parent.height;
                            anchors.left: parent.left;
                            anchors.leftMargin: sectionText.x;
                            anchors.right: parent.right;
                            hoverEnabled: true;
                            Timer{
                                id:t_gotoPage;
                                interval: 300;
                                running: false;
                                repeat: false;
                                onTriggered: {
                                    var page = model.page;
                                    swipeView.gotoPage(page);
                                }
                            }
                            onClicked: {
                                tocListView.currentIndex = index;
                                t_gotoPage.start();
                            }
                        }
                    }
                }

            }
        }
    }
}
