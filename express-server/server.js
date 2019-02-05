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
	response.write('<br>go to \'\/browser\/{your browser} and I will tell you more browsers. :o')
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

app.get('/browser/:browser', (request,response)=>{
	let browser = request.params.browser;
	if(browser!='internetexplorer'){
		response.send("Why don't you try internetexplorer? You know its the most popular web browser.")
	} else {
		response.send("IE #1");
	}
});
app.listen(3000, ()=> console.log('Listening on port 3000'));
