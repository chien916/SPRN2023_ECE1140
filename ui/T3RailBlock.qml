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
	property string fwdInfo_s:"clear"
	property string bwdInfo_s:"?"
	//infrastructure information
	property string stationInfo_s : ""
	property string crossingInfo_s: ""
	property bool isUndg_b: true
	//current train on block information
	property string trainInfo_s :"1"
	property bool trainMoveForward_b: true
	//current status of block represented by color information
	property color color_c:T3Styling.cBlue_c
	//for styling only -> dont change!
	readonly property real adaptiveMargin_r :root.height*0.1

	readonly property real adaptiveFontSize_r: root.height*0.1

	readonly property real adaptiveSpacing_r: root.height*0.05

	readonly property real adaptiveLineWidth_r : root.height*0.01

	readonly property real adaptiveElemHeight_r : (rect_canvas.height-13*adaptiveLineWidth_r-adaptiveMargin_r*2)/6

	readonly property real adaptiveElemWidth_r: rect_canvas.width*((ld_b||rd_b)?0.6:1)

	readonly property real adaptiveElemX_r: ld_b?rect_canvas.width-adaptiveElemWidth_r:0
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
		color: "transparent"
		clip:false
		readonly property real h_r: root.adaptiveMargin_r

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
			width: /*mAre_train.containsMouse?rect_canvas.h_r*3:*/rect_canvas.h_r
			Behavior on width {PropertyAnimation { easing.type: Easing.InOutQuad }}
			height: rect_canvas.h_r
			radius: rect_canvas.h_r/2
			visible: trainInfo_s!==""
//			opacity: root.trainId_s===""?0:1
			Behavior on opacity {PropertyAnimation { easing.type: Easing.InOutQuad }}
			color: /*mAre_train.containsMouse?*//*T3Styling.cBgSub_c:*/T3Styling.cBgSub_c
			border.width:root.adaptiveLineWidth_r
			border.color:T3Styling.cFgMain_c
			Behavior on color {PropertyAnimation { easing.type: Easing.InOutQuad }}
			property real trainAtPerc_r: 0.7
			readonly property real animationDuration_r : 3000.0
//			readonly property variant animTimeIntervProp_rA : {
//				let totalTime_r = 3000.0;
//				if((ld_b||rd_b)&&!sUp_b){
//					let shortterInterv_r = totalTime_r*rect_canvas.ws_r/2/(rect_canvas.wl_r+rect_canvas.ws_r/2)
//					let longerInterv_r = totalTime_r - shortterInterv_r;
//					if(rd_b)
//						return [shortterInterv_r/2,longerInterv_r/2];
//					else
//						return [longerInterv_r/2,shortterInterv_r/2];
//				} else
//					[totalTime_r/2,totalTime_r/2];
//			}
			readonly property variant animPosiIntervProp_rA :{
				if(trainMoveForward_b)
					return [0,1/2,1];
				else
					return [1,1/2,0];
			}



			ParallelAnimation{
				running: true
				loops: Animation.Infinite
				alwaysRunToEnd: true
				SequentialAnimation{
					alwaysRunToEnd: true
					PropertyAnimation{
						alwaysRunToEnd: true
						target: rect_train
						property:"opacity"
						from:0
						to:1
						duration:rect_train.animationDuration_r*1/5
					}
					PropertyAnimation{
						alwaysRunToEnd: true
						target: rect_train
						property:"opacity"
						from:1
						to:1
						duration:rect_train.animationDuration_r*3/5
					}
					PropertyAnimation{
						alwaysRunToEnd: true
						target: rect_train
						property:"opacity"
						from:1
						to:0
						duration:rect_train.animationDuration_r*1/5
					}
				}
				SequentialAnimation{
					alwaysRunToEnd: true
					PropertyAnimation{
						alwaysRunToEnd: true
						target: rect_train
						property:"trainAtPerc_r"
						from:rect_train.animPosiIntervProp_rA[0]
						to:rect_train.animPosiIntervProp_rA[1]
						duration: rect_train.animationDuration_r/2
						easing.type:((ld_b||rd_b)&&!sUp_b)?Easing.InOutCubic:Easing.InCubic
					}
					PropertyAnimation{
						alwaysRunToEnd: true
						target: rect_train
						property:"trainAtPerc_r"
						from:rect_train.animPosiIntervProp_rA[1]
						to:rect_train.animPosiIntervProp_rA[2]
						duration: rect_train.animationDuration_r/2
						easing.type:((ld_b||rd_b)&&!sUp_b)?Easing.InOutCubic:Easing.OutCubic
					}
				}

				//				PropertyAnimation{
				//					target: rect_train
				//					property:"trainAtPerc_r"
				//					from:rect_train.animPosiIntervProp_rA[1]
				//					to:rect_train.animPosiIntervProp_rA[2]
				//					duration: rect_train.animTimeIntervProp_rA[0]*2
				//					easing.type:Easing.OutCirc
				//				}

				//				ParallelAnimation{
				//					PropertyAnimation{
				//						target: rect_train
				//						property:"trainAtPerc_r"
				//						from:rect_train.animPosiIntervProp_rA[3]
				//						to:rect_train.animPosiIntervProp_rA[4]
				//						duration: rect_train.animTimeIntervProp_rA[1]
				////						easing.type:Easing.OutQuart
				//					}
				//					PropertyAnimation{
				//						target: rect_train
				//						property:"opacity"
				//						from:1
				//						to:0
				//						duration:rect_train.animTimeIntervProp_rA[1]
				//					}
				//				}

			}

			x:(rect_canvas.width-rect_canvas.h_r)*trainAtPerc_r
			y:{
				//				let trainAtPerc_r = parseFloat(root.trainInfo_s.split("_")[1])
				if(trainAtPerc_r<0.5&&!root.sUp_b&&root.ld_b)
					//H/B=h/b -> h=H/B*b
					return (rect_canvas.ybottom_r-rect_canvas.ytop_r)*(0.5-trainAtPerc_r)*2
				else if(trainAtPerc_r>0.5&&!root.sUp_b&&root.rd_b)
					return (rect_canvas.ybottom_r-rect_canvas.ytop_r)*(-0.5+trainAtPerc_r)*2
				else
					return 0;
			}
			z:2
//			MouseArea{
//				id:mAre_train
//				hoverEnabled: true
//				anchors.fill: parent
//			}
//			Text{
//				opacity: 1
//				color: T3Styling.cFgMain_c
//				Behavior on opacity {PropertyAnimation { easing.type: Easing.InOutQuad }}
//				anchors.fill: parent
//				font.family: "Inter"
//				font.pixelSize: root.adaptiveFontSize_r
//				fontSizeMode: Text.Fit
//				horizontalAlignment: Text.AlignHCenter
//				verticalAlignment: Text.AlignVCenter
//				text:root.trainInfo_s.split("_")[0]
//			}
		}

		Rectangle{
			id:rect_underground
			x:0/*rect_canvas.h_r*/
			y:rect_canvas.h_r+root.adaptiveLineWidth_r
			width: rect_canvas.width/*-2*x*/
			height: root.adaptiveLineWidth_r*3
			//			radius: height
			color:T3Styling.cFgSubSub_c
			opacity: root.isUndg_b?1:0
		}

		Rectangle{
			id:rect_station
			x:0/*rect_canvas.h_r*/
			width: rect_canvas.width/*-2*x*/
			y:rect_underground.y+rect_underground.height+root.adaptiveLineWidth_r
			height: root.adaptiveElemHeight_r
			radius: root.adaptiveLineWidth_r
			color: T3Styling.cFgSubSub_c
			opacity: stationInfo_s===""?0:1
			Text{
				text:stationInfo_s
				color: T3Styling.cBgSub_c
				anchors.fill: parent
				anchors.margins: root.adaptiveLineWidth_r
				font.family: "Inter"
				font.pixelSize: root.adaptiveFontSize_r
				fontSizeMode: Text.Fit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
			}

		}

		Rectangle{
			id:rect_leftArrow
			x:root.adaptiveElemX_r
			y:rect_station.y+rect_station.height+root.adaptiveLineWidth_r
			height:root.adaptiveElemHeight_r
			width: adaptiveElemWidth_r
			color: "transparent"
			Item{
				width: rect_leftArrow.height
				height:rect_leftArrow.height
				anchors.horizontalCenter: rect_leftArrow.horizontalCenter
				Text{
					id:text_leftArrow
					anchors.fill: parent
					text:(bwdInfo_s!=="")?"←":""
					font.family: "Inter"
					font.pixelSize: root.adaptiveFontSize_r*2
					fontSizeMode: Text.Fit
					horizontalAlignment: Text.AlignHCenter
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
		}
		Rectangle{
			id:rect_rightArrow
			x:root.adaptiveElemX_r
			y:rect_leftArrow.y+rect_leftArrow.height+root.adaptiveLineWidth_r
			height: root.adaptiveElemHeight_r
			width: adaptiveElemWidth_r
			color: "transparent"
			Item{
				width: rect_rightArrow.height
				height:rect_rightArrow.height
				anchors.horizontalCenter: rect_rightArrow.horizontalCenter
				Text{
					id:text_rightArrow
					anchors.fill: parent
					text:fwdInfo_s!==""?"→":""
					font.family: "Inter"
					font.pixelSize: root.adaptiveFontSize_r*2
					fontSizeMode: Text.Fit
					horizontalAlignment: Text.AlignHCenter
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
		}

		Rectangle{
			id:rect_crossing
			x:root.adaptiveElemX_r
			y:rect_rightArrow.y+rect_rightArrow.height+root.adaptiveLineWidth_r
			height: root.adaptiveElemHeight_r
			width:adaptiveElemWidth_r
			color: "transparent"
			Item{
				width: rect_crossing.height
				height:rect_crossing.height
				anchors.horizontalCenter: rect_crossing.horizontalCenter
				Text{
					id:text_crossing
					anchors.fill: parent
					text:"×"
					font.family: "Inter"
					font.pixelSize: root.adaptiveFontSize_r*2
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
				//				Text{
				//					id:text_crossing
				//					anchors.fill: parent
				//					text:fwdInfo_s!==""?"→":""
				//					font.family: "Inter"
				//					font.pixelSize: root.adaptiveFontSize_r*2
				//					fontSizeMode: Text.Fit
				//					horizontalAlignment: Text.AlignHCenter
				//					verticalAlignment: Text.AlignVCenter
				//					color: {
				//						if(root.fwdInfo_s==="clear")
				//							return T3Styling.cGreen_c
				//						else if(root.fwdInfo_s==="approach")
				//							return T3Styling.cYellow_c
				//						else if(root.fwdInfo_s==="stop")
				//							return T3Styling.cRed_c
				//						else
				//							return T3Styling.cFgSubSub_c
				//					}
				//					Behavior on color {PropertyAnimation { easing.type: Easing.InOutQuad }}
				//				}
				rotation: (!root.sUp_b&&root.ld_b)?-rect_canvas.alpha_r:0
				Behavior on rotation {SpringAnimation { spring: 2; damping: 1 }}

			}
		}



		Rectangle{

			id:rect_blockInfo
			x:root.adaptiveElemX_r - (ld_b?0: root.adaptiveLineWidth_r*0.5)
			width:adaptiveElemWidth_r + adaptiveLineWidth_r*((ld_b||rd_b)?0.5:1)
			height: root.adaptiveElemHeight_r*2+root.adaptiveLineWidth_r/*rect_station.height*/
			color: "transparent"
			radius: root.adaptiveLineWidth_r
			border.color: T3Styling.cFgSubSub_c
			border.width: root.adaptiveLineWidth_r
			//			anchors.horizontalCenter: rect_station.horizontalCenter
			y:rect_crossing.y+rect_crossing.height+root.adaptiveLineWidth_r
			Text{
				id:text_blockId
				anchors.fill: parent
				text:{
					let splittedBlockId_s = root.blockId_s.split("_");
					return splittedBlockId_s[0]+splittedBlockId_s[1]+"\n"+splittedBlockId_s[2]
				}
				color: T3Styling.cFgSubSub_c
				font.family: "Inter"
				font.pixelSize: root.adaptiveFontSize_r*2
				fontSizeMode: Text.Fit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
			}
		}

		//		Rectangle{
		//			id:rect_seperator
		//			x:0/*rect_canvas.h_r*/
		//			y:rect_blockInfo.y+rect_blockInfo.height+root.adaptiveLineWidth_r
		//			width: rect_canvas.width/*-2*x*/
		//			height: root.adaptiveLineWidth_r
		//			radius: height
		//			color:T3Styling.cFgSubSub_c
		//			opacity: 0.2
		//		}

	}

	//--TESTING ONLY
	implicitHeight: 1000
	implicitWidth: 400
		MouseArea{
			anchors.fill: parent
			onClicked: {
				sUp_b = !sUp_b
				if(root.crossingInfo_s==="down")root.crossingInfo_s="up"
				else root.crossingInfo_s="down"
			}
		}
}
