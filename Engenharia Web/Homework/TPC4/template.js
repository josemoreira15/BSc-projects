// template.js
// tpc4EngWeb2023: 2023-03-09
// by jmm

exports.mainPage = function(data, d){
    var pagHTML = `
    <!DOCTYPE html>
    <html>
        <head>
            <meta charset="UTF-8"/>
            <link rel="icon" href="taskicon.png"/>
            <link rel="stylesheet" href="w3.css"/>
            <title>2doListApp</title>
        </head>
        <body>
            <div class="w3-card-4">
                <header class="w3-container w3-blue">
                    <center>
                        <h2 style="text-shadow:1px 1px 0 #444"><b>2doListApp</b></h2>
                    </center>
                </header>
        
                <form class="w3-container" method="POST">
                    <fieldset>
                        <label>ID [already defined]</label>
                        <input class="w3-input w3-round" type="text" name="id" value="${data.length-55}" readonly/>
                        <br>
                        <label>Task</label>
                        <input class="w3-input w3-round" type="text" name="task"/>
                        <br>
                        <label>Author</label>
                        <select class="w3-select w3-round" name="name" style="font-size: 15px;">
                            <option value="" disabled selected>Choose your option</option>`

    for(let i=0; i < data.length ; i++)
        if (!data[i].status)
            pagHTML += `<option value="${data[i].name}">${data[i].name}</option>`
                            
    pagHTML +=         `</select> 
                        <br><br>
                        <label>Date</label>
                        <input class="w3-input w3-round" type="date" name="date"/>
                    </fieldset> 
                    <br/>
                    <button class="w3-btn w3-blue w3-mb-2" type="submit" style="position: absolute; right: 0;;">Submit Task</button>
                </form>
            </div>
            <br><br>
            <div class="w3-card-4 w3-cell-row">
                <div class="w3-container w3-cell">
                    <table class="w3-table-all">
                        <caption style="font-size: 25px; text-shadow:1px 1px 0 #444">To do tasks</caption>
                        <tr>
                            <th>Task</th><th>Author</th><th>Date</th>
                        </tr>`
    for(let i=0; i < data.length ; i++){
        if (data[i].status && data[i].status == 'todo')
            pagHTML += `<tr>
                            <td>${data[i].task}</td><td>${data[i].name}</td><td>${data[i].date}</td>
                            <td>[<a href="/edit/${data[i].id}">Done</a>]</td>
                        <tr>`    
    } 

    pagHTML +=                `</table>
                </div>
                <div class="w3-container w3-cell">
                    <table class="w3-table-all">
                        <caption style="font-size: 25px; text-shadow:1px 1px 0 #444">Done tasks</caption>
                        <tr>
                            <th>Task</th><th>Author</th><th>Date</th>
                        </tr>`

    for(let i=0; i < data.length ; i++){
        if (data[i].status && data[i].status == 'done')
            pagHTML += `<tr>
                            <td>${data[i].task}</td><td>${data[i].name}</td><td>${data[i].date}</td>
                            <td>[<a href="/delete/${data[i].id}">Delete</a>]</td>
                        </tr>`   
    }            

    pagHTML +=                `</table>
                </div>
            </div>
        </body>
    </html>`

    return pagHTML
}

exports.infoPage = function(text, d){
    var pagHTML = `
    <!DOCTYPE html>
    <html>
        <head>
            <meta charset="UTF-8"/>
            <link rel="icon" href="taskicon.png"/>
            <link rel="stylesheet" href="w3.css"/>
            <title>Information</title>
        </head>
        <body>
            <div class="w3-card-4">
                <header class="w3-container w3-blue">
                    <center>
                        <h2 style="text-shadow:1px 1px 0 #444"><b>${text}</b></h2>
                    </center>
                    <br/>
                    <button class="w3-btn w3-blue w3-mb-2" style="position: absolute; right: 0;;">
                        <a href="/">Main app</a>
                    </button>
                </header>
            </div>
            <div>
            <footer class="w3-container w3-blue">
                <h5>Generated by jmm in ${d}</h5>
            </div>
            </footer>
        </body>
    </html>`

    return pagHTML
}