import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Window 2.12

ApplicationWindow {
	id:root
	width: 640
	height: 480
	visible: true
	title: qsTr("Hello World")
	Rectangle{
		color: T3Styling.cBgSub_c
		anchors.fill: parent
	}
	T3Button{
		buttonLabel_s: "pull from db"
		onButtonClicked: {
			t3databaseQml.pullFromFirebase()
		}
	}

	T3Button{
		buttonLabel_s: "initialize new ctc window"
		y:20
		onButtonClicked: {
			var component = Qt.createComponent("qrc:/T3CTC.qml")
			var window = component.createObject(root)
			window.show()
		}
	}
}
