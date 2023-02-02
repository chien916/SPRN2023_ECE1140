import QtQuick 2.12
import QtQuick.Controls 1.4
Rectangle {
	//Modify these as delegate:
	property string valueLabel_s:"Speed"
	property string unitLabel_s:"mph"
	property real maxValue_r: 20
	property real minValue_r: 10
	property bool textonly_b:false
	property int fixedPoint_i:2
	property bool twoStates_b: true
	property variant ticks :null


	id:root
	implicitHeight: 60
	implicitWidth: 300
	color: T3Styling.cBgSub_c
	property real valueratio_r: 0.2
	readonly property real actualValue_r:
	{minValue_r+valueratio_r*(maxValue_r-minValue_r)}
	//	Behavior on valueratio_r{
	//		PropertyAnimation{}
	//	}
	//	readonly property real adaptiveMargin_r :root.height*0.1
	//	readonly property real adaptiveFontSize_r: root.height*0.1
	//	readonly property real adaptiveSpacing_r: root.height*0.05
	//	readonly property real adaptiveLineWidth_r : root.height*0.01
	Text{
		id:text_label
		text:valueLabel_s.toUpperCase()
		color: T3Styling.cFgSub_c
		anchors{
			left: root.left
			right:root.right
			top:root.top
			margins: T3Styling.lineWidth_r
		}
		height:textonly_b
			   ?(root.height-anchors.margins*2)
			   :(root.height-anchors.margins*3)/3
		font.family: "Inter"
		font.pixelSize: T3Styling.fontSub_r
		font.bold: true
		fontSizeMode: Text.Fit
		horizontalAlignment: Text.AlignLeft
		verticalAlignment: Text.AlignVCenter
	}
	Text{
		id:text_value
		text:{
			if(twoStates_b)
				if(actualValue_r<minValue_r+0.5*(maxValue_r-minValue_r))
					return "OFF";
				else return "ON";
			else{
				let valString_s = actualValue_r.toString()
				if(!valString_s.includes("."))valString_s+="."
				if(valString_s.includes(".")){
					let valString_sA = valString_s.split(".");
					valString_sA[1] = valString_sA[1].substr(0,1).padEnd(fixedPoint_i-1,"0");
					valString_s = valString_sA.join(".")
				}
				return valString_s
						+((unitLabel_s.length===0)?"":" "+unitLabel_s.toUpperCase())
			}

		}
		color:T3Styling.cFgMain_c
		font.bold: true
		anchors{
			left: root.left
			right:root.right
			top:root.top
			margins: T3Styling.lineWidth_r
		}
		height:textonly_b
			   ?(root.height-anchors.margins*2)
			   :(root.height-anchors.margins*3)/3
		font.family: "Inter"
		font.pixelSize: T3Styling.fontSub_r
		fontSizeMode: Text.Fit
		horizontalAlignment: Text.AlignRight
		verticalAlignment: Text.AlignVCenter
	}
	Rectangle{
		id:rect_outside
		readonly property real minX_r:x+radius
		readonly property real maxX_r:x+width-radius
		anchors{
			left: root.left
			right:root.right
			bottom:root.bottom
			margins: T3Styling.lineWidth_r
		}
		height:textonly_b?0:(root.height-anchors.margins*3)/3*2
		radius: T3Styling.margin_r/2
		color: T3Styling.cFgSubSub_c
		antialiasing: true
		clip: true
		Rectangle{
			property real widthFast_r: radius*2+(rect_outside.width-radius*2)*valueratio_r
			id:rect_inside
			opacity:{
				 0.2+valueratio_r*0.8
			}
			Behavior on opacity{
				PropertyAnimation { easing.type: Easing.OutBack }
			}
			color:{
				/*if(twoStates_b)
					if(valueratio_r<0.5) return T3Styling.cFgSub_c;//off
					else return T3Styling.cFgMain_c;//on
				else */return T3Styling.cFgMain_c;
			}
			Behavior on color{
				PropertyAnimation { easing.type: Easing.OutBack }
			}
			height:rect_outside.height
			x:twoStates_b
			  ?(valueratio_r<0.5?0:width)
			  :0
			Behavior on x{
				PropertyAnimation { easing.type: Easing.OutBack }
			}
			width: twoStates_b?rect_outside.width*0.5:widthFast_r
			Behavior on width{
				PropertyAnimation { easing.type: Easing.OutBack }
			}
			radius: rect_outside.radius
			antialiasing: true
		}
		Rectangle{
			id:rect_tick
			visible: !twoStates_b
			width:T3Styling.lineWidth_r
			height: rect_inside.height*0.5
			anchors.verticalCenter: rect_inside.verticalCenter
			x:rect_inside.x+rect_inside.widthFast_r-rect_outside.radius-width+rect_tick.width/2
			radius: width
			color: T3Styling.cFgSubSub_c
		}
		Rectangle{
			id:rect_switchOffLabel
			x:rect_outside.width/4-width/2
			y:rect_outside.height/2-height/2
			opacity: twoStates_b?1:0
			visible: twoStates_b
			height: T3Styling.lineWidth_r
			width: rect_switchOnLabel.height
			radius: width
			color: rect_tick.color
		}
		Rectangle{
			id:rect_switchOnLabel
			anchors{
				top:rect_outside.top
				bottom: rect_outside.bottom
				margins: (rect_outside.height-rect_tick.height)/2
			}
			visible: twoStates_b
			opacity: twoStates_b?1:0
			x:rect_outside.width*3/4-width/2
			width: height
			radius: width
			color: "transparent"
			border.width: T3Styling.lineWidth_r
			border.color: rect_tick.color
		}
	}
	MouseArea{
		id:mAre
		anchors.fill: rect_outside
		onReleased: {

		}
		onClicked: {
			if(!twoStates_b) return;
			if(valueratio_r<0.5) valueratio_r=1;
			else valueratio_r = 0;
		}
		onPositionChanged: {
			if(twoStates_b) return;
			let rawValRatio_r = 0.0;
			if(mouse.x<rect_outside.minX_r)
				rawValRatio_r = 0;
			else if(mouse.x>rect_outside.maxX_r)
				rawValRatio_r = 1;
			else
				rawValRatio_r
						= (mouse.x-rect_outside.minX_r)/(rect_outside.maxX_r-rect_outside.minX_r);
			let intervals_rA = [0];
			rawValRatio_r = rawValRatio_r.toFixed(root.fixedPoint_i);
			if(ticks===null)
				root.valueratio_r = rawValRatio_r;
			else{
				if(Number.isInteger(ticks)){
					let interval_r = 1/ticks;
					intervals_rA = [];
					for(let j=1;j<=ticks;++j){
						intervals_rA.push(j/ticks);
					}
				}
				else if(Array.isArray(ticks)){
					intervals_rA = ticks;
					intervals_rA.sort((a,b)=>a-b);
				}
				if(ticks.length===0) return rawValRatio_r;
				if(rawValRatio_r<=ticks[0])
					root.valueratio_r = ticks[0];
				else if(rawValRatio_r>=ticks[ticks.length-1])
					root.valueratio_r =  ticks[ticks.length-1];
				else
					for(let i=1;i<ticks.lenth-1;++i){
						if(ticks[i]<rawValRatio_r&&rawValRatio_r<=ticks[i+1]){
							if(Math.abs(rawValRatio_r-ticks[i])<Math.abs(rawValRatio_r-ticks[i+1]))
								root.valueratio_r =  ticks[i];
							else
								root.valueratio_r =  ticks[i+1];
						}
					}
			}
		}
	}
}
