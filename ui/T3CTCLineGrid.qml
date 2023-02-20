import QtQuick 2.12
import QtGraphicalEffects 1.12
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.15
Item {
	id:root
	implicitHeight: 300
	implicitWidth: 1000
	property real unitWidth_r:30
	property variant trackConstantsObject_O: null
	property variant trackVariablesObject_O: null
	property int dbIndex_i:-1
	property variant coordinates_A: []
	signal blockClicked(blockId_s:string)
	Rectangle{
		id:rect_canvas
		property real numberOfUnitWidthNeeded_r: Math.max(...coordinates_A.map(it=>it[1][1]))+1
		color: T3Styling.cBgMain_c
		anchors{
			fill:parent
		}
		border.width: T3Styling.lineWidth_r
		border.color: T3Styling.cFgSubSub_c
		radius:T3Styling.margin_r
		clip: true
		SequentialAnimation{
			running: !load_loader.active
			loops: Animation.Infinite
			ColorAnimation{
				target: rect_canvas
				property:"color"
				from: T3Styling.cFgSubSub_c
				to: T3Styling.cRed_c
				duration: 1000
			}
			ColorAnimation{
				target: rect_canvas
				property:"color"
				from: T3Styling.cRed_c
				to: T3Styling.cFgSubSub_c
				duration: 1000
			}
		}
		Loader{
			id:load_loader
			anchors.fill: parent
			sourceComponent: comp_canvas
			active: root.trackConstantsObject_O&&trackVariablesObject_O&&root.coordinates_A.length>0
			//			onLoaded: rect_leftConnectorCanvas.adaptiveMarginCopy_r = item.heightAlias_r*0.05
		}
	}
	Component{
		id:comp_canvas
		Flickable {

			id:gVie_flickable
//			ScrollBar.horizontal: ScrollBar {
//					parent: gVie_flickable.parent
//					anchors.top: gVie_flickable.top
//					anchors.left: gVie_flickable.right
//					anchors.bottom: gVie_flickable.bottom
//				}
			anchors.fill: parent
			anchors{
				topMargin: T3Styling.margin_r
				leftMargin: T3Styling.margin_r
				rightMargin:T3Styling.margin_r
			}

			contentHeight:rect_blockGrid.height
			contentWidth: rect_blockGrid.width
			clip: true

			Rectangle{
				id:rect_blockGrid
				height: gVie_flickable.height
				color: "transparent"
				width: rect_canvas.numberOfUnitWidthNeeded_r*unitWidth_r+rect_leftConnectorCanvas.width+rect_rightConnectorCanvas.width
				Rectangle{
					id:rect_leftConnectorCanvas
					//					x:gVie_flickable.x
					property real adaptiveMarginCopy_r: (rect_blockGrid.height)/2*0.1
					height: rect_leftConnectorCanvas.adaptiveMarginCopy_r*10
					width: rect_leftConnectorCanvas.adaptiveMarginCopy_r*2
					color: "transparent"
					opacity:trackConstantsObject_O["startingBlock2"]===""?0:1
					Rectangle{
						y:height
						width: rect_leftConnectorCanvas.adaptiveMarginCopy_r*1.5
						height:T3Styling.spacing_r
						radius: height
						color: T3Styling.cFgSubSub_c
						antialiasing: true
					}
					Rectangle{
						y:rect_leftConnectorCanvas.height-height*2
						width: rect_leftConnectorCanvas.adaptiveMarginCopy_r*1.5
						height: T3Styling.spacing_r
						radius: height
						//				radius: rect_leftConnectorCanvas.adaptiveMarginCopy_r*0.5
						color: T3Styling.cFgSubSub_c
						antialiasing: true
					}
					Rectangle{
						y:T3Styling.spacing_r
						width: T3Styling.spacing_r
						height: rect_leftConnectorCanvas.height-1.5*T3Styling.spacing_r*1.5
						radius: height
						//				radius: rect_leftConnectorCanvas.adaptiveMarginCopy_r*0.5
						color: T3Styling.cFgSubSub_c
						antialiasing: true
					}
				}
				Rectangle{
					id:rect_rightConnectorCanvas
					x:rect_leftConnectorCanvas.x+rect_leftConnectorCanvas.width+rect_canvas.numberOfUnitWidthNeeded_r*unitWidth_r
					height: rect_leftConnectorCanvas.adaptiveMarginCopy_r*10
					width: rect_leftConnectorCanvas.adaptiveMarginCopy_r*2
					color: "transparent"
					opacity:trackConstantsObject_O["endingBlock2"]===""?0:1
					Rectangle{
						x:rect_rightConnectorCanvas.width-width
						y:height
						width: rect_leftConnectorCanvas.adaptiveMarginCopy_r*1.5
						height:T3Styling.spacing_r
						radius: height
						color: T3Styling.cFgSubSub_c
						antialiasing: true
					}
					Rectangle{
						x:rect_rightConnectorCanvas.width-width
						y:rect_rightConnectorCanvas.height-height*2
						width: rect_leftConnectorCanvas.adaptiveMarginCopy_r*1.5
						height: T3Styling.spacing_r
						radius: height
						//				radius: rect_leftConnectorCanvas.adaptiveMarginCopy_r*0.5
						color: T3Styling.cFgSubSub_c
						antialiasing: true
					}
					Rectangle{
						x:rect_rightConnectorCanvas.width-width
						y:T3Styling.spacing_r
						width: T3Styling.spacing_r
						height: rect_leftConnectorCanvas.height-1.5*T3Styling.spacing_r*1.5
						radius: height
						//				radius: rect_leftConnectorCanvas.adaptiveMarginCopy_r*0.5
						color: T3Styling.cFgSubSub_c
						antialiasing: true
					}
				}

				Repeater{
					model:coordinates_A/*[lineObjIndex_i]*/
					delegate:
						Rectangle{
						width: unitWidth_r*coordinates_A/*[lineObjIndex_i]*/[index][2]
						height: (rect_blockGrid.height)/2
						x:unitWidth_r*coordinates_A/*[lineObjIndex_i]*/[index][1][1]+rect_leftConnectorCanvas.width
						y:coordinates_A[index][1][0]*(height-height*0.1)
						color: "transparent"
						T3CTCRailBlock{
							anchors.fill: parent
							blockId_s:coordinates_A/*[lineObjIndex_i]*/[index][0]
							blockConstantsObject_O:trackConstantsObject_O[blockId_s]
							blockVariablesObject_O: trackVariablesObject_O[blockId_s]
//							ld_b: {
//								let prevBlock2_s = trackConstantsObject_O["blocksMap"][blockId_s]["prevBlock2"];
//								return prevBlock2_s!==""&&prevBlock2_s!=="PASSIVE"
//							}
//							rd_b: {
//								let nextBlock2_s = trackConstantsObject_O["blocksMap"][blockId_s]["nextBlock2"];
//								return nextBlock2_s!==""&&nextBlock2_s!=="PASSIVE"
//							}
//							stationInfo_s: {
//								let station_sA = trackConstantsObject_O["blocksMap"][blockId_s]["station"].split("_")
//								return station_sA.length===2?station_sA[1]:""
//							}
//							crossingInfo_s:{
//								if(trackConstantsObject_O["blocksMap"][blockId_s]["crossing"])
//									return trackVariablesObject_O[blockId_s]["crossingPosition"]
//								else
//									return ""
//							}
//							color_c: {//probably needs change
//								let failure_b = trackVariablesObject_O[blockId_s]["failure"];
//								let authority_b = trackVariablesObject_O[blockId_s]["authority"];
//								if(failure_b)
//									return T3Styling.cRed_c
//								else{
//									if(authority_b)
//										return T3Styling.cGreen_c
//									else
//										return T3Styling.cYellow_c
//								}

//							}
//							isUndg_b: trackConstantsObject_O["blocksMap"][blockId_s]["underground"]
//							fwdInfo_s: {
//								let direction_s = trackConstantsObject_O["blocksMap"][blockId_s]["direction"];
//								if(direction_s==="BIDIRECTIONAL"||direction_s==="FORWARD"){
//									trackVariablesObject_O[blockId_s]["forwardLight"]
//								}else{
//									return ""
//								}
//							}
//							bwdInfo_s: {
//								let direction_s = trackConstantsObject_O["blocksMap"][blockId_s]["direction"];
//								if(direction_s==="BIDIRECTIONAL"||direction_s==="REVERSED"){
//									trackVariablesObject_O[blockId_s]["reversedLight"]
//								}else{
//									return ""
//								}
//							}
//							trainInfo_s: trackVariablesObject_O[blockId_s]["trainOnBlock"]
//							trainMoveForward_b:trackVariablesObject_O[blockId_s]["trainOnBlock"].split("_")[1].includes("F")
							hovered_b: mAre_railBlock.containsMouse
							pressed_b: mAre_railBlock.containsPress
						}
						MouseArea{
							id:mAre_railBlock
							hoverEnabled: true
							anchors.fill: parent
							onClicked: blockClicked(coordinates_A[index][0])
						}
					}


				}
			}
		}
	}


}
