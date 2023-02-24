import QtQuick 2.12

Item {
	implicitWidth: 1100
	implicitHeight: 500
	property real kp_r:0.0
	property real ki_r:0.6
	property real kd_r:0.7
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
//				bottom:item_canvas.bottom
//				bottomMargin: T3Styling.margin_r*3+T3Styling.spacing_r*2
			}
			height: T3Styling.margin_r*2+colu_pidLabel00.height
					+pid_pid.height+text_pidLabel1.height+T3Styling.spacing_r*4
					+rect_seperatorBelowPid.height+text_menu.height
			width:item_canvas.width*0.5
			radius: T3Styling.spacing_r
			color: T3Styling.cBgMain_c
			border.width: T3Styling.lineWidth_r
			border.color: T3Styling.cFgSubSub_c
			Item{
				id:item_leftScreenCanvas
				anchors.fill: parent
				anchors.margins: T3Styling.margin_r
				Column{
					id:colu_pidLabel00
					anchors{
						top:parent.top
						left: parent.left
						right:parent.horizontalCenter
						rightMargin:T3Styling.margin_r/2
					}
					spacing: T3Styling.lineWidth_r
					height: T3Styling.fontSub_r*3+spacing*2
					Repeater{
						model:
							[["P - Propotional Gain",kp_r,T3Styling.cGreen_c]
							,["I - Integral Gain",ki_r,T3Styling.cBlue_c]
							,["D - Derivitive Gain",kd_r,T3Styling.cYellow_c]]
						delegate:
							Rectangle{
							width: colu_pidLabel00.width
							height: T3Styling.fontSub_r
							color: "transparent"
							T3Text{
								anchors.fill: parent
								textAlign_s: "left"
								textColor_c: modelData[2]
								textContent_s: modelData[0].slice(0,1)
							}
							T3Text{
								anchors.fill: parent
								textAlign_s: "left"
								textColor_c: T3Styling.cFgSub_c
								textContent_s:"   "+modelData[0].slice(1)
							}
							T3Text{
								anchors.fill: parent
								textAlign_s: "right"
								textColor_c: modelData[1]===0?T3Styling.cRed_c:T3Styling.cGreen_c
								textContent_s:modelData[1]===0?"OFF":"ON"
							}
						}
					}
				}
				Column{
					id:colu_pidLabel01
					anchors{
						top:parent.top
						left: parent.horizontalCenter
						right:parent.right
						leftMargin:T3Styling.margin_r/2
					}
					spacing: T3Styling.lineWidth_r
					height: T3Styling.fontSub_r*3+spacing*2
					Repeater{
						model:
							[["Propotional Coefficient",kp_r]
							,["Integral Coefficient",ki_r]
							,["Derivitive Coefficient",kd_r]]
						delegate:
							Rectangle{
							width: colu_pidLabel00.width
							height: T3Styling.fontSub_r
							color: "transparent"
							T3Text{
								anchors.fill: parent
								textAlign_s: "left"
								textColor_c: T3Styling.cFgSub_c
								textContent_s:modelData[0]
							}
							T3Text{
								anchors.fill: parent
								textAlign_s: "right"
								textColor_c: modelData[1]===0?T3Styling.cFgSub_c:T3Styling.cFgMain_c
								textContent_s: modelData[1]===0?"N/A":modelData[1]
							}
						}

					}

				}
				T3NCPid{
					id:pid_pid
					anchors{
						top:colu_pidLabel00.bottom
						topMargin: T3Styling.spacing_r*2
						left: parent.left
						right:parent.right
					}
				}
				T3Text{
					id:text_pidLabel1
					anchors{
						top:pid_pid.bottom
						topMargin: T3Styling.spacing_r
						left: parent.left
						right:parent.right
					}
					textColor_c: T3Styling.cFgSub_c
					textContent_s: "R - Setpoint | E - Error | U - Output Power | U - Current Velocity"
				}
				Rectangle{
					id:rect_seperatorBelowPid
					anchors{
						left:parent.left
						right: parent.right
						top:text_pidLabel1.bottom
						topMargin: T3Styling.spacing_r
					}
					height: T3Styling.lineWidth_r
					radius: height
					color: T3Styling.cFgSubSub_c
				}

				T3Text{
					id:text_menu
					anchors{
						top:rect_seperatorBelowPid.bottom
						topMargin: T3Styling.spacing_r
						left: parent.left
						right:parent.right
					}
					textColor_c: T3Styling.cFgMain_c
					textContent_s: "NO OPERATIONS"
				}

//				T3NMCircularGauge{
//				}
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
//		Column{
//			id:colu_coefficient
//			anchors{
//				top:rect_leftScreen.bottom
//				topMargin: T3Styling.spacing_r
//				bottom: parent.bottom
//				left:rect_leftScreen.left
//				right:rect_leftScreen.right
//			}
//			spacing:T3Styling.spacing_r
//			Repeater{
//				model:["F_F_Kp_","F_F_Ki_","F_F_Kd_"]
//				delegate:	T3ParamUnit{
//					anchors{
//						left:parent.left
//						right:parent.right
//					}
//					height: (colu_coefficient.height-colu_coefficient.spacing*2)/3
//					paramConfig_A:modelData
//		//			textonly_b: false
//				}
//			}
//		}


		T3NCDial{
			id:dial_direction
			anchors{
				top:parent.top
				//top:sDis_segDisplay.bottom
				topMargin: T3Styling.spacing_r
				left:rect_leftScreen.right
				leftMargin: T3Styling.spacing_r
			}
			height: (parent.height-T3Styling.spacing_r)/2
			width: height
		}

		T3Text{
			anchors{
				top:parent.top
				left:dial_direction.left
				right: dial_direction.right
			}
			textPixelSize_r: T3Styling.fontSubSub_r
			textContent_s: "Direction"
			textColor_c: T3Styling.cFgSub_c
		}

		T3NCDial{
			id:dial_power
			anchors{
				top:dial_direction.bottom
				topMargin:  -T3Styling.spacing_r
				left:rect_leftScreen.right
				leftMargin: T3Styling.spacing_r
				bottomMargin: T3Styling.spacing_r*1.5
			}
			ticks_nA: [0.64,0.73,0.82,0.911,1]
			height: dial_direction.height
			width: height
		}

		T3Text{
			anchors{
				bottom:parent.bottom
				left:dial_power.left
				right: dial_power.right
			}
			textPixelSize_r: T3Styling.fontSubSub_r
			textContent_s: "Power"
			textColor_c: T3Styling.cFgSub_c
		}

		Rectangle{
			id:rect_rightScreen
			anchors{
				//top:sDis_segDisplay.bottom
				//topMargin: T3Styling.margin_r
				top:parent.top
				left: dial_power.right
				bottom:parent.bottom
			}
			width: T3Styling.fontSubSub_r*3+T3Styling.margin_r*2
			color: T3Styling.cBgMain_c
			border.width: T3Styling.lineWidth_r
			border.color: T3Styling.cFgSubSub_c
			radius: T3Styling.spacing_r
			Item{
				anchors.fill: parent
				anchors.margins: T3Styling.margin_r
				Rectangle{
					id:rect_directionLabel
					anchors{
						top:parent.top
						left:parent.left
						right:parent.right

					}
					color:"transparent"
					height: dial_direction.height*0.7
					T3Text{
						anchors{
							top:parent.top
							left:parent.left
							right:parent.right
						}
						textColor_c:
							dial_direction.currValue_n
							===dial_direction.ticks_nA[0]
							?T3Styling.cFgMain_c: T3Styling.cFgSubSub_c
						Behavior on textColor_c{PropertyAnimation{}}
						textPixelSize_r: T3Styling.fontSubSub_r
						textContent_s: "FWD"
					}
					T3Text{
						anchors{
							top:parent.top
							bottom: parent.bottom
							left:parent.left
							right:parent.right
						}
						textColor_c:
							dial_direction.currValue_n
							===dial_direction.ticks_nA[1]
							?T3Styling.cFgMain_c: T3Styling.cFgSubSub_c
						Behavior on textColor_c{PropertyAnimation{}}
						textPixelSize_r: T3Styling.fontSubSub_r
						textContent_s: "NEU"
					}
					T3Text{
						anchors{

							left:parent.left
							right:parent.right
							bottom: parent.bottom
						}
						textColor_c:
							dial_direction.currValue_n
							===dial_direction.ticks_nA[2]
							?T3Styling.cFgMain_c: T3Styling.cFgSubSub_c
						Behavior on textColor_c{PropertyAnimation{}}
						textPixelSize_r: T3Styling.fontSubSub_r
						textContent_s: "REV"
					}
				}

				Rectangle{
					id:rect_powerLabel
					anchors{
						bottom:parent.bottom
						left:parent.left
						right:parent.right
					}
					color:"transparent"
					height: dial_direction.height*0.8
					Column{
						id:colu_powerLabel
						anchors{
							top:parent.top
							left:parent.left
							right:parent.right
							bottom:parent.bottom
						}
						Repeater{
							model:["P2","P1","N","B1","B2"]
							delegate: 		T3Text{
								anchors{
									left:parent.left
									right:parent.right
								}
								height: colu_powerLabel.height/5
								textColor_c:
									dial_power.currValue_n
									===dial_power.ticks_nA[index]
									?T3Styling.cFgMain_c: T3Styling.cFgSubSub_c
								Behavior on textColor_c{PropertyAnimation{}}
								textPixelSize_r: T3Styling.fontSubSub_r
								textContent_s: modelData
							}
						}
					}
				}
			}
		}


		property int totalRow_n:7
		Grid{
			id:grid_buttons
			anchors{
				top:parent.top
				left:rect_rightScreen.right
				leftMargin: T3Styling.margin_r
				right:parent.right
//				bottom:parent.bottom
			}
			spacing:T3Styling.spacing_r
			rows: 5
			columns:2
			readonly property real unitWidth_r: (width-spacing*(columns-1))/columns
			readonly property real unitHeight_r: (parent.height-spacing*(parent.totalRow_n-1))/parent.totalRow_n
			height: unitHeight_r*rows+spacing*(rows-1)
			Repeater{
				model:["Turn On\nHeaters","Turn Off\nHeaters"
					,"Open\nL Doors","Close\nL Doors"
					,"Open\nR Doors","Close\nR Doors"
					,"Turn On\nExterior Light","Turn Off\nExterior Light"
					,"Turn On\nInterior Light","Turn Off\nInterior Light"
				]
				delegate:			T3Button{
					width: parent.unitWidth_r
					height:parent.unitHeight_r
					buttonLabel_s: modelData.toUpperCase()
					pressedColor_c: index%2==0
									?T3Styling.cFgSub_c
									:T3Styling.cBgMain_c
					releasedColor_c: index%2==0
									 ?T3Styling.cFgMain_c
									 :T3Styling.cFgSubSub_c
					buttonTextColor_c: index%2==0
									   ?T3Styling.cBgMain_c
									   :T3Styling.cFgMain_c
				}
			}
		}

		Grid{
			id:grid_delayButtons
			anchors{
				top:grid_buttons.bottom
				topMargin: T3Styling.spacing_r
				left:rect_rightScreen.right
				leftMargin: T3Styling.margin_r
				right:parent.right
//				bottom:parent.bottom
			}
			spacing:T3Styling.spacing_r
			rows: 3
			columns:1
			readonly property real unitWidth_r: (width-spacing*(columns-1))/columns
			readonly property real unitHeight_r: (parent.height-spacing*(parent.totalRow_n-1))/parent.totalRow_n
			height: unitHeight_r*rows+spacing*(rows-1)
			Repeater{
				model:[
					"TURN OFF / ON\nAIDED TRAIN CONTROL"
					,"ACTIVATE / DEACTIVATE\nEMERGENCY BRAKE"
				]
				delegate:			T3Button{
					width: parent.unitWidth_r
					height:parent.unitHeight_r
					buttonLabel_s: modelData.toUpperCase()
					delayButton_b: true
					pressedColor_c: buttonLabel_s.indexOf("EMERGENCY")!==-1
									?Qt.darker(T3Styling.cRed_c):T3Styling.cBgMain_c
					releasedColor_c: buttonLabel_s.indexOf("EMERGENCY")!==-1
									 ?(T3Styling.cRed_c):T3Styling.cFgSubSub_c
					buttonTextColor_c:T3Styling.cFgMain_c
				}
			}

		}


	}
}
