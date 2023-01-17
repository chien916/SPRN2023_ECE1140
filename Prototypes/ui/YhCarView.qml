import QtQuick 2.12

Item {
	id:root
	property bool leftDoorClosed_b: false
	property bool rightDoorClosed_b: true
	property bool brakeReleased_b: true
	Rectangle{
		anchors{
			fill: parent
		}
		radius: YhStyling.i_margin
		color:YhStyling.c_bgSub
		Text{
			width: parent.width
			height: parent.height*0.2
			x:parent.x
			y:parent.y+parent.height*0.5-height/2
			text:"Door Status : <font color=\"#E8D19D\">Open</font> / <font color=\"#C9CDB3\">Closed</font><br/>Brake Status : <font color=\"#E8D19D\">Applied</font> / <font color=\"#C9CDB3\">Released</font>"
			font.family: "Inter"
			font.pixelSize: YhStyling.i_fontSub
			fontSizeMode: Text.Fit
			font.letterSpacing: YhStyling.i_margin*0.03
			lineHeight: YhStyling.i_margin*0.03
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter
			color: YhStyling.c_fgSub
		}
		Repeater{
			//number of door sides in this car
			model:[1,2,0,2,1]
			delegate:Rectangle{
				border.width: YhStyling.i_margin*0.03
				border.color: YhStyling.c_fgSub
				color: "transparent"
				height: parent.height*0.2
				width: (parent.width-6*YhStyling.i_margin*0.5)/5
				radius: YhStyling.i_margin*0.1
				x: YhStyling.i_margin*0.5+parent.x+(width+YhStyling.i_margin*0.5)*index
				y: parent.y+parent.height*0.25-height*0.5
				Grid{
					id:grid_doorStatusCarView
					rows:2
					visible: modelData>0
					columns: modelData
					rowSpacing:parent.height*0.1
					columnSpacing: parent.width*0.1
					anchors{
						fill: parent
						leftMargin: columnSpacing
						topMargin: rowSpacing
					}
					Repeater{
						model:grid_doorStatusCarView.rows*grid_doorStatusCarView.columns
						Rectangle{
							border.width: YhStyling.i_margin*0.03
							border.color: YhStyling.c_fgSub
							color: (index<grid_doorStatusCarView.columns?leftDoorClosed_b:rightDoorClosed_b)?YhStyling.c_green:YhStyling.c_yellow
							Behavior on color {PropertyAnimation{}}
							width: (grid_doorStatusCarView.width-grid_doorStatusCarView.columnSpacing*(grid_doorStatusCarView.columns))/grid_doorStatusCarView.columns
							height: (grid_doorStatusCarView.height-grid_doorStatusCarView.rowSpacing*(grid_doorStatusCarView.rows))/grid_doorStatusCarView.rows
							radius: YhStyling.i_margin*0.1
						}
					}

				}
			}
		}
		Repeater{
			//number of brake sides in this car
			model:[2,0,2,0,2]
			delegate:Rectangle{
				border.width: YhStyling.i_margin*0.03
				border.color: YhStyling.c_fgSub
				color: "transparent"
				height: parent.height*0.2
				width: (parent.width-6*YhStyling.i_margin*0.5)/5
				radius: YhStyling.i_margin*0.1
				x: YhStyling.i_margin*0.5+parent.x+(width+YhStyling.i_margin*0.5)*index
				y: parent.y+parent.height*0.75-height*0.5
				Grid{
					id:grid_brakeStatusCarView
					rows:2
					visible: modelData>0
					columns: modelData
					rowSpacing:parent.height*0.1
					columnSpacing: parent.width*0.1
					anchors{
						fill: parent
						leftMargin: columnSpacing
						topMargin: rowSpacing
					}
					Repeater{
						model:grid_brakeStatusCarView.rows*grid_brakeStatusCarView.columns
						Rectangle{
							border.width: YhStyling.i_margin*0.03
							border.color: YhStyling.c_fgSub
							color: brakeReleased_b?YhStyling.c_green:YhStyling.c_yellow
							Behavior on color {ColorAnimation{}}
							width: (grid_brakeStatusCarView.width-grid_brakeStatusCarView.columnSpacing*(grid_brakeStatusCarView.columns))/grid_brakeStatusCarView.columns
							height: (grid_brakeStatusCarView.height-grid_brakeStatusCarView.rowSpacing*(grid_brakeStatusCarView.rows))/grid_brakeStatusCarView.rows
							radius: YhStyling.i_margin*0.1
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
