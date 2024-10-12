const express = require('express');
const router = require('./router');


const cors = require('cors');
const morgan = require('morgan');
const bodyParser = require("body-parser");
const app = express();

const port = process.env.PORT || 3000;

//app.use(express.static('./public'))
app.use(express.static('public'));

app.use(morgan('combined')); 
app.use(cors()); 
app.use(bodyParser.json()); 
app.use(bodyParser.urlencoded({
        extended: true
    }));
app.use(router); // Requests processing will be defined in the file router
app.listen(port, () => console.log('Server app listening on port ' + port));
