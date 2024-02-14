var express = require('express');
var router = express.Router();
var Planta = require('../controllers/planta')


router.get('/plantas', function(req, res) {
  if (req.query.especie != undefined){
    // GET /plantas?especie=EEEE: devolve a lista dos registos correspondentes à espécie EEEE
    Planta.getPlantasEspecie(req.query.especie)
      .then(dados => res.status(200).json(dados))
      .catch(erro => res.status(520).json({erro: erro, mensagem: "Não consegui a lista de plantas dessa espécie!"}))
  }

  else if (req.query.implant != undefined){
    // GET /plantas?implant=AAA: devolve a lista dos registos com implantação AAA
    Planta.getPlantasImplantacao(req.query.implant)
      .then(dados => res.status(200).json(dados))
      .catch(erro => res.status(520).json({erro: erro, mensagem: "Não consegui a lista de plantas dessa implantação!"}))
  }

  else {
    // GET /plantas: devolve uma lista com todos os registos
    Planta.list()
      .then(dados => res.status(200).json(dados))
      .catch(erro => res.status(520).json({erro: erro, mensagem: "Não consegui a lista de plantas!"}))
  }
});


// GET /plantas/freguesias: devolve a lista de freguesias ordenada alfabeticamente e sem repetições
router.get('/plantas/freguesias', function(req, res) {
  Planta.getFreguesias()
    .then(dados => res.status(200).json(dados))
    .catch(erro => res.status(520).json({erro: erro, mensagem: "Não consegui a lista de freguesias!"}))
});


// GET /plantas/especies: devolve a lista das espécies vegetais ordenada alfabeticamente e sem repetições
router.get('/plantas/especies', function(req, res) {
  Planta.getEspecies()
    .then(dados => res.status(200).json(dados))
    .catch(erro => res.status(520).json({erro: erro, mensagem: "Não consegui a lista de espécies!"}))
});


// GET /plantas/:id: devolve o registo com identificador id;
router.get('/plantas/:id', function(req, res) {
  Planta.getPlanta(req.params.id)
    .then(dados => res.status(200).json(dados))
    .catch(erro => res.status(520).json({erro: erro, mensagem: "Não consegui obter essa planta!"}))
});


// POST /plantas: acrescenta um registo novo à BD
router.post('/plantas', function(req, res) {
  Planta.postPlanta(req.body)
    .then(dados => res.status(200).json(dados))
    .catch(erro => res.status(520).json({erro: erro, mensagem: "Não consegui adicionar a planta!"}))
});


// DELETE /plantas/:id: elimina da BD o registo com o identificador id
router.delete('/plantas/:id', function(req, res) {
  Planta.deletePlanta(req.params.id)
    .then(dados => res.status(200).json(dados))
    .catch(erro => res.status(520).json({erro: erro, mensagem: "Não consegui apagar a planta!"}))
});


module.exports = router;