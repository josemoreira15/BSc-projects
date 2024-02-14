import json 
import requests

file = open('../files/people_readable.json')  
data = json.load(file)

url = 'http://localhost:7777/people'

for elem in data:
    post = requests.post(url, json = elem)
