const express = require('express');
const bodyParser = require('body-parser');
const db = require('./queries');
const app = express();
const port = 8000;

app.use(bodyParser.json());
app.use(
    bodyParser.urlencoded({
        extended: true,
    })
);

app.get('/',(req, res)=>{
    res.json({info: 'Postgres example'});
});

app.listen(port,()=>{
    console.log(`App running on port ${port}`);
});

app.get('/users', db.getUsers);
app.get('/users/:id', db.getUserById);
app.post('/users', db.createUser);
app.put('/users/:id', db.updateUser);
