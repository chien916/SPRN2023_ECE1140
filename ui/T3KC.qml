import QtQuick 2.12

Item {

	property real plcInputs_r:0xfff3ffff
	property real plcOutputs_r:13
	implicitHeight: 500
	implicitWidth: 500
	Rectangle{
		anchors.fill: parent
		color: T3Styling.cBgSub_c
	}
	Item{
		id:item_canvas
		anchors.fill: parent
		anchors.margins: T3Styling.margin_r
		Rectangle{
			id:rect_leftScreen
			anchors{
				top:parent.top
				//top:sDis_segDisplay.bottom
				//topMargin: T3Styling.margin_r
				left:item_canvas.left
				bottom:item_canvas.bottom
				bottomMargin: T3Styling.margin_r+T3Styling.spacing_r*2
			}
			width:item_canvas.width/**0.7*/
			radius: T3Styling.spacing_r
			color: T3Styling.cBgMain_c
			border.width: T3Styling.lineWidth_r
			border.color: T3Styling.cFgSubSub_c
			Item{
				id:item_leftScreenCanvas
				anchors.fill: parent
				anchors.margins: T3Styling.margin_r
				Grid{
					id:grid_label
					rows:2
					columns:1
					anchors{
						top:parent.top
						left:parent.left
						right:parent.right
					}
					height: T3Styling.fontSub_r*rows+T3Styling.spacing_r*(rows-1)
					Repeater{
						model:["PLC File Path","PLC Status"]
						delegate:Item{
							width: grid_label.width
							height: T3Styling.fontSub_r
							T3Text{
								anchors.fill: parent
								textContent_s: modelData
								textAlign_s: "left"
								textColor_c: T3Styling.cFgSub_c
							}
							T3Text{
								anchors.fill: parent
								textContent_s: modelData
								textAlign_s: "right"
								textColor_c: T3Styling.cFgMain_c
							}
						}
					}
				}

				Rectangle{
					id:rect_seperatorInputLabel
					anchors{
						left:parent.left
						right: parent.right
						top:grid_label.bottom
						topMargin: T3Styling.spacing_r
					}
					height: T3Styling.lineWidth_r
					radius: height
					color: T3Styling.cFgSubSub_c
				}

				Item{
					id:item_inputLabels
					anchors{
						top:rect_seperatorInputLabel.bottom
						topMargin: T3Styling.spacing_r
					}
					width: grid_label.width
					height: T3Styling.fontSub_r
					T3Text{
						anchors.fill: parent
						textContent_s: "PLC Input Binaries"
						textAlign_s: "left"
						textColor_c: T3Styling.cFgSub_c
					}
					T3Text{
						anchors.fill: parent
						textContent_s: "0x"+plcInputs_r.toString(16).padStart(8,"0").toUpperCase()
						textAlign_s: "right"
						textColor_c: T3Styling.cBlue_c
					}
				}

				Grid{
					id:grid_inputBinaries
					rows:2
					columns:16
					anchors{
						top:item_inputLabels.bottom
						topMargin: T3Styling.spacing_r
						left:parent.left
						right:parent.right
					}
					columnSpacing: T3Styling.lineWidth_r
					rowSpacing: columnSpacing
					readonly property real unitWidth_r:
						(width-(columns-1)*columnSpacing)/columns


					Repeater{
						model:parent.columns*parent.rows
						delegate:	Rectangle{
							width: grid_inputBinaries.unitWidth_r
							height: width
							radius: width/4
							color: (plcInputs_r&(1<<(31-index)))!==0?T3Styling.cBlue_c:T3Styling.cFgSubSub_c
							T3Text{
								anchors.fill: parent
								textContent_s: (plcInputs_r&(1<<(31-index)))!==0?"T":"F"
								textColor_c: (plcInputs_r&(1<<(31-index)))!==0?T3Styling.cBgMain_c:T3Styling.cBgMain_c
							}
						}
					}
				}

				Rectangle{
					id:rect_seperatorOutputLabel
					anchors{
						left:parent.left
						right: parent.right
						top:grid_inputBinaries.bottom
						topMargin: T3Styling.spacing_r*2
					}
					height: T3Styling.lineWidth_r
					radius: height
					color: T3Styling.cFgSubSub_c
				}

				Item{
					id:item_outputLabels
					anchors{
						top:rect_seperatorOutputLabel.bottom
						topMargin: T3Styling.spacing_r
					}
					width: grid_label.width
					height: T3Styling.fontSub_r
					T3Text{
						anchors.fill: parent
						textContent_s: "PLC Output Binaries"
						textAlign_s: "left"
						textColor_c: T3Styling.cFgSub_c
					}
					T3Text{
						anchors.fill: parent
						textContent_s: "0x"+plcOutputs_r.toString(16).padStart(8,"0").toUpperCase()
						textAlign_s: "right"
						textColor_c: T3Styling.cGreen_c
					}
				}

				Grid{
					id:grid_outputBinaries
					rows:2
					columns:16
					anchors{
						top:item_outputLabels.bottom
						topMargin: T3Styling.spacing_r
						left:parent.left
						right:parent.right
					}
					columnSpacing: T3Styling.lineWidth_r
					rowSpacing: columnSpacing
					readonly property real unitWidth_r:
						(width-(columns-1)*columnSpacing)/columns
					Repeater{
						model:parent.columns*parent.rows
						delegate:	Rectangle{
							width: grid_inputBinaries.unitWidth_r
							height: width
							radius: width/4
							color: (plcOutputs_r&(1<<(31-index)))!==0?T3Styling.cGreen_c:T3Styling.cFgSubSub_c
							T3Text{
								anchors.fill: parent
								textContent_s: (plcOutputs_r&(1<<(31-index)))!==0?"T":"F"
								textColor_c: (plcOutputs_r&(1<<(31-index)))!==0?T3Styling.cBgMain_c:T3Styling.cBgMain_c
							}
						}
					}
				}
			}
		}
		Grid{
			id:grid_menuButtons
			anchors{
				top:rect_leftScreen.bottom
				topMargin: T3Styling.spacing_r
				bottom: parent.bottom
				left:rect_leftScreen.left
				right:rect_leftScreen.right
			}
			spacing: T3Styling.spacing_r
			rows:1
			columns:3
			Repeater{
				model:["◄","●","■"]
				delegate:T3Button{
					buttonLabel_s: modelData
					width: (grid_menuButtons.width-(grid_menuButtons.spacing*grid_menuButtons.columns-1))
						   /grid_menuButtons.columns
					height: grid_menuButtons.height
				}
			}
		}
	}
}
