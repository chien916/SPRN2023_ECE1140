import QtQuick 2.12

Item {
	implicitHeight: 500
	implicitWidth: 500
	Rectangle{
		color: YhStyling.c_bgSub
		anchors.fill:parent
		radius: YhStyling.i_margin
		Rectangle{
			id:item_ratioKeeper
			readonly property double widthToHeight_d: 0.5
			width:parent.width<parent.height?parent.width:parent.height*widthToHeight_d
			height:parent.height<parent.width?parent.height:parent.width/widthToHeight_d
			color: "blue"
			anchors{
				horizontalCenter: parent.horizontalCenter
				verticalCenter: parent.verticalCenter}
		}
	}
}
