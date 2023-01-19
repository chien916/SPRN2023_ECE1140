import QtQuick 2.12
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
Item {
	id:root
	property string gaugeUnit_s: "mph"
	property int maxValue_n: 100
	property int minValue_n: 0
	property int currValue_n: 50
	implicitHeight: 500
	implicitWidth: 500
	Rectangle{
		id:rectangle_container
		color: YhStyling.cBgSub_c
		radius: YhStyling.margin_r
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
				anchors.margins: parent.height*0.05
				style: CircularGaugeStyle {
						needle: Rectangle {
							y: outerRadius * 0.2
							implicitWidth: outerRadius * 0.05
							implicitHeight: outerRadius * 0.9
							antialiasing: true
							color: YhStyling.cFgMain_c
							radius: outerRadius * 0.05
						}
						foreground: Rectangle {
								width: outerRadius * 0.2
								height: width
								radius: width / 2
								color: YhStyling.cFgMain_c
								anchors.centerIn: parent
							}
						tickmark: Rectangle {
							visible: true
							implicitWidth: outerRadius * 0.02
							antialiasing: true
							implicitHeight: outerRadius * 0.06
							color: YhStyling.cFgMain_c
							radius: outerRadius * 0.02
						}
						minorTickmark: Rectangle {
							visible: true
							implicitWidth: outerRadius * 0.01
							antialiasing: true
							implicitHeight: outerRadius * 0.03
							color: YhStyling.cFgMain_c
							radius: outerRadius * 0.02
						}
						tickmarkLabel:  Text {
							font.pixelSize: Math.max(6, outerRadius * 0.1)
							font.family: "Inter"
							text: styleData.value
							color: YhStyling.cFgSub_c
							antialiasing: true
						}
					}
				value: currValue_n
				Behavior on value {NumberAnimation{}}
				maximumValue: root.maxValue_n
				minimumValue: root.minValue_n
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
				font.pixelSize: YhStyling.fontMain_r
				fontSizeMode: Text.Fit
				color: YhStyling.cFgSub_c
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				opacity: 0.15
			}
			Text{
				anchors{
					horizontalCenter: parent.horizontalCenter
					bottom: text_digitalDisplayForeground.top
					margins: parent.height*0.05
				}
				height:  item_ratioKeeper.width*0.1
				text:root.gaugeUnit_s
				font.family: "Inter"
				font.pixelSize: YhStyling.fontSub_r
				fontSizeMode: Text.Fit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				color: YhStyling.cFgSub_c
			}
			Text{
				id:text_digitalDisplayForeground
				anchors{
					horizontalCenter: parent.horizontalCenter
					bottom: parent.bottom
					margins: parent.height*0.05
				}
				height: item_ratioKeeper.width*0.1
				text:root.currValue_n.toString().padStart(3,"!").substring(0,3)
				font.family: "DSEG14 Classic"
				font.pixelSize: YhStyling.fontMain_r
				fontSizeMode: Text.Fit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				color: YhStyling.cFgMain_c
			}
		}
	}
	//for testing only
	MouseArea{
		anchors.fill: parent
		onClicked: currValue_n-=10
	}
}
