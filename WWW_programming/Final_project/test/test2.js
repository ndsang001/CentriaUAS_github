var xhttp = new XMLHttpRequest();
var url = "test.json";

xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        document.getElementById("demo").innerHTML = this.responseText;
        var obj = this.responseText;
        var obj1 = JSON.parse(obj);
        a0 = obj1.a0;
    }
};
xhttp.open("GET", "test.json", true);
xhttp.send();