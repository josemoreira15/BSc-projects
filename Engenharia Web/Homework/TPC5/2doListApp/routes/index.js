var express = require('express');
var router = express.Router();
var Data = require('../controllers/data');

/* GET home page. */
router.get('/', function(req, res, next) {
  Data.list()
    .then(data => {
      res.render('main', { data: data });
    })
    .catch(erro => {
      res.render('error',{error: erro, message: "Error downloading all data..."})
    })
});


/* GET done task. */
router.get('/edit/:taskID', function(req, res, next) {
  var date = new Date().toISOString().substring(0, 16)
  Data.done(req.params.taskID)
    .then(data => {
      res.render('info', { date: date, text: "Task done!" });
    })
    .catch(erro => {
      res.render('error',{error: erro, message: "Error downloading all data..."})
    })
});


/* GET delete task. */
router.get('/delete/:taskID', function(req, res, next) {
  var date = new Date().toISOString().substring(0, 16)
  Data.delete(req.params.taskID)
    .then(data => {
      res.render('info', { date: date, text: "Task removed from your done tasks!" });
    })
    .catch(erro => {
      res.render('error',{error: erro, message: "Error downloading all data..."})
    })
});


// POST new task. */
router.post('/', (req, res, next) => {
  var date = new Date().toISOString().substring(0, 16)
  if(req.body && req.body['task'] != '' && req.body['author'] != '' && req.body['date'] != ''){
    req.body['status'] = 'todo' 

    Data.add(req.body)
      .then(task => {
        res.render('info', {date: date, text: "Task added!"})
      })
      .catch(erro => {
        res.render('error', {error: erro, message: "Erro na alteração do registo de aluno"})
      })
  }

  else
    res.render('info', {date: date, text: "Couldn't add task!"})
})


module.exports = router;