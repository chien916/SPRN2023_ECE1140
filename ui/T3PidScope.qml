import QtQuick 2.12
import QtCharts 2.13
import QtQuick.Controls 2.15
Rectangle {
	implicitHeight: 500
	implicitWidth: 500
	property variant tbuffer: testTrainController.tbuffer_q
	property variant ybuffer: testTrainController.ybuffer_q
//	property variant rbuffer: testTrainController.rbuffer_q
	onYbufferChanged: {
		if(tbuffer[tbuffer.length-1]>10){spli_plot.remove(1)}

		spli_plot.append(tbuffer[tbuffer.length-1],ybuffer[ybuffer.length-1]);
	}
	Rectangle{
		anchors.fill: parent
		color:T3Styling.cBgSub_c
		radius: T3Styling.margin_r
		Rectangle{
			id:rect_canvas
			color: "white"
			anchors{
				fill:parent
				margins:T3Styling.margin_r
			}
			ChartView {
				width: 400
				height: 300
				theme: ChartView.ChartThemeBrownSand
				antialiasing: true
				ValueAxis{
					id:sharedT
					min: tbuffer.length<100?0:tbuffer[tbuffer.length-100]
					max: tbuffer[tbuffer.length-1]
				}
				ValueAxis{
					id:sharedY
					min: 0
					max: 1000
				}

				SplineSeries {
					id:spli_plot
					axisY:sharedY
					color: "green"
					axisX:sharedT
				}
				LineSeries {
					id:spliref_plot
					axisY:sharedY
					color: "blue"
					axisX:sharedT
					XYPoint{x:sharedT.min;y:sharedT.testTrainController.r_q}
					XYPoint{x:sharedT.max;y:sharedT.testTrainController.r_q}
				}

			}
			Slider{
				from:0
				to:1000
				onValueChanged: {testTrainController.r_q = value;}
			}
			Text{
				text:ybuffer[ybuffer.length-1]+" "+testTrainController.r_q
			}
		}

	}

}
