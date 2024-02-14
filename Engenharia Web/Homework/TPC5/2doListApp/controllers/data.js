var axios = require('axios')

module.exports.list = () => {
    return axios.get("http://localhost:3000/data?_sort=date,name")
            .then(response => {
                return response.data
            })
            .catch(error => {
                return error
            })
}


module.exports.done = taskID => {
    return axios.get("http://localhost:3000/data/" + taskID)
            .then(response => {
                var data = response.data
                data['status'] = 'done'

                axios.put("http://localhost:3000/data/" + taskID, data)
                 .then(response => {
                    return response.data
                 })
                 .catch(error => {
                    return error
                 })                
            })
            .catch(error => {
                return error
            })
}


module.exports.delete = taskID => {
    return axios.delete("http://localhost:3000/data/" + taskID)
            .then(response => {
                return response.data
            })
            .catch(error => {
                return error
            })
}


module.exports.add = task => {
    if(task && task['task'] != '' && task['author'] != '' && task['date'] != ''){
        task['status'] = 'todo'

        return axios.post("http://localhost:3000/data/", task)
                .then(response => {
                    return response.data
                })
                .catch(error => {
                    return error
                })
    }
}