var data = {
    "food": [{
            "title": "Pumpkin Spice Bread Recipe",
            "image": "../menu_sushi_list/lohi.jpeg",
        },
        {
            "title": "New New",
            "image": "../menu_sushi_list/futomaki.jpeg",
        }
    ]
}

var output = "<ul>";
// Create a variable to temporarily store the data 
for (var i in data.food) {
    output += "<li><a title='" + data.food[i].title + "'>" + data.food[i].title + "<img title='" + data.food[i].title + "' src='" + data.food[i].image + "' /></li>";
}
output += "</ul>";
// Once we go through all of the elements in the array, 
// we use the output variable to populate the placeholder div.
var test = document.getElementsByClassName('food')
console.log(test)
    // document.getElementById('food').innerHTML = output
var test2 = document.createElement('div')
test2.classList.add('test')
test2.innerHTML = output
document.getElementsByClassName('food')[0].append(test2)