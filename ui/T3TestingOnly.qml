import QtQuick 2.12

Item {
	implicitHeight: 500
	implicitWidth: 500
	Text{
		text:{
			//		let str_s = ""
			//		for(let currObj_O in testTrackDatabase.lineObjects_OA[0]){

			//		}
			return Object.keys(testTrackDatabase.lineObjects_OA[0].blocksMap).toString()
		}
	}

	function getRowLengthArray_f(lineObjects_O,maxWidth_n){
		let secondRowStartingMultiples_nA = [];
		let firstRowLengthMultiples_nAA = [];
		let secondRowLengthMultiples_nAA = [];
		let currBlockOnFirstRow_O = lineObjects_O.startingBlock1;
	}

	//greatest common divisior
	function gcd_f (a_n, b_n)  {
		if (b_n !== 0) { return gcd_f(b_n, a_n % b_n); }
		else return Math.abs(a_n);
	}

	//least common multiples
	function lcm_f (a_n, b_n)  {
		return (a_n * b_n) / gcd_f(a_n, b_n);
	}

}
