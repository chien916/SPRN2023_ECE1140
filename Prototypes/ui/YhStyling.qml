pragma Singleton
import QtQuick 2.12

/**https://learn.microsoft.com/en-us/sharepoint/dev/design/themes-colors

  Add the following to main function to ensure font loading
	QFontDatabase::addApplicationFont(":/YhSansFont.ttf");
	QFontDatabase::addApplicationFont(":/YhSegFont.ttf");
*/
Item {
	property int minScreenPixel: 500
	readonly property color c_bgMain: "#000000"
	readonly property color c_bgSub: "#262626"
	readonly property color c_fgMain: "#ffffff"
	readonly property color c_fgSub: "#a6a6a6"
	readonly property color c_yellow: "#E8D19D"
	readonly property color c_red: "#EB9091"
	readonly property color c_blue: "#BFD3E4"
	readonly property color c_green: "#C9CDB3"
	readonly property int i_margin: minScreenPixel*0.1
	readonly property int i_fontMain: minScreenPixel*0.1
	readonly property int i_fontSub: minScreenPixel*0.05
}
