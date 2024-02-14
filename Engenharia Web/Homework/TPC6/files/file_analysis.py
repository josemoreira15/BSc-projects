import json

file = open('people.json')

data = json.load(file)
file.close()

for elem in data['pessoas']:
    elem.pop('id')
    if 'descrição' in elem:
        elem['descricao'] = elem.pop('descrição')
    if 'CC' in elem:
       elem['_id'] = elem.pop('CC') 
    else:
        elem['_id'] = elem.pop('BI')

final = open('people_readable.json',"w")
json.dump(data['pessoas'], final, indent = 2)
final.close()
