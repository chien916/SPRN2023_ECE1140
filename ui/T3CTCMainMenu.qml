import QtQuick 2.12
import QtQuick.Dialogs 1.3
Item {
	implicitHeight: 500
	implicitWidth: 500
	Rectangle{
		id:rect_canvas
		radius: T3Styling.margin_r
		color: T3Styling.cBgSub_c
		anchors.fill: parent
		Column{
			id:colu_column
			property int count_i :8
			readonly property real unitHeight_r
			:(rect_canvas.height-2*colu_column.anchors.margins
			  - (count_i-1)*colu_column.spacing)/count_i
			spacing: T3Styling.margin_r
			anchors.fill: parent
			anchors.margins: T3Styling.margin_r
			Text{
				text:"T3 CTC OFFICE VER 2023.02.02"
				anchors.horizontalCenter: colu_column.horizontalCenter
				width: colu_column.width-2*T3Styling.margin_r
				height: colu_column.unitHeight_r
				font.pixelSize: T3Styling.fontMain_r
				color: T3Styling.cFgSubSub_c
				font.letterSpacing: T3Styling.lineWidth_r
				bottomPadding: T3Styling.lineWidth_r*5
				font.family: "Inter"
//				font.bold: true
				fontSizeMode: Text.Fit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
			}
			T3ParamUnit{
				width: colu_column.width
				height: colu_column.unitHeight_r
				paramConfig_A: "F_F_Clock Rate_x"
				minValue_r: 0.1
				maxValue_r: 50
			}
			T3ParamUnit{
				width: colu_column.width
				height: colu_column.unitHeight_r
				paramConfig_A: "F_T_Automatic Mode_"
			}
			T3Button{
				width: colu_column.width
				height: colu_column.unitHeight_r
				buttonLabel_s: "Load line"
			}
			T3Button{
				width: colu_column.width
				height: colu_column.unitHeight_r
				buttonLabel_s: "Load time schedule"
			}
			T3Button{
				width: colu_column.width
				height: colu_column.unitHeight_r
				buttonLabel_s: "Manually Dispatch"
			}
			T3Button{
				width: colu_column.width
				height: colu_column.unitHeight_r
				buttonLabel_s: "Debugging Interface"
				onButtonClicked: {
								var component = Qt.createComponent("qrc:/T3CTCTestInterface.qml")
								var window    = component.createObject(root)
								window.show()

				}
			}

			T3Button{
				width: colu_column.width
				height: colu_column.unitHeight_r
				buttonLabel_s: "Quit Software"
				onButtonClicked: Qt.callLater(Qt.quit)
			}



		}



	}

}
