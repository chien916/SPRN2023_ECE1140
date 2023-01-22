import QtQuick 2.12

Item {
	id:root

	property int currSpeedLimit_i:60
	//"clear"|"approach"|"stop"
	property string currSignal_s: "stop"

	readonly property variant speedLimitIntervals_iA: [80,70,65,60,55,45,40,30,20,15]
	readonly property int roundedSpeedLimit_i:{
		for(const currSpeedLimitIntervalPoint_i of speedLimitIntervals_iA){
			if(currSpeedLimit_i>=currSpeedLimitIntervalPoint_i)
				return currSpeedLimitIntervalPoint_i;
		}
	}
	Rectangle{
		color: T3Styling.cBgSub_c
		anchors.fill:parent
		radius: T3Styling.margin_r
		Rectangle{
			id:item_ratioKeeper
			readonly property double widthToHeight_d: 0.5
			width:parent.width<parent.height*widthToHeight_d?parent.width-2*T3Styling.margin_r:parent.height*widthToHeight_d
			height:parent.height*widthToHeight_d<=parent.width?parent.height-2*T3Styling.margin_r:parent.width/widthToHeight_d
			color:"transparent"
			anchors{
				horizontalCenter: parent.horizontalCenter
				verticalCenter: parent.verticalCenter
			}
			Column{
				id:column_speedLimitSquares
				spacing: T3Styling.spacing_r
				readonly property real squareSideLength_r: (item_ratioKeeper.height-T3Styling.spacing_r*9)/10;
				Repeater{
					model:root.speedLimitIntervals_iA
					delegate:	Rectangle{
						readonly property int copiedModelData_i: modelData
						width: column_speedLimitSquares.squareSideLength_r
						height:  column_speedLimitSquares.squareSideLength_r
						radius: T3Styling.lineWidth_r
						color: {
							if(modelData===15)
								if(root.roundedSpeedLimit_i===modelData)
									if(root.currSpeedLimit_i!==root.roundedSpeedLimit_i)
										return T3Styling.cYellow_c;
									else
										return T3Styling.cFgMain_c;
								else
									return T3Styling.cFgSubSub_c;
							else
								return "transparent"
						}
						Behavior on color{PropertyAnimation{}}
						border.color: {
							if(modelData===15)
								return T3Styling.cBgSub_c;
							else
								if(root.currSpeedLimit_i<=80&&root.roundedSpeedLimit_i===copiedModelData_i)
									if(root.currSpeedLimit_i!==root.roundedSpeedLimit_i)
										return T3Styling.cYellow_c;
									else
										return T3Styling.cFgMain_c;
								else
									return T3Styling.cFgSubSub_c;
						}
						Behavior on border.color{PropertyAnimation{}}
						border.width: modelData===15?0:T3Styling.lineWidth_r
						Text{
							text:parent.copiedModelData_i.toString()
							color: parent.border.color

							anchors.fill: parent
							anchors.margins: T3Styling.lineWidth_r
							font.family: "Inter"

							font.pixelSize: T3Styling.fontSub_r
							fontSizeMode: Text.Fit
							horizontalAlignment: Text.AlignHCenter
							verticalAlignment: Text.AlignVCenter

						}
					}
				}
			}
			Item{
				id:item_commandedSpeedLabel
				width:item_ratioKeeper.width-column_speedLimitSquares.squareSideLength_r-T3Styling.spacing_r
				height: column_speedLimitSquares.squareSideLength_r
				x:column_speedLimitSquares.squareSideLength_r+T3Styling.spacing_r
				Text{
					id:text_commandedSpeedLabel
					anchors{
						margins: T3Styling.spacing_r
						fill: parent
					}
					color: T3Styling.cFgMain_c
					text:"Commanded Speed"
					font.family: "Inter"
					font.letterSpacing: T3Styling.lineWidth_r
					font.pixelSize: T3Styling.fontSub_r
					fontSizeMode: Text.Fit
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
				}
			}

			Rectangle{
				id:rectangle_commandedSpeedValue
				width: item_commandedSpeedLabel.width
				height: column_speedLimitSquares.squareSideLength_r*2+T3Styling.spacing_r
				x:item_commandedSpeedLabel.x
				y: item_commandedSpeedLabel.y+item_commandedSpeedLabel.height+T3Styling.spacing_r
				border.width: T3Styling.lineWidth_r
				color: "transparent"
				border.color: T3Styling.cFgSubSub_c
				radius: T3Styling.lineWidth_r
				Text{
					id:text_commandedSpeedValueBack
					anchors.fill: parent
					text:"~~~"
					font.family: "DSEG14 Classic"
					font.pixelSize: T3Styling.fontSub_r
					fontSizeMode: Text.HorizontalFit
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					color: T3Styling.cFgSubSub_c
				}
				Text{
					id:text_commandedSpeedValue
					anchors.fill: parent
					text:root.currSpeedLimit_i.toString().padStart(3,"!").substring(0,3)
					font.family: "DSEG14 Classic"
					font.pixelSize: T3Styling.fontSub_r
					fontSizeMode: Text.HorizontalFit
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					color: {
						if(root.currSpeedLimit_i!==root.roundedSpeedLimit_i)
							if(root.currSpeedLimit_i>80)
								return T3Styling.cRed_c;
							else
								return T3Styling.cYellow_c;
						else
							return T3Styling.cFgMain_c;
					}
				}
			}

			Item{
				id:item_signalLabel
				width:item_ratioKeeper.width-column_speedLimitSquares.squareSideLength_r-T3Styling.spacing_r
				height: column_speedLimitSquares.squareSideLength_r
				x:column_speedLimitSquares.squareSideLength_r+T3Styling.spacing_r
				y:rectangle_commandedSpeedValue.y+(column_speedLimitSquares.squareSideLength_r+T3Styling.spacing_r)*3
				Text{
					id:text_signalLabel
					anchors{
						margins: T3Styling.spacing_r
						fill: parent
					}
					color: T3Styling.cFgMain_c
					text:"Next Rail-Block Signal"
					font.family: "Inter"
					font.letterSpacing: T3Styling.lineWidth_r
					font.pixelSize: T3Styling.fontSub_r
					fontSizeMode: Text.Fit
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
				}
			}

			Rectangle{
				id:rectangle_signalValue
				width: item_signalLabel.width
				height: column_speedLimitSquares.squareSideLength_r*5+T3Styling.spacing_r*4
				x:item_signalLabel.x
				y: item_signalLabel.y+item_signalLabel.height+T3Styling.spacing_r
				border.width: T3Styling.lineWidth_r
				color: "transparent"
				border.color: T3Styling.cFgSubSub_c
				radius: T3Styling.lineWidth_r
				Column{
					id:column_signalOrganizer
					spacing: T3Styling.margin_r
					anchors{
						horizontalCenter: rectangle_signalValue.horizontalCenter
						verticalCenter: rectangle_signalValue.verticalCenter
						margins: T3Styling.margin_r
					}
					Repeater{
						model:3
						delegate:Rectangle{
							height: (rectangle_signalValue.height-column_signalOrganizer.spacing*4)/3
							width: height
							radius: width*0.5
							color: {
								if(index===0&&root.currSignal_s==="clear")
									return T3Styling.cGreen_c
								else if(index===1&&root.currSignal_s==="approach")
									return T3Styling.cYellow_c
								else if(index===2&&root.currSignal_s==="stop")
									return T3Styling.cRed_c
								else
									return T3Styling.cFgSubSub_c
							}
							Behavior on color {PropertyAnimation{}}
						}
					}
				}
			}
		}
	}
	implicitHeight: 500
	implicitWidth: 300
	//for testing only
	MouseArea{
		anchors.fill: parent
		onClicked: currSpeedLimit_i+=10
	}
}
