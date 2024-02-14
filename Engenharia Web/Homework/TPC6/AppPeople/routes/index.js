var express = require('express');
var router = express.Router();
var Person = require('../controllers/person')

/* GET home page. */
router.get('/people', function(req, res, next) {
  Person.list()
    .then(persons => { res.json(persons); })
    .catch(erro => { res.status(601).json({erro: erro})
    })
});


router.get('/people/:idPerson', function(req, res, next) {
  Person.getPerson(req.params.idPerson)
    .then(person => { res.json(person); })
    .catch(erro => { res.status(602).json({erro: erro})
    })
});


router.post('/people', (req, res) => {
  Person.addPerson(req.body)
    .then(person => { res.status(201).json(person); })
    .catch(erro => { res.status(603).json({erro: erro})
    })
});


router.put('/people/:idPerson', (req, res) => {
  Treino.updatePerson(req.body)
    .then(person => { res.json(person); })
    .catch(erro => { res.status(604).json({erro: erro})
    })
});


router.delete('/people/:idPerson', (req, res) => {
  Person.deletePerson(req.params.idPerson)
    .then(person => { res.json(person); })
    .catch(erro => { res.status(605).json({erro: erro})
    })
});

module.exports = router;