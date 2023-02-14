import QtQuick 2.12

Item {/*
	signal cancelClicked();
	signal applyClicked();
	readonly property variant configModel_nA:[
		//[textonly,twostate,labal,unit]
		["maintain","maintainance mode",true]
		,["authority","authority",true]
		,["commandedSpeed","commanded speed",false]
		,["crossingPosition","switch up",true]
		,["authority","switch down",true]
		,["authority","discrete ",true]
		,["authority","continuous ",false]
		,["authority","continuous 2",false]
	]
	property variant trackConstantsObject_O : {
		return {
			"crossing": false,
			"direction": "BIDIRECTIONAL",
			"elevation": 0.25,
			"grade": 0.5,
			"length": 50,
			"nextBlock1": "R_E_15",
			"nextBlock2": "PASSIVE",
			"prevBlock1": "R_A_2",
			"prevBlock2": "",
			"speedLimit": 40,
			"station": "",
			"underground": false
		}//for testing only
	}

	property variant trackVariablesObject_O : {
		return {
			"authority": false,//changeable -> two-button pair -> switch
			"commandedSpeed": 0,
			"crossingPosition": "",
			"failure": "",
			"forwardLight": "clear",
			"heaters": "",
			"peopleOnStation": 0,
			"reversedLight": "clear",
			"switchPosition": false,
			"trainOnBlock": ""
		}//for testing only
	}
	Rectangle{
		id:rect_canvas
		radius: T3Styling.margin_r
		color: T3Styling.cBgSub_c
		anchors.fill: parent
//		Column{
//			anchors{
//				margins: T3Styling.margin_r
//				fill: parent
//			}
//			id:colu_allConfigs
//			Text{
//				text:"eet"
//			}
//		}
		Column{
			id:col_column
			anchors.fill: parent
			anchors{
				topMargin: T3Styling.margin_r
				leftMargin: T3Styling.margin_r
				rightMargin: T3Styling.margin_r
				bottomMargin: T3Styling.margin_r*3
			}
//			clip: true
			spacing: T3Styling.spacing_r
			Repeater{
				model:configModel_nA
				delegate:		T3ParamConfigUnit{
					height:(rect_canvas.height-T3Styling.margin_r*4
							-col_column.spacing*(configModel_nA.length-1))/configModel_nA.length
					valueLabel_s:modelData[1]
					unitLabel_s:"mph"
					maxValue_r: 20
					minValue_r: 10
					textonly_b:false
					fixedPoint_i:2
					twoStates_b: modelData[2]
					width: col_column.width
				}
			}
		}
		T3Button{
			anchors{
				bottom:rect_canvas.bottom
				left:rect_canvas.left
//				right:rect_canvas.right
				margins: T3Styling.margin_r
			}
			height: T3Styling.margin_r
			width: (rect_canvas.width-T3Styling.margin_r*3)/2
			buttonLabel_s: "APPLY"
			onButtonClicked: applyClicked()
		}

		T3Button{
			anchors{
				bottom:rect_canvas.bottom
//				left:rect_canvas.left
				right:rect_canvas.right
				margins: T3Styling.margin_r
			}
			height: T3Styling.margin_r
			width: (rect_canvas.width-T3Styling.margin_r*3)/2
			buttonLabel_s: "CANCEL"
			onButtonClicked: cancelClicked()
		}
	}


	implicitWidth: 250
	implicitHeight: 500*/
}
