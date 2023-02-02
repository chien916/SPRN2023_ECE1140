import QtQuick 2.12
import QtQuick.Window 2.12

Window {
	width: 640
	height: 480
	visible: true
	title: qsTr("Hello World")
	visibility: "FullScreen"
	Rectangle{
		color: T3Styling.cBgSub_c
		anchors.fill: parent
	}
	T3CTC{
		anchors.fill: parent
	}
}
