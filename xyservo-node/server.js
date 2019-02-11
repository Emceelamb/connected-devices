const express = require('express');
const app = express();

app.get('/', (req,res)=>{
	
	console.log(req.headers['user-agent']);
});

app.listen(8000);
console.log('started on port 8000');
