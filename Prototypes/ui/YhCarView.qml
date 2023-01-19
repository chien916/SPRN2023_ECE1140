import QtQuick 2.12

Item {
	id:root
	property bool leftDoorClosed_b: true
	property bool rightDoorClosed_b: false
	property bool brakeReleased_b: true
	property bool brakeEmergency_b: false
	Rectangle{
		anchors{
			fill: parent
		}
		radius: YhStyling.margin_r
		color:YhStyling.cBgSub_c
		Text{
			width: parent.width
			height: parent.height*0.2
			x:parent.x
			y:parent.y+parent.height*0.5-height/2
			text:"Door Status :<font color=\"#ffff00\">Open</font> /
<font color=\"#00ff00\">Closed</font>
<br/>Brake Status :
<font color=\"#ffff00\">Applied</font> /
<font color=\"#00ff00\">Released</font> /
<font color=\"#ff0000\">Emergency</font>"
			font.family: "Inter"
			font.pixelSize: YhStyling.fontSub_r
			fontSizeMode: Text.Fit
			font.letterSpacing: YhStyling.lineWidth_r
			lineHeight: YhStyling.lineWidth_r*0.6
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter
			color: YhStyling.cFgSub_c
		}
		Repeater{
			//number of door sides in this car
			model:[1,2,0,2,1]
			delegate:Rectangle{
				border.width: YhStyling.lineWidth_r
				border.color: YhStyling.cFgSub_c
				color: "transparent"
				height: parent.height*0.2
				width: (parent.width-6*YhStyling.spacing_r)/5
				radius: YhStyling.lineWidth_r
				x: YhStyling.spacing_r+parent.x+(width+YhStyling.spacing_r)*index
				y: parent.y+parent.height*0.25-height*0.5
				Grid{
					id:grid_doorStatusCarView
					rows:2
					visible: modelData>0
					columns: modelData
					rowSpacing:YhStyling.spacing_r
					columnSpacing: YhStyling.spacing_r
					anchors{
						fill: parent
						leftMargin: columnSpacing
						topMargin: rowSpacing
					}
					Repeater{
						model:grid_doorStatusCarView.rows*grid_doorStatusCarView.columns
						Rectangle{
//							border.width: YhStyling.lineWidth_r
//							border.color: YhStyling.cFgSub_c
							color: (index<grid_doorStatusCarView.columns?leftDoorClosed_b:rightDoorClosed_b)?YhStyling.cGreen_c:YhStyling.cYellow_c
							Behavior on color {PropertyAnimation{}}
							width: (grid_doorStatusCarView.width-grid_doorStatusCarView.columnSpacing*(grid_doorStatusCarView.columns))/grid_doorStatusCarView.columns
							height: (grid_doorStatusCarView.height-grid_doorStatusCarView.rowSpacing*(grid_doorStatusCarView.rows))/grid_doorStatusCarView.rows
							radius: YhStyling.lineWidth_r
						}
					}

				}
			}
		}
		Repeater{
			//number of brake sides in this car
			model:[2,0,2,0,2]
			delegate:Rectangle{
				border.width: YhStyling.lineWidth_r
				border.color: YhStyling.cFgSub_c
				color: "transparent"
				height: parent.height*0.2
				width: (parent.width-6*YhStyling.spacing_r)/5
				radius:YhStyling.lineWidth_r
				x: YhStyling.spacing_r+parent.x+(width+YhStyling.spacing_r)*index
				y: parent.y+parent.height*0.75-height*0.5
				Grid{
					id:grid_brakeStatusCarView
					rows:2
					visible: modelData>0
					columns: modelData
					rowSpacing:YhStyling.spacing_r
					columnSpacing: YhStyling.spacing_r
					anchors{
						fill: parent
						leftMargin: columnSpacing
						topMargin: rowSpacing
					}
					Repeater{
						model:grid_brakeStatusCarView.rows*grid_brakeStatusCarView.columns
						Rectangle{
//							border.width: YhStyling.lineWidth_r
//							border.color: YhStyling.cFgSub_c
							color: {
								if(root.brakeEmergency_b)
									return YhStyling.cRed_c;
								else if(brakeReleased_b)
									return YhStyling.cGreen_c;
								else
									return YhStyling.cYellow_c;
							}
							Behavior on color {ColorAnimation{}}
							width: (grid_brakeStatusCarView.width-grid_brakeStatusCarView.columnSpacing*(grid_brakeStatusCarView.columns))/grid_brakeStatusCarView.columns
							height: (grid_brakeStatusCarView.height-grid_brakeStatusCarView.rowSpacing*(grid_brakeStatusCarView.rows))/grid_brakeStatusCarView.rows
							radius: YhStyling.lineWidth_r
						}
					}

				}
			}
		}
	}
	implicitHeight: 500
	implicitWidth: 700
	MouseArea{
		anchors.fill: parent
		onClicked: leftDoorClosed_b =!leftDoorClosed_b
	}
}
