import QtQuick 2.12
import QtQuick.Controls 1.4
import QtQuick.Window 2.12
Window {
	height: 500
	width: 200
	Column{
		Text{
			text:"CTC OFFICE TEST INTERFACE 1.0"
		}
		TextField{
			text: "test"
		}
		Button{
			text: "Get Block By ID"
		}
		Text{
			text:"Queried Rail Block Status: " + "OK"
		}

		Column {
			id:colu_column
			property int currInd_i:0
			ExclusiveGroup { id: group }
			Repeater{
				model:[
					"CommandedSpeed"
					, "Authority"
					, "SwitchPostion"
					, "ForwardLight"
					, "ReversedLight"
					, "CrossingPosition"
					, "TrainOnBlock"
					, "Failure"
					, "Heaters"
					, "PeopleOnStation"
				]
				delegate:	RadioButton {
//					checked: true
					text: modelData
					exclusiveGroup: group
				}

			}
		}
		Text{
			text:"Queried Value: " + "24"
		}
		TextField{
			text: "15"
		}
		Button{
			text: "Set new value"
		}

	}


}
