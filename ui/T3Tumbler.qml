import QtQuick 2.12
import QtQuick.Controls 2.15
Item {
	id:root
	implicitHeight: 200
	implicitWidth: 200
	property variant model_A:
		//title,model
		["Line",["R"]]
	Rectangle{
		anchors.fill: root
		color: T3Styling.cBgMain_c
	}

	Tumbler{
		id:tumb_tumbler
		model:20
		delegate: T3Text{
			textColor_c: T3Styling.cFgMain_c
			textPixelSize_r:T3Styling.fontSub_r
			opacity: 1.0 - Math.abs(Tumbler.displacement) / (Tumbler.tumbler.visibleItemCount / 2)

		}
	}




}
