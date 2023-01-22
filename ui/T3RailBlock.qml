import QtQuick 2.12

Item {
	//--MODIFYABLES:
	//block identifier
	property string blockId_s:"B_R_35"
	//switch information
	property bool ld_b: false
	property bool rd_b: true
	property bool sUp_b: false
	//block direction information
	property string fwdInfo_s:"stop"
	property string bwdInfo_s:"?"
	//infrastructure information
	property string stationInfo_s : ""
	property string crossingInfo_s: "up"
	property bool isUndg_b: true
	//current train on block information
	property string trainInfo_s :"132_0.6"
	//current status of block represented by color information
	property color color_c:T3Styling.cBlue_c

	//--DO NOT MODIFY ANYTHING FROM HERE
	id:root
	Behavior on color_c{PropertyAnimation{
			easing.type: Easing.InOutQuad
			duration:  1000}
	}
	Rectangle{
		id:rect_canvas
		height: root.height
		width: root.width
		color: T3Styling.cBgSub_c
		readonly property real h_r: T3Styling.margin_r
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
			color: T3Styling.cFgSubSub_c
			x:0
			y:rect_canvas.ytop_r
		}

		Rectangle{
			id:rect_slBlock
			width: rect_canvas.wl_r
			height: rect_canvas.h_r
			radius:rect_canvas.h_r
			color: T3Styling.cFgSubSub_c
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
			color:  T3Styling.cFgSubSub_c
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
			color: T3Styling.cFgSubSub_c
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
			color: mAre_train.containsMouse?T3Styling.cBgSub_c:T3Styling.cBgSub_c
			border.width:T3Styling.lineWidth_r
			border.color:T3Styling.cFgMain_c
			Behavior on color {PropertyAnimation { easing.type: Easing.InOutQuad }}
			property real trainAtPerc_r: parseFloat(root.trainInfo_s.split("_")[1])
			x:(rect_canvas.width-rect_canvas.h_r)*trainAtPerc_r
			y:{
				let trainAtPerc_r = parseFloat(root.trainInfo_s.split("_")[1])
				if(trainAtPerc_r<0.5&&!root.sUp_b&&root.ld_b)
					//H/B=h/b -> h=H/B*b
					return (rect_canvas.ybottom_r-rect_canvas.ytop_r)*(0.5-trainAtPerc_r)*2
				else if(trainAtPerc_r>0.5&&!root.sUp_b&&root.rd_b)
					return (rect_canvas.ybottom_r-rect_canvas.ytop_r)*(-0.5+trainAtPerc_r)*2
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
				color: T3Styling.cFgMain_c
				Behavior on opacity {PropertyAnimation { easing.type: Easing.InOutQuad }}
				anchors.fill: parent
				font.family: "Inter"
				font.pixelSize: T3Styling.fontSub_r
				fontSizeMode: Text.Fit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				text:root.trainInfo_s.split("_")[0]
			}
		}

		Rectangle{
			id:rect_underground
			x:rect_canvas.h_r
			y:rect_canvas.h_r+T3Styling.spacing_r
			width: rect_canvas.width-2*x
			height: T3Styling.lineWidth_r
			radius: x
			color:T3Styling.cFgSubSub_c
			opacity: root.isUndg_b?1:0
		}

		Rectangle{
			id:rect_station
			x:rect_canvas.h_r
			width: rect_canvas.width-2*x
			y:rect_underground.y+T3Styling.lineWidth_r*3
			height: rect_canvas.h_r
			radius: T3Styling.lineWidth_r
			color: T3Styling.cFgSubSub_c
			opacity: stationInfo_s===""?0:1
			Text{
				text:stationInfo_s
				color: T3Styling.cBgSub_c
				anchors.fill: parent
				anchors.margins: T3Styling.lineWidth_r
				font.family: "Inter"
				font.pixelSize: T3Styling.fontSub_r
				fontSizeMode: Text.Fit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter

			}

		}

		Rectangle{
			id:rect_arrows
			width: rect_station.width
			height: rect_canvas.h_r*2
			color: "transparent"
			x:rect_station.x
			y:rect_station.y+rect_station.height+T3Styling.lineWidth_r*2
			Item{
				height: rect_arrows.height
				width: height
				Text{
					anchors.fill: parent
					text:(bwdInfo_s!=="")?"←":""
					font.family: "Inter"
					font.pixelSize: T3Styling.fontMain_r
					fontSizeMode: Text.Fit
					horizontalAlignment: Text.AlignLeft
					verticalAlignment: Text.AlignVCenter
					color: {
						if(root.bwdInfo_s==="clear")
							return T3Styling.cGreen_c
						else if(root.bwdInfo_s==="approach")
							return T3Styling.cYellow_c
						else if(root.bwdInfo_s==="stop")
							return T3Styling.cRed_c
						else
							return T3Styling.cFgSubSub_c
					}
					Behavior on color {PropertyAnimation { easing.type: Easing.InOutQuad }}
				}
				rotation: (!root.sUp_b&&root.ld_b)?-rect_canvas.alpha_r:0
				Behavior on rotation {SpringAnimation { spring: 2; damping: 1 }}
			}
			Item{
				height: rect_arrows.height
				width: height
				x:rect_arrows.width-width
				Text{
					anchors.fill: parent
					text:fwdInfo_s!==""?"→":""
					font.family: "Inter"
					font.pixelSize: T3Styling.fontMain_r
					fontSizeMode: Text.Fit
					horizontalAlignment: Text.AlignRight
					verticalAlignment: Text.AlignVCenter
					color: {
						if(root.fwdInfo_s==="clear")
							return T3Styling.cGreen_c
						else if(root.fwdInfo_s==="approach")
							return T3Styling.cYellow_c
						else if(root.fwdInfo_s==="stop")
							return T3Styling.cRed_c
						else
							return T3Styling.cFgSubSub_c
					}
					Behavior on color {PropertyAnimation { easing.type: Easing.InOutQuad }}
				}
				rotation: (!root.sUp_b&&root.rd_b)?rect_canvas.alpha_r:0
				Behavior on rotation {SpringAnimation { spring: 2; damping: 1 }}
			}
			Text{
				id:text_crossing
				anchors.fill: parent
				text:"×"
				font.family: "Inter"
				font.pixelSize: T3Styling.fontMain_r
				fontSizeMode: Text.Fit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				opacity:(root.crossingInfo_s==="down"||root.crossingInfo_s==="up")?1:0
				color: T3Styling.cFgSubSub_c
				Behavior on color {PropertyAnimation { easing.type: Easing.InOutQuad }}
				SequentialAnimation on color{
					running: root.crossingInfo_s==="down"
					alwaysRunToEnd: true
					loops: Animation.Infinite
					PropertyAnimation{
						from: T3Styling.cFgSubSub_c
						to: T3Styling.cRed_c
						duration: 100
					}
					PropertyAnimation{
						from: T3Styling.cRed_c
						to: T3Styling.cFgSubSub_c
						duration: 500
					}
				}

			}
		}

		Rectangle{
			id:rect_blockInfo
			width: text_blockId.paintedWidth
			height: rect_canvas.h_r*2
			color: "transparent"
			radius: T3Styling.lineWidth_r
			border.color: T3Styling.cFgSubSub_c
			border.width: T3Styling.lineWidth_r
			anchors.horizontalCenter: rect_station.horizontalCenter
			y:(rect_canvas.height-height)/2-rect_canvas.h_r
			Text{
				id:text_blockId
				anchors.fill: parent
				anchors.margins: T3Styling.spacing_r
				text:root.blockId_s.split("_").join(" ")
				color: T3Styling.cFgSubSub_c
				font.family: "Inter"
				font.pixelSize: T3Styling.fontMain_r
				fontSizeMode: Text.Fit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
			}
		}

	}

	//--TESTING ONLY
	implicitHeight: 376
	implicitWidth: 500
	MouseArea{
		anchors.fill: parent
		onClicked: {
			//			if(trainAtPerc_r<=0.9) trainAtPerc_r+=0.1
			//			else trainAtPerc_r=0
						sUp_b = !sUp_b
			if(root.crossingInfo_s==="down")root.crossingInfo_s="up"
			else root.crossingInfo_s="down"
		}
	}
}
