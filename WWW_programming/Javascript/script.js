//const typeString = 123; // --> Number
//const typeString = "Hello World"; //--> String
//var typeString; // --> Undefined
//console.log(typeof typeString);

/*
function foo(x) {
    //var xPlusOnne = x + 1; // 8
    let xPlusOnne = x + 1;

    function bar(y) {

        console.log(x); // 7
        console.log(xPlusOnne); // 8
        console.log(y); // 15
    }
    bar(xPlusOnne + x); // xPlusOne + x = 15
}

foo(7);*/

// function varTest() {
//     var x = 1; {
//         var x = 2;
//         console.log(x);
//     }
//     console.log(x);
// }

// varTest();

// function letTest() {
//     let x = 1; {
//         let x = 2;
//         console.log(x);
//     }
//     console.log(x);
// }

// letTest();

/*z = 123;

function varTest() {
    console.log(z);
    var x = 1; {
        var x = 2;
        console.log(x);
        console.log(z)
    }
    console.log(x);
}

varTest();*/

// let text = "Hello";

// console.log(`${text}`);

//FOR - IN

// var myArray = ["hello", "world", "JS"];
// for (const key in myArray) {
//     console.log(key);
//     if (myArray.hasOwnProperty(key)) {
//         const element = myArray[key];
//         console.log(element);
//     }

// }

var myArray = { "key1": "hello", "key2": "world", "key3": "JS" };
for (const key in myArray) {
    console.log(key);
    if (myArray.hasOwnProperty(key)) {
        const element = myArray[key];
        console.log(element);
    }

}