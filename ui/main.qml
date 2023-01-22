import QtQuick 2.12
import QtQuick.Window 2.12

Window {
	width: 640
	height: 480
	visible: true
	title: qsTr("Hello World")
	Rectangle{
		anchors.fill: parent
		color: T3Styling.cBgMain_c
		T3CircularGauge{
			id:g
			height: parent.height*0.5
			currValue_n: 100
			maxValue_n: 100
		}
		T3CarView{
			anchors.top:g.bottom
		}
		Column{
			id: column
			anchors.fill: parent
			anchors.margins: 10
			Rectangle{
				color: T3Styling.cBgSub_c
				height:15
				width: 100
				Text{
					text: "regular"
					anchors.fill: parent
					font.family: "Inter"
					color: T3Styling.cFgMain_c
				}
			}
			Rectangle{
				color: T3Styling.cRed_c
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "Space Grotesk"
					color: T3Styling.cBgMain_c
				}
			}
			Rectangle{
				color: T3Styling.cYellow_c
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "DSEG14 Classic"
					color: T3Styling.cBgMain_c
				}
			}
			Rectangle{
				color: T3Styling.cBlue_c
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "DSEG14 Classic"
					color: T3Styling.cBgMain_c
				}
			}
			Rectangle{
				color: T3Styling.cGreen_c
				height:15
				width: 100
				Text{
					text: "primary"
					anchors.fill: parent
					font.family: "DSEG14 Classic"
					color: T3Styling.cBgMain_c
				}
			}


		}
	}
}
