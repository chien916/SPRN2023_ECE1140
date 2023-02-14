import QtQuick 2.12
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
Item {
	id:root
	property string gaugeUnit_s: "mph"
	property int maxValue_n: 100
	property int minValue_n: 0
	property int currValue_n: 50
	property bool textOnly_b: false
	property bool toggle_b: true
	implicitHeight: 150
	implicitWidth: 500
	Rectangle{
		id:rectangle_container
		color: T3Styling.cBgMain_c
//		radius: T3Styling.margin_r
		anchors{
			horizontalCenter: parent.horizontalCenter
			verticalCenter: parent.verticalCenter
			fill: parent
		}
		Item{
			id:item_ratioKeeper
			anchors{
				horizontalCenter: parent.horizontalCenter
				verticalCenter: parent.verticalCenter
			}
			width: Math.min(parent.width,parent.height)
			height: width
			CircularGauge{
				anchors.fill: parent
				anchors.margins: parent.height*0.01
				style: CircularGaugeStyle {
						needle: Rectangle {
							y: outerRadius * 0.2
							implicitWidth: outerRadius * 0.05
							implicitHeight: outerRadius * 0.9
							antialiasing: true
							color: T3Styling.cFgMain_c
							radius: outerRadius * 0.05
							opacity: textOnly_b?0:1
							Behavior on opacity {NumberAnimation{easing.type: Easing.InOutCubic}}
						}
						foreground: Rectangle {
								width: outerRadius * 0.2
								height: width
								radius: width / 2
								color: T3Styling.cFgMain_c
								anchors.centerIn: parent
								opacity: textOnly_b?0:1
								Behavior on opacity {NumberAnimation{easing.type: Easing.InOutCubic}}
							}
						tickmark: Rectangle {
							visible: true
							implicitWidth: outerRadius * 0.02
							antialiasing: true
							implicitHeight: outerRadius * 0.06
							color: T3Styling.cFgMain_c
							radius: outerRadius * 0.02
						}
						minorTickmark: Rectangle {
							visible: true
							implicitWidth: outerRadius * 0.01
							antialiasing: true
							implicitHeight: outerRadius * 0.03
							color: T3Styling.cFgMain_c
							radius: outerRadius * 0.02
						}
						tickmarkLabel:  Text {
							font.pixelSize: Math.max(6, outerRadius * 0.13)
							font.family: "Inter"
							text: styleData.value
							color: T3Styling.cFgSub_c
							antialiasing: true
							opacity: textOnly_b?0:1
							Behavior on opacity {NumberAnimation{}}
						}
					}
				value: currValue_n
				Behavior on value {NumberAnimation{}}
				maximumValue: root.maxValue_n
				minimumValue: root.minValue_n
			}
			T3Text{
				anchors.fill: parent
				anchors.margins: root.height*0.2
				textPixelSize_r: T3Styling.fontMain_r
				textColor_c: T3Styling.cFgMain_c
				opacity: !textOnly_b?0:1
				textContent_s: currValue_n
			}
			T3Text{
				anchors.bottom: parent.bottom
				anchors.left: parent.left
				anchors.right: parent.right
				textPixelSize_r: T3Styling.fontMain_r
				textColor_c: T3Styling.cFgMain_c
				textContent_s: gaugeUnit_s
			}
			Text{
				anchors{
					horizontalCenter: parent.horizontalCenter
					bottom: parent.bottom
					margins: parent.height*0.05
				}
				height:  item_ratioKeeper.width*0.1
				text:"~~~"
				font.family: "DSEG14 Classic"
				visible: false
				font.pixelSize: T3Styling.fontMain_r
				fontSizeMode: Text.Fit
				color: T3Styling.cFgSub_c
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				opacity: 0.15
			}
		}
	}
	//for testing only
	MouseArea{
		anchors.fill: parent
		onClicked: currValue_n-=10
	}
	Timer{
		running: toggle_b
		repeat: true
		onTriggered: textOnly_b = !textOnly_b;
		interval: 3000
	}
}
