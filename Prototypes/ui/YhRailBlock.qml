import QtQuick 2.12

Item {
	id:root
	property bool ld_b: false
	property bool rd_b: true
	property bool sUp_b: false
	property string stationName_s : ""
	property string trainId_s :"1"
	property real trainAtPerc_r: 0.4
	Behavior on trainAtPerc_r{NumberAnimation{}}
	property color color_c:YhStyling.cRed_c
	Behavior on color_c{PropertyAnimation{
			easing.type: Easing.InOutQuad
			duration:  1000}
	}
	Rectangle{
		id:rect_canvas
		height: root.height
		width: root.width
		color: YhStyling.cBgSub_c
		readonly property real h_r: YhStyling.margin_r
		readonly property real ytop_r: 0;
		readonly property real ybottom_r:height-h_r;
		readonly property real ws_r:(width+h_r)*0.5
		readonly property real alpha_r: Math.atan((ybottom_r-ytop_r)/(ws_r-h_r))*180/Math.PI;
		readonly property real wl_r:Math.sqrt(Math.pow(ybottom_r-ytop_r,2)+Math.pow(ws_r-h_r,2))+h_r
		Rectangle{
			id:rect_tlBlock
			width:rect_canvas.ws_r
			height: rect_canvas.h_r
			radius: rect_canvas.h_r
			color: YhStyling.cFgSubSub_c
			x:0
			y:rect_canvas.ytop_r
		}
		Rectangle{
			id:rect_slBlock
			width: rect_canvas.wl_r
			height: rect_canvas.h_r
			radius:rect_canvas.h_r
			color: YhStyling.cFgSubSub_c
			visible:root.ld_b
			x:0
			y:rect_canvas.ybottom_r
			transform: Rotation{
				origin.x:rect_canvas.h_r/2
				origin.y:rect_canvas.h_r/2
				angle: -rect_canvas.alpha_r
			}
		}
		Rectangle{
			id:rect_trBlock
			width: rect_canvas.ws_r
			height:rect_canvas.h_r
			radius: rect_canvas.h_r
			color:  YhStyling.cFgSubSub_c
			x:rect_canvas.ws_r-rect_canvas.h_r
			y:rect_canvas.ytop_r
			z:0
		}
		Rectangle{
			id:rect_srBlock
			//			width:parent.width/2+radius/2\
			width: rect_canvas.wl_r
			height:rect_canvas.h_r
			radius: rect_canvas.h_r
			color: YhStyling.cFgSubSub_c
			visible:root.rd_b
			x:rect_canvas.ws_r-rect_canvas.h_r
			y:rect_canvas.ytop_r
			z:0
			transform: Rotation{
				origin.x:rect_canvas.h_r/2
				origin.y:rect_canvas.h_r/2
				angle: rect_canvas.alpha_r
			}
		}
		Rectangle{
			id:rect_clBlock
			width:(!root.sUp_b&&root.ld_b)?rect_srBlock.width:rect_trBlock.width
			Behavior on width {PropertyAnimation {
					easing.type: Easing.InOutQuad
					duration:  1000
				}}
			height: rect_canvas.h_r
			radius: rect_canvas.h_r
			color: root.color_c
			x:rect_trBlock.x
			y:rect_trBlock.y
			z:2
			transform: Rotation{
				origin.x:rect_canvas.h_r/2
				origin.y:rect_canvas.h_r/2
				angle: ((!sUp_b&&ld_b)?180-rect_canvas.alpha_r:180)
				Behavior on angle {SpringAnimation { spring: 2; damping: 1 }}
			}
		}
		Rectangle{
			id:rect_crBlock
			width:(!root.sUp_b&&root.rd_b)?rect_srBlock.width:rect_trBlock.width
			Behavior on width {PropertyAnimation {
					easing.type: Easing.InOutQuad
					duration:  1000
				}}
			height: rect_canvas.h_r
			radius: rect_canvas.h_r
			color: root.color_c
			x:rect_trBlock.x
			y:rect_trBlock.y
			z:2
			transform: Rotation{
				origin.x:rect_canvas.h_r/2
				origin.y:rect_canvas.h_r/2
				angle: (!sUp_b&&rd_b)?rect_canvas.alpha_r:0
				Behavior on angle {SpringAnimation { spring: 2; damping: 1 }}
			}
		}
		Rectangle{
			id:rect_train
			width: mAre_train.containsMouse?rect_canvas.h_r*3:rect_canvas.h_r
			Behavior on width {PropertyAnimation { easing.type: Easing.InOutQuad }}
			height: rect_canvas.h_r
			radius: rect_canvas.h_r/2
			opacity: root.trainId_s===""?0:1
			Behavior on opacity {PropertyAnimation { easing.type: Easing.InOutQuad }}
			color: mAre_train.containsMouse?YhStyling.cBgSub_c:YhStyling.cBgSub_c
			border.width:YhStyling.lineWidth_r
			border.color:YhStyling.cFgMain_c
			Behavior on color {PropertyAnimation { easing.type: Easing.InOutQuad }}
			x:(rect_canvas.width-rect_canvas.h_r)*root.trainAtPerc_r
			y:{
				if(root.trainAtPerc_r<0.5&&!root.sUp_b&&root.ld_b)
					//H/B=h/b -> h=H/B*b
					return (rect_canvas.ybottom_r-rect_canvas.ytop_r)*(0.5-root.trainAtPerc_r)*2
				else if(root.trainAtPerc_r>0.5&&!root.sUp_b&&root.rd_b)
					return (rect_canvas.ybottom_r-rect_canvas.ytop_r)*(-0.5+root.trainAtPerc_r)*2
				else
					return 0;
			}
			z:2
			MouseArea{
				id:mAre_train
				hoverEnabled: true
				anchors.fill: parent
			}
			Text{
				opacity: mAre_train.containsMouse?1:0
				color: YhStyling.cFgMain_c
				Behavior on opacity {PropertyAnimation { easing.type: Easing.InOutQuad }}
				anchors.fill: parent
				font.family: "Inter"
				font.pixelSize: YhStyling.fontSub_r
				fontSizeMode: Text.Fit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				text:trainId_s
			}
		}
	}
//for testing only
	implicitHeight: 376
	implicitWidth: 500
	MouseArea{
		anchors.fill: parent
		onClicked: {
			if(trainAtPerc_r<=0.9) trainAtPerc_r+=0.1
			else trainAtPerc_r=0
		}
	}
}
