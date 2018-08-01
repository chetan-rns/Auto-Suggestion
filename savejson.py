#To convert the trie node to a json object
from trie import *
import json

def writeToJSONFile(path, fileName, data):
    filePathNameWExt = './' + path + '/' + fileName + '.json'
    with open(filePathNameWExt, 'w') as fp:
        json.dump(data, fp)

#writeToJSONFile('./','jsontrie',trie.children)

#def convert_to_json(trie):
#	for key in trie.children:
'''d={}
def get_objects(node):
	if node is None:
		return d
	for key,value in node.children.items():
		d[key]=get_objects(value)		
jtrie={}
for key,value in trie.children.items():
	jtrie[key]=get_objects(value)
print(jtrie)'''
'''k=trie.children['a']
def getValue(k):
	while(k is not None):
		for key,value in k.children.items():
			print(key," ",getValue(value))
	return 
d=str(trie.children.items())
print(d)
json_str=json.loads(d)
print(json_str)'''
print(trie.children.items())