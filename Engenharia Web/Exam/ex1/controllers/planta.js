var Planta = require('../models/planta')


// GET /plantas: devolve uma lista com todos os registos
module.exports.list = () => {
    return Planta
            .find()
            .then(resposta => {
                return resposta
            })
            .catch(erro => {
                return erro
            })
}


// GET /plantas/:id: devolve o registo com identificador id
module.exports.getPlanta = id => {
    return Planta.findOne({_id: id})
            .then(resposta => {
                return resposta
            })
            .catch(erro => {
                return erro
            })
}


// GET /plantas?especie=EEEE: devolve a lista dos registos correspondentes à espécie EEEE
module.exports.getPlantasEspecie = especie => {
    return Planta.find({Especie: especie})
            .then(resposta => {
                return resposta
            })
            .catch(erro => {
                return erro
            })
}


// GET /plantas?implant=AAA: devolve a lista dos registos com implantação AAA
module.exports.getPlantasImplantacao = implantacao => {
    return Planta.find({Implantacao: implantacao})
            .then(resposta => {
                return resposta
            })
            .catch(erro => {
                return erro
            })
}


// GET /plantas/freguesias: devolve a lista de freguesias ordenada alfabeticamente e sem repetições
module.exports.getFreguesias = () => {
    return Planta.distinct("Freguesia")
            .sort()
            .then(resposta => {
                return resposta
            })
            .catch(erro => {
                return erro
            })
}


// GET /plantas/especies: devolve a lista das espécies vegetais ordenada alfabeticamente e sem repetições
module.exports.getEspecies = () => {
    return Planta.distinct("Especie")
            .sort()
            .then(resposta => {
                return resposta
            })
            .catch(erro => {
                return erro
            })
}


// POST /plantas: acrescenta um registo novo à BD
module.exports.postPlanta = planta => {
    return Planta.create(planta)
            .then(resposta => {
                return resposta
            })
            .catch(erro => {
                return erro
            })
}


// DELETE /plantas/:id: elimina da BD o registo com o identificador id
module.exports.deletePlanta = id => {
    return Planta.deleteOne({_id: id})
            .then(resposta => {
                return resposta
            })
            .catch(erro => {
                return erro
            })
}