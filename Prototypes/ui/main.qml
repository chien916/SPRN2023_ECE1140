import QtQuick 2.12
import QtQuick.Window 2.12

Window {
	width: 640
	height: 480
	visible: true
	title: qsTr("Hello World")
	Rectangle{
		anchors.fill: parent
		color: YhStyling.c_bgMain
		YhCircularGauge{
			id:g
			height: parent.height*0.5
			currValue_n: 100
			maxValue_n: 100
		}
		YhCarView{
			anchors.top:g.bottom
		}
		Column{
			id: column
			anchors.fill: parent
			anchors.margins: 10
			Rectangle{
				color: YhStyling.c_bgSub
				height:15
				width: 100
				Text{
					text: "regular"
					anchors.fill: parent
					font.family: "Inter"
					color: YhStyling.c_fgMain
				}
			}
			Rectangle{
				color: YhStyling.c_red
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "Space Grotesk"
					color: YhStyling.c_bgMain
				}
			}
			Rectangle{
				color: YhStyling.c_yellow
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "DSEG14 Classic"
					color: YhStyling.c_bgMain
				}
			}
			Rectangle{
				color: YhStyling.c_blue
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "DSEG14 Classic"
					color: YhStyling.c_bgMain
				}
			}
			Rectangle{
				color: YhStyling.c_green
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "DSEG14 Classic"
					color: YhStyling.c_bgMain
				}
			}


		}
	}
}
