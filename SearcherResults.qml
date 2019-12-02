import QtQuick 2.12
import QtQuick.Controls 2.12

Frame{
    id:searchResultsView
    property alias progress: searchProgress;
    property alias text_input: searchInput;
    anchors.top:parent.top;
    anchors.bottom: parent.bottom;
    width: 340;
    padding: 0;
    state: "closed"
    states: [State {
            name: "open"
            PropertyChanges {
                target: searchResultsView
                x:0;
            }
            PropertyChanges {
                target: handle_textSearch
                x:0;
            }
        },
        State {
            name: "closed"
            PropertyChanges {
                target: searchResultsView
                x:-width;
            }
            PropertyChanges {
                target: handle_textSearch
                x:-width;
            }
        }
    ]
    transitions: Transition {
        from: "closed";
        to: "open";
        reversible: true;
        ParallelAnimation{
            NumberAnimation {
                target: searchResultsView
                property: "x"
                duration: 300
                easing.type: Easing.InOutQuad
            }
            SequentialAnimation{

                PauseAnimation {
                    duration: 100
                }
                NumberAnimation {
                    target: handle_textSearch
                    property: "x"
                    duration: 500
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }


    background: Rectangle{border.width: 0; color: listPanel_bg}

    Rectangle{
        id:handle_textSearch
        border.width: 0;
        height: 45;
        width: parent.width-1;
        y:-1;
        z:10
        TextInput{
            id:searchInput
            font.pointSize: 14
            font.letterSpacing: 2
            font.family: appFont;
            anchors.fill: parent;
            verticalAlignment:TextInput.AlignVCenter;
            horizontalAlignment: TextInput.AlignHCenter;
            property var busy: false;
            onEditingFinished: {
                focus= false;
                handle_textSearch.state="closed";
                if(text!=="" && !busy)
                {
                    busy = true;
                    searchProgress.value = 0;
                    searchResults.clear();
                    gc();
                    searhPDF(text);
                }
            }
        }

    }


    Column{
        id: column
        spacing: 2
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
            onValueChanged: {
                searchInput.busy = !(pageCnt === value);
            }
        }
        ListView{
            id:searchResultsList
            model: searchResults;
            anchors.right: parent.right
            anchors.rightMargin: 1
            anchors.left: parent.left
            anchors.leftMargin: 1
            height: searchResultsView.height-y;
            spacing: 1;
            clip: true;
            delegate:  Item{
                width: parent.width;
                height: 70;
                Rectangle{
                    anchors.fill: parent;
                    color:search_row_bg;
                    opacity: 0.3;
                }
                Column{
                    spacing: 10
                    anchors.fill: parent;
                    anchors.margins: 3;
                    anchors.rightMargin: 6
                    Text {
                        width: parent.width;
                        clip:truncated;
                        text:  result;
                        font.family: appFont;
                        font.pointSize: 12;
                        color: fontcolor;
                        elide: Text.ElideRight
                        wrapMode: Text.WordWrap;
                        maximumLineCount: 2;
                    }
                    Text {
                        width: parent.width;
                        clip:truncated;
                        text:  "pg. " + page;
                        font.family: appFont;
                        font.pointSize: 12;
                        horizontalAlignment: Text.AlignRight;
                        color: fontcolor;
                    }

                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        searchResultsList.currentIndex = index;
                        swipeView.gotoPage(page);
                    }
                }
            }
            highlightFollowsCurrentItem :false;
            highlight:  Rectangle {
                width: parent.width;
                height: 70;
                /*/color:"lightsteelblue"; /*/
                color: highlightColor
                radius: 0
                y: searchResultsList.currentItem.y
                Behavior on y {
                    NumberAnimation {
                        duration: 250
                        easing.type: Easing.InOutQuad;
                    }
                }
            }
        }


    }
    Rectangle{width: 1; color: border_color_outerEdge; height: parent.height; anchors.right: parent.right}
}
