import QtQuick 2.12

Item {
	implicitHeight: T3Styling.fontSubSub_r+T3Styling.spacing_r*2
	implicitWidth: 200
	property string buttonLabel_s :"buttonText"
	signal buttonClicked()
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
		T3Text{
			textContent_s: buttonLabel_s
			textPixelSize_r: T3Styling.fontSubSub_r
			textColor_c: T3Styling.cFgMain_c
			anchors{
				margins: T3Styling.spacing_r
				fill:parent
			}
		}
	}
	MouseArea{
		id:mAre_mouseArea
		hoverEnabled: true
		anchors.fill: rect_buttonBackground
		onClicked: buttonClicked()
	}

}
