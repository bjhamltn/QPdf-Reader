import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls 1.2 as V1
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import QtQuick.Window 2.13

ApplicationWindow
{

    property var appSize : Qt.size(Screen.desktopAvailableWidth,Screen.desktopAvailableHeight);
    onAppSizeChanged: {
        height = mainWindow.screen.desktopAvailableHeight;
        width = mainWindow.screen.desktopAvailableWidth;
    }
    //title: mainWindow.screen.devicePixelRatio;

    color: applicationWindow_bg;

    signal getPdfPageInfo(var idx);
    signal markText(var page);
    signal searhPDF(string term);
    signal enableCropMode(var enabled);
    property var  rotenum: 0
    property var  devicePixelRatio: mainWindow.screen.devicePixelRatio > 1 ? 1 :1;
    property var  devicePixelRatio_img: mainWindow.screen.devicePixelRatio > 1 ? 1 :1;

    property var pdfsourceinfo: sourceinfo;
    property var activeFleet: configuredFleet
    property var busy: false;
    property var fitMode: 0;
    property var scleValue:"";
    property var indx2PageMap: ({});
    property var flickmargin: 0;

    property var leftPanelWidth: 500/devicePixelRatio;
    property var searchPanelWidth: 800/devicePixelRatio;
    property var outlinePanelWidth: 800/devicePixelRatio;
    property var leftPanel_transitionDuration: 500;
    property  var switch_height: 34/devicePixelRatio;
    property  var switch_radius:switch_height/5;

    property var pageBorderWidth: 0;
    property  var translucentOpacity: 0.70;


    property var bntColor: "#a4b1b1";
    property var bntColor_light: "#a4b1b1";
    property var bntColor_dark: "#37483e";

    property var  applicationWindow_bg: applicationWindow_bg_light;
    property var  applicationWindow_bg_light: "#fafafa";
    property var  applicationWindow_bg_dark: "#050505";


    property var listPanel_bg : "#fff";
    property var listPanel_bg_light : "#fff";
    property var listPanel_bg_dark : "#1a1a1a";

    property var listPanel_item_bg : "#f9f9f9";
    property var listPanel_item_bg_light : "#f9f9f9";
    property var listPanel_item_bg_dark : "#00000000";

    property var listPanel_row_bg : "#f9f9f9";
    property var listPanel_row_bg_light : "#f9f9f9";
    property var listPanel_row_bg_dark : "#00000000";


    //property var search_row_bg : "#ccccef";
    //property var search_row_bg_light : "#ccccef";
    //property var search_row_bg_dark : "#1c1c24";
    property var search_row_bg : search_row_bg_light;
    property var search_row_bg_light : "#7fd5f6ff";
    property var search_row_bg_dark : "#7f1a1a1a";

    property var sidepanel_header_bg: "#a9eeff";
    property var sidepanel_header_bg_light: "#a9eeff";
    property var sidepanel_header_bg_dark: "#1a1a1a";

    property var listPanel_text_color : "#333333";
    property var listPanel_text_color_light : "#333333";
    property var listPanel_text_color_dark : "white";

    property  var ui_FontSize: 20/devicePixelRatio;
    property  var ui_FontSize_lrg: 30/devicePixelRatio;
    property  var ui_FontSize_Med: 25/devicePixelRatio;

    property var fontcolor: fontcolor_light;
    property var fontcolor_light: "#000";
    property var fontcolor_drk: "#2ad4ff";

    property var border_color_outerEdge: border_color_outerEdge_light;
    //property var border_color_outerEdge_light: "#2ad4ff"
    property var border_color_outerEdge_light: "#909090";
    property var border_color_outerEdge_dark: "#402ad4ff";

    //property var highlightColor : "#d7eef4";
    property var highlightColor : highlightColor_light;
    property var highlightColor_light: "#7fa2cdf5";
    property var highlightColor_dark : "#7f000000";

    //property var bgColor_toolPanels_light : "#ececec";
    property var bgColor_toolPanels :"#cccccc";
    property var bgColor_toolPanels_light : "#cccccc";
    property var bgColor_toolPanels_dark : "black";

    property var toolBarBtnBg: toolBarBtnBg_light;
    property var toolBarBtnBg_light: "#00ffffff";
    property var toolBarBtnBg_dark: "#00ffffff";
    property var appFont: "Avenir Next Cyr W04 Regular";


    property var selectTool_bg: selectTool_bg_light;
    property var selectTool_bg_light: "#7fffffff";
    property var selectTool_bg_dark: "#20ffffff";


    property var pageNbrTracker:swipeView.currentIndex+1 + swipeView.pageNoOffest;

    property var  toolbarBtnSect_bg: toolbarBtnSect_bg_light;
    property var  toolbarBtnSect_bg_light: "#b3b3b3";
    property var  toolbarBtnSect_bg_dark: "#00b3b3b3";

    property var  toolbarBtnSect_bg_li: toolbarBtnSect_bg_li_light;
    property var  toolbarBtnSect_bg_li_light: "#dde2e2";
    property var  toolbarBtnSect_bg_li_dark: "#00dde2e2";

    property var libIcon: libIcon_light;
    property var libIcon_light: "ic1"
    property var libIcon_drk: "ic1_drk"


    property var bmIcon : bmIcon_light;
    property var bmIcon_light: "ic3"
    property var bmIcon_drk: "ic3_drk"
    property  var bookmark_dwn: "bookmark_dwn"
    property  var bookmark_dwn_light: "bookmark_dwn"
    property  var bookmark_dwn_drk: "bookmark_dwn"


    property var fitWidthIcon: fitWidthIcon_light;
    property var fitWidthIcon_light: "ic4"
    property var fitWidthIcon_drk: "ic4_drk"

    property var fitHightIcon: fitHightIcon_light;
    property var fitHightIcon_light: "ic5"
    property var fitHightIcon_drk: "ic5_drk"



    property var fitSrchIcon: fitSrchIcon_light;
    property var fitSrchIcon_light: "ic6"
    property var fitSrchIcon_drk: "ic6_drk"


    property var bookmarkIcon: bookmarkIcon_light;
    property var bookmarkIcon_light: "bookmark"
    property var bookmarkIcon_dark: "bookmark_drk"


    property var rotateIcon: rotateIcon_light;
    property var rotateIcon_light: "rotate_pg"
    property var rotateIcon_dark: "rotate_pg_drk"
    property var night: themeSwitch.checked;


    function getPageSize(page){
        var h = pdfsourceinfo.filter(function(a,b){return a.name === page ;})[0];
        return  Qt.size(h.width, h.height);
    }
    function getPageInfo(page){
        var pageInfo = pdfsourceinfo.filter(function(a,b){return a.name === page ;})[0];
        return pageInfo;
    }
    function searchFinished()
    {
        searchInput.busy = false;
    }

    function updateSearchResult(result)
    {
        searchProgress.value +=1;
        if(result.hits> 0){
            var data = {"result":result.result, "page":result.page, "hits":result.hits, "worker":result.worker}
            searchResults.append(data);
        }
    }

    onPageNbrTrackerChanged: {
        txt_currentPageNumber.text = pageNbrTracker;
    }

}
