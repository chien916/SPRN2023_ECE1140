function solveForCoors_f(rootObj_O) {
	let blocksMap_O = rootObj_O["blocksMap"];
	let currTopBlockId_s = rootObj_O["startingBlock1"];
	let currBottomBlockId_s = rootObj_O["startingBlock2"];
	let currTopBlockLine_A = [];
	let currBottomBlockLine_A = [];
	let currBlockGridList_A = [];
	while (true) {
		let currIsDoubleLine_b = currBottomBlockId_s !== "";
		let currTopBlockObj_O = blocksMap_O[currTopBlockId_s];
		let currBottomBlockObj_O
			= currIsDoubleLine_b ? blocksMap_O[currBottomBlockId_s] : null;
		let spreadLength_f = (blockLine1_A, blockLine2_A) => {
			let theSmallerLength_n
				= Math.min(blockLine1_A.length, blockLine2_A.length);
			let theBiggerLength_n
				= Math.max(blockLine1_A.length, blockLine2_A.length);
			let theShorterBlockLine_O
				= blockLine1_A.length === theSmallerLength_n
					? blockLine1_A : blockLine2_A;
			let newSmallerWidth_n = theBiggerLength_n / theSmallerLength_n;
			for (let currTopBlock_A of theShorterBlockLine_O) {
				currTopBlock_A[1] = newSmallerWidth_n;
			}
		};
		if (!currIsDoubleLine_b
			&& currTopBlockId_s === rootObj_O["endingBlock1"]
			&& currBottomBlockId_s === rootObj_O["endingBlock2"]) {
			currTopBlockLine_A.push([currTopBlockId_s, 1]);
			currBlockGridList_A.push([[...currTopBlockLine_A], []]);
			break;
		} else if (currIsDoubleLine_b
			&& currTopBlockId_s === rootObj_O["endingBlock1"]
			&& currBottomBlockId_s === rootObj_O["endingBlock2"]) {
			currTopBlockLine_A.push([currTopBlockId_s, 1]);
			currBottomBlockLine_A.push([currBottomBlockId_s, 1]);
			spreadLength_f(currTopBlockLine_A, currBottomBlockLine_A);
			currBlockGridList_A.push([[...currTopBlockLine_A], [...currBottomBlockLine_A]]);
			break;
		} else if (currIsDoubleLine_b
			&& currTopBlockId_s !== currBottomBlockId_s
			&& (((currTopBlockId_s === rootObj_O["endingBlock1"]
				|| (currTopBlockObj_O["prevBlock2"] !== ""
					&& currTopBlockObj_O["prevBlock2"] !== "PASSIVE"))
				&& currBottomBlockId_s !== rootObj_O["endingBlock2"]))) {
			currBottomBlockLine_A.push([currBottomBlockId_s, 1]);
			currBottomBlockId_s = currBottomBlockObj_O["nextBlock1"];
		} else if (currIsDoubleLine_b
			&& currTopBlockId_s !== currBottomBlockId_s
			&& (((currBottomBlockId_s === rootObj_O["endingBlock2"]
				|| (currBottomBlockObj_O["prevBlock2"] !== ""
					&& currBottomBlockObj_O["prevBlock2"] !== "PASSIVE"))
				&& currTopBlockId_s !== rootObj_O["endingBlock1"]))) {
			currTopBlockLine_A.push([currTopBlockId_s, 1]);
			currTopBlockId_s = currTopBlockObj_O["nextBlock1"];
		} else if (currIsDoubleLine_b
			&& (currTopBlockObj_O["prevBlock2"] !== "" && currTopBlockObj_O["prevBlock2"] !== "PASSIVE")
			&& (currBottomBlockObj_O["prevBlock2"] !== "" && currBottomBlockObj_O["prevBlock2"] !== "PASSIVE")) {
			spreadLength_f(currTopBlockLine_A, currBottomBlockLine_A);
			currBlockGridList_A.push([[...currTopBlockLine_A], [...currBottomBlockLine_A]]);
			currTopBlockLine_A = [];
			currBottomBlockLine_A = [];
			currIsDoubleLine_b = false;
			currBlockGridList_A.push([[[currTopBlockId_s, 2]],[]]);//switch has min width 2
			// currTopBlockLine_A.push([currTopBlockId_s, 1]);
			currTopBlockId_s = currTopBlockObj_O["nextBlock1"];
			currBottomBlockId_s = currTopBlockObj_O["nextBlock2"];
		} else if (!currIsDoubleLine_b
			&& !currIsDoubleLine_b
			&& currTopBlockObj_O["nextBlock2"] !== "") {
			// currTopBlockLine_A.push([currTopBlockId_s, 1]);
			currBlockGridList_A.push([[...currTopBlockLine_A], []]);
			currBlockGridList_A.push([[[currTopBlockId_s, 2]],[]]);//switch has min width 2
			currTopBlockLine_A = [];
			currIsDoubleLine_b = true;
			currTopBlockId_s = currTopBlockObj_O["nextBlock1"];
			currBottomBlockId_s = currTopBlockObj_O["nextBlock2"];
		} else if (currIsDoubleLine_b) {
			currTopBlockLine_A.push([currTopBlockId_s, 1]);
			currBottomBlockLine_A.push([currBottomBlockId_s, 1]);
			currTopBlockId_s = currTopBlockObj_O["nextBlock1"];
			currBottomBlockId_s = currBottomBlockObj_O["nextBlock1"];
		} else if (!currIsDoubleLine_b) {
			currTopBlockLine_A.push([currTopBlockId_s, 1]);
			currTopBlockId_s = currTopBlockObj_O["nextBlock1"];
		}
	}
	let currBlockFlattenedTopList_A = [];
	let currBlockFlattenedBottomList_A = [];
	let currTopX_n = 0;
	let currBottomX_n = 0;

	for (let currBlockGrid_A of currBlockGridList_A) {
		
		for (let currTopBlock_A of currBlockGrid_A[0]) {
			currBlockFlattenedTopList_A.push([currTopBlock_A[0], [0, currTopX_n],currTopBlock_A[1]]);
			currTopX_n += currTopBlock_A[1];
		}
		for (let currBottomBlock_A of currBlockGrid_A[1]) {
			currBlockFlattenedBottomList_A.push([currBottomBlock_A[0], [1, currBottomX_n],currBottomBlock_A[1]]);
			currBottomX_n += currBottomBlock_A[1];
		}
		currBottomX_n = currTopX_n;
	}
	let concatedBlockFlattenedList_A
		= currBlockFlattenedTopList_A.concat(currBlockFlattenedBottomList_A);

	return concatedBlockFlattenedList_A;
};

let bluelineJson_O = require("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3BlueLine_json.json");
let greenLineJson_O = require("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3GreenLine_json.json");
let redLineJson_O = require("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3RedLine_json.json");

let res = solveForCoors_f(redLineJson_O);
let i = 0;



