import QtQuick 2.12
import QtQuick.Window 2.12

Window {
	width: 640
	height: 480
	visible: true
	title: qsTr("Hello World")
	Rectangle{
		anchors.fill: parent
		color: YhStyling.cBgMain_c
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
				color: YhStyling.cBgSub_c
				height:15
				width: 100
				Text{
					text: "regular"
					anchors.fill: parent
					font.family: "Inter"
					color: YhStyling.cFgMain_c
				}
			}
			Rectangle{
				color: YhStyling.cRed_c
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "Space Grotesk"
					color: YhStyling.cBgMain_c
				}
			}
			Rectangle{
				color: YhStyling.cYellow_c
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "DSEG14 Classic"
					color: YhStyling.cBgMain_c
				}
			}
			Rectangle{
				color: YhStyling.cBlue_c
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "DSEG14 Classic"
					color: YhStyling.cBgMain_c
				}
			}
			Rectangle{
				color: YhStyling.cGreen_c
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "DSEG14 Classic"
					color: YhStyling.cBgMain_c
				}
			}


		}
	}
}
