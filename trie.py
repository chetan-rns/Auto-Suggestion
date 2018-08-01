#File to hold the trie object
from search_trie import *
fhand=open("englishwords.dic","r")
trie=Trie()
for line in fhand:
    trie.insert(line)
#prefix=input("Enter the prefix\n")
#array_of_words_that_begin_with = trie.autocomplete(str(prefix))
#print(array_of_words_that_begin_with)

