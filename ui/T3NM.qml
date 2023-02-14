import QtQuick 2.12

Item {
	id:root
	implicitWidth: 1100
	implicitHeight: 500
	Rectangle{
		id:rect_canvas
		color: T3Styling.cBgSub_c
		anchors.fill: root
	}
	T3SegDisplay{
		id:sDis_segDisplay
		segCharCount_i: 30
		anchors{
			left:root.left
			right:root.right
			top:root.top
			margins: T3Styling.margin_r
		}
		contentsQueue_sA:
			["red  dormont  via penn station"
			,"red  shadyside | waterfront"
			,"          we are hiring     "
			," Pittsburgh Regional Transit"]
		centered_b: false
		shift_b: false
	}
	Rectangle{
		id:rect_leftScreen
		anchors{
			left:root.left
			top:sDis_segDisplay.bottom
			bottom:root.bottom
			margins:T3Styling.margin_r
		}
		width: root.width*0.42
		border.width: T3Styling.lineWidth_r
		border.color: T3Styling.cFgSubSub_c
		radius: T3Styling.spacing_r
		color:T3Styling.cBgMain_c
		T3NMCarView{
			id:cVie_carView
			anchors{
				top:rect_leftScreen.top
				left:rect_leftScreen.left
				right:rect_leftScreen.right
				margins: T3Styling.margin_r
			}
			height: rect_leftScreen.height*0.65-T3Styling.margin_r
		}
		Rectangle{
			id:rect_seperator2
			anchors{
				left:cVie_carView.left
				right: cVie_carView.right
				top:cVie_carView.bottom
				topMargin: T3Styling.spacing_r*3
			}
			height: T3Styling.lineWidth_r
			radius: height
			color: T3Styling.cFgSubSub_c
		}
		T3Text{
			textContent_s:"Join the Church of Scientology"
			textPixelSize_r: T3Styling.fontSubSub_r*1.5
			textColor_c: T3Styling.cFgSubSub_c
//			textBold_b: true
			anchors{
				left:cVie_carView.left
				right: cVie_carView.right
				top:rect_seperator2.bottom
				topMargin: T3Styling.spacing_r*2
				bottom:parent.bottom
				bottomMargin: T3Styling.spacing_r*2
			}
		}

	}
	T3NMSpeedLimitAndSignal{
		anchors{
			top:sDis_segDisplay.bottom
			topMargin: T3Styling.margin_r
			left: rect_leftScreen.right
			leftMargin: T3Styling.spacing_r
			right:rect_rightScreen.left
			rightMargin:T3Styling.spacing_r
			bottom: root.bottom
			bottomMargin: T3Styling.margin_r
		}
	}
	Rectangle{
		id:rect_rightScreen
		anchors{
			right:root.right
			top:sDis_segDisplay.bottom
			bottom:root.bottom
			margins:T3Styling.margin_r
		}
		width: root.width*0.42
		border.width: T3Styling.lineWidth_r
		border.color: T3Styling.cFgSubSub_c
		radius: T3Styling.spacing_r
		color:T3Styling.cBgMain_c
		Rectangle{
			anchors{
				fill:parent
				margins: T3Styling.margin_r}
			color: "transparent"
			T3NMCircularGauge{
				id:cGau_power
				anchors{
					top:parent.top
					left: parent.left
				}
				textOnly_b: false
				toggle_b: false
				width:(parent.width- T3Styling.spacing_r*2)/3
				height: width
			}
			T3Text{
				anchors{
					horizontalCenter: cGau_power.horizontalCenter
					top:cGau_velocity.bottom
				}
				height:T3Styling.fontSub_r
				textPixelSize_r: T3Styling.fontMain_r
				textContent_s: "Power"
				textColor_c: T3Styling.cFgMain_c
			}
			T3NMCircularGauge{
				id:cGau_velocity
				anchors{
					top:parent.top
					left: cGau_power.right
					leftMargin: T3Styling.spacing_r
				}
				textOnly_b: true
				toggle_b: false
				width:(parent.width- T3Styling.spacing_r*2)/3
				height: width
			}
			T3Text{
				anchors{
					horizontalCenter: cGau_velocity.horizontalCenter
					top:cGau_velocity.bottom
				}
				height:T3Styling.fontSub_r

				textPixelSize_r: T3Styling.fontSub_r
				textContent_s: "Velocity"
				textColor_c: T3Styling.cFgMain_c
			}
			T3NMCircularGauge{
				id:cGau_acceleration
				anchors{
					top:parent.top
					left: cGau_velocity.right
					leftMargin: T3Styling.spacing_r
				}
				textOnly_b: false
				toggle_b: false
				width:(parent.width- T3Styling.spacing_r*2)/3
				height: width
			}
			T3Text{
				id:text_acceleration
				anchors{
					horizontalCenter: cGau_acceleration.horizontalCenter
					top:cGau_velocity.bottom
				}
				height:T3Styling.fontSub_r
				textPixelSize_r: T3Styling.fontSub_r
				textContent_s: "Acceleration"
				textColor_c: T3Styling.cFgMain_c
			}
			Rectangle{
				id:rect_seperator1
				anchors{
					left:parent.left
					right: parent.right
					top:text_acceleration.bottom
					topMargin: T3Styling.spacing_r*2
				}
				height: T3Styling.lineWidth_r
				radius: height
				color: T3Styling.cFgSubSub_c
			}
			Column{
				spacing:T3Styling.spacing_r*1
				anchors{
					left:parent.left
					right: cGau_velocity.horizontalCenter
					rightMargin: T3Styling.spacing_r*2
					top:rect_seperator1.bottom
					topMargin: T3Styling.spacing_r*2
					bottom: parent.bottom
				}
				Repeater{
					model:[["Train Length","12 FT"]
						,["Train Height","8 FT"]
						,["Train Width","45 FT"]
						,["Train Mass","240 LBS"]
						,["Cabin Temperature","45 F"]
					]
					delegate:Rectangle{
						height: T3Styling.fontSub_r
						width: parent.width
						color:"transparent"
						T3Text{
							width:parent.width
							height:T3Styling.fontSub_r
							textPixelSize_r: T3Styling.fontSub_r
							textContent_s: modelData[0]
							textColor_c: T3Styling.cFgSub_c
							textAlign_s: "left"
						}
						T3Text{
							width:parent.width
							height:T3Styling.fontSub_r
							textPixelSize_r: T3Styling.fontSub_r
							textContent_s: modelData[1]
							textColor_c: T3Styling.cFgMain_c
							textAlign_s: "right"
						}
					}
				}
			}
			Column{
				spacing:T3Styling.spacing_r*1
				anchors{
					right:parent.right
					left: cGau_velocity.horizontalCenter
					leftMargin: T3Styling.spacing_r*2
					top:rect_seperator1.bottom
					topMargin: T3Styling.spacing_r*2
					bottom: parent.bottom
				}
				Repeater{
					model:[["Exterior Light","ON"]
						,["Interior Light","OFF"]
						,["Engine Status","OK"]
						,["Signal Pickup","ERROR"]
						,["Brake Status","OK"]

					]
					delegate:Rectangle{
						height: T3Styling.fontSub_r
						width: parent.width
						color:"transparent"
						T3Text{
							width:parent.width
							height:T3Styling.fontSub_r
							textPixelSize_r: T3Styling.fontSub_r
							textContent_s: modelData[0]
							textColor_c: T3Styling.cFgSub_c
							textAlign_s: "left"
						}
						T3Text{
							width:parent.width
							height:T3Styling.fontSub_r
							textPixelSize_r: T3Styling.fontSub_r
							textContent_s: modelData[1]
							textColor_c: {
								if(textContent_s==="OK")
									return T3Styling.cGreen_c
								else if(textContent_s==="ERROR")
									return T3Styling.cRed_c
								else if(textContent_s==="ON")
									return T3Styling.cYellow_c
								else if(textContent_s==="OFF")
									return T3Styling.cGreen_c
								else
									return T3Styling.cFgMain_c
							}
							textAlign_s: "right"
						}
					}
				}
			}

		}




	}
}
