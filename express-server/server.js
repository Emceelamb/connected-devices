const express = require('express');
const app = express();

let ua;
app.get('/', (request, response)=> {
	response.write('<html>');
	response.write('<head>');
	response.write('</head>');
	response.write('<body>');
	response.write('<h1>HELLO!</h1>');
	response.write('go to \'\/browser and I will tell you about yourself ;)')
	response.write('</body>');
	response.write('</html>');
	response.end();
	console.log(request.headers['user-agent']+ ' joined!');
});

app.get('/browser', (request, response)=>{
	ua =request.headers['user-agent'];	
	response.write('<html>');
	response.write('<head></head');
	response.write('<body>');
	response.write('<h1>You\'re using: </h1>'+ ua);
	response.end();
	console.log(ua +' wants to know their browser');
});
app.listen(3000, ()=> console.log('Listening on port 3000'));
