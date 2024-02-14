var express = require('express');
var router = express.Router();
var axios = require('axios')


/* GET home page. */
router.get('/', function(req, res, next) {
  var data = new Date().toISOString().substring(0, 16)
  axios.get('http://localhost:15030/plantas')
    .then(resposta => {
      res.render('index', { ps: resposta.data, d: data });
    })
    .catch(error => {
      res.render('error', {err: error})
    })
});


/* GET planta page */
router.get('/:id', function(req, res, next) {
  var data = new Date().toISOString().substring(0, 16)
  axios.get('http://localhost:15030/plantas/' + req.params.id)
    .then(resposta => {
      res.render('planta', { p: resposta.data, d: data });
    })
    .catch(error => {
      res.render('error', {err: error})
    })
});


/* GET especie page */
router.get('/especies/:id', function(req, res, next) {
  var data = new Date().toISOString().substring(0, 16)
  axios.get('http://localhost:15030/plantas?especie=' + req.params.id)
    .then(resposta => {
      res.render('especie', { ps: resposta.data, d: data });
    })
    .catch(error => {
      res.render('error', {err: error})
    })
});


module.exports = router;