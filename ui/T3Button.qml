import QtQuick 2.12

Item {
	implicitHeight: 100
	implicitWidth: 200
	property string buttonLabel_s :"buttonText"
	signal onButtonClicked()
	Rectangle{
		id:rect_buttonBackground
		color:{
			if(mAre_mouseArea.containsMouse&&!mAre_mouseArea.containsPress)
				return T3Styling.cBgMain_c
			else
				return T3Styling.cFgSubSub_c
		}
		Behavior on color {PropertyAnimation{duration:100}}
		radius:T3Styling.margin_r
		anchors{
			fill: parent
		}
		Text{
			text:buttonLabel_s.toUpperCase()
			font.pixelSize: T3Styling.fontSub_r
			color: T3Styling.cFgMain_c
			anchors{
				margins: T3Styling.spacing_r
				fill:parent
			}
			font.family: "Inter"
			font.bold: true
			fontSizeMode: Text.Fit
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter
		}
	}
	MouseArea{
		id:mAre_mouseArea
		hoverEnabled: true
		anchors.fill: rect_buttonBackground
		onClicked: onButtonClicked()
	}

}
