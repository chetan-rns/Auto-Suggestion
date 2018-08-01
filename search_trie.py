from functools import reduce
class Trie(object):
    """Class representing the trie"""
    def __init__(self):
        self.children={}
        self.isEndOfWord=False

    def add(self,char):  #Adds a character to dictionary and creates a new node 
        self.children[char]=Trie()

    def insert(self,word): #Insert a new word to the trie
        node=self
        for char in word:
            if char not in node.children:
                node.add(char)
            node=node.children[char]
        node.isEndOfWord=True
    def search(self, word): #Search for a particular word in a trie
        node = self
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.isEndOfWord


    def all_suffixes(self,prefix):
        results = set()
        if self.isEndOfWord:
            results.add(prefix)
        if not self.children: 
            return results
        return reduce(lambda a, b: a | b, [node.all_suffixes(prefix + char) for (char, node) in self.children.items()]) | results

    def autocomplete(self, prefix):
        node = self
        for char in prefix:
            if char not in node.children:
                return set()
            node = node.children[char]
        return list(node.all_suffixes(prefix))


