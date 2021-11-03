var http = require('http');
const { resourceUsage } = require('process');

var server = http.createServer(function (request, response) {
    if(request.url == '/'){
        response.writeHead(200, {'Content-Type': 'text/html'});
        response.write('<html><head><title> Sang ne </title></head><body><h1>Helloooooooooo!!!!</h1></body></html>');
        response.end();
    }
    else if (request.url == '/post-demo' && request.method == 'POST'){
        response.writeHead(200, {'Content-Type': 'application/json'});
        response.write(JSON.stringify({data: 12345}));
        response.end();
    }
    return response;
});

var port = 9090;
server.listen(port);
console.log(`Node.js web server at port ${port}`);
//console
