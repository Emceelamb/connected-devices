const express = require ('express');
const app = express();
app.set('view engine', 'ejs');
app.get('/form', (req, res)=>{
        res.render('main.ejs', req);
});

app.get('/', (req, res)=>{
    res.render('hue.ejs', req);
});

app.listen(8000, (res)=>{
    console.log('listening on port 8000');
});

