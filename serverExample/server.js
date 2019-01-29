const express = require('express');		// include express lib
const server = express();			// create a server
server.use('/', express.static('public'));	// serve static files

function getTime(request, response){
	let now = new Date();
	response.send(now);
	response.end();
	// check out queries
}

function getAge(request, response){
	response.end('Your\'e as old as you are');
	// checkout params
}

server.get('/time', getTime);
server.get('/age', getAge);
server.listen(8080);				// start the server on port 


