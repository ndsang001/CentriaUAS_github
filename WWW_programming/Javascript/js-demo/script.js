console.log("Here is the js-demo");
console.log("Print DOM tree");
console.log(document);
console.dir(document);
//Get element by ID
// const demoParagraph = document.getElementById("demo-paragraph");
// console.log(demoParagraph);
//Get element by CSS selector
const demoParagraphCSS = document.querySelector("#demo-paragraph");
console.log(demoParagraphCSS);


const liCollection = document.querySelectorAll("ul>li");
console.log(liCollection);
liCollection.forEach(element => {
    console.log(element);
});

// const fragment = document.createDocumentFragment();
// const tr = document.createElement("tr");
// const td1 = document.createElement("td");
// const td2 = document.createElement("td");
// tr.appendChild(td1);
// tr.appendChild(td2);
// fragment.appendChild(tr);

// let cloneRow = fragment.cloneNode(true);
// let firstId = cloneRow.querySelector("td");
// let secId = cloneRow.querySelector("td:last-child");
// firstId.innerText = "Jack";
// secId.innerText = "31";
// const tableBody = document.querySelector("#table-container > table > tbody");
// tableBody.appendChild(cloneRow);

// function whereIsTheEventNow() {
//     let event = arguments[0];
//     alert(`Where does the event propage to ${this.id}`);
//     event.preventDefault();
//     event.stopPropagation();
// }

// let googleUl = document.getElementById("google-ul");
// googleUl.addEventListener("click", whereIsTheEventNow);

// let jsLink = document.getElementById("js-link");
// jsLink.addEventListener("click", whereIsTheEventNow);

// let googleUl = document.getElementById("google-ul");
// googleUl.addEventListener("click", whereIsTheEventNow, true);

document.getElementById("demo-ajax-button").addEventListener("click", makeRequest);

function makeRequest() {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4) {
            if (xhr.status == 200) {
                console.log(xhr.responseText);
            } else {
                console.error("There was a problem with the request");
            }
        }
    }

    xhr.open("GET", "./data/test.json", true);
    xhr.send();
}