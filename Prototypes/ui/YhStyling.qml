pragma Singleton
import QtQuick 2.12

/**https://learn.microsoft.com/en-us/sharepoint/dev/design/themes-colors

  Add the following to main function to ensure font loading
	QFontDatabase::addApplicationFont(":/YhSansFont.ttf");
	QFontDatabase::addApplicationFont(":/YhSegFont.ttf");
*/
Item {
	property real minScreenPixel_r: 500
	readonly property color cBgMain_c: "#000000"
	readonly property color cBgSub_c: "#212121"
	readonly property color cFgMain_c: "#ffffff"
	readonly property color cFgSub_c: "#a6a6a6"
	readonly property color cFgSubSub_c: "#3c3c3c"
	readonly property color cYellow_c: "#ffff00"
	readonly property color cRed_c: "#ff0000"
	readonly property color cBlue_c: "#78d7ec"
	readonly property color cGreen_c: "#00ff00"
	readonly property real margin_r: minScreenPixel_r*0.05
	readonly property real spacing_r:margin_r*0.2
	readonly property real lineWidth_r:margin_r*0.1
	readonly property real fontMain_r: minScreenPixel_r*0.1
	readonly property real fontSub_r: minScreenPixel_r*0.05
}
