/**
 * This program will parse the existing CSV route file into JSON object
 * The JSON object will be ready to push to the firebase database system
 * 
 * To parse a file, run the following command in the command terminal
 * node parser.js -f FILE_NAME
 */
let arguments_sA = process.argv;
let fileReader_O = new FileReader();
fileReader_O.addEventListener("error",()=>{
    console.log("Read error");
})