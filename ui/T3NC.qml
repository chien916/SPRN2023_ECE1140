import QtQuick 2.12

Item {
	implicitWidth: 1000
	implicitHeight: 400
	Rectangle{
		anchors.fill: parent
		color: T3Styling.cBgSub_c
	}
	Item{
		id:item_canvas
		anchors.fill: parent
		anchors.margins: T3Styling.margin_r
		T3SegDisplay{
			id:sDis_segDisplay
			anchors{
				top:parent.top
				left:parent.left
				right:parent.right
			}
		}
	}
}
