#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//structure representing trie node
struct TrieNode {
	std::map<char, TrieNode*> children;
	bool isEndOfWord;
};
TrieNode* root = new TrieNode();

TrieNode* getNewTrieNode() {
	TrieNode* node = new TrieNode();
	node->isEndOfWord = false;
	return node;
}

void insert(string word) {
	if (root == nullptr)
		root = getNewTrieNode();
	TrieNode* temp = root;
	for (unsigned int i = 0; i < word.size(); i++) {
		char x = word[i];
		if (temp->children.find(x) == temp->children.end())
			temp->children[x] = getNewTrieNode();
		temp = temp->children[x];
	}
	temp->isEndOfWord = true;
}

bool search(string word) {
	if (root == nullptr)
		return false;
	TrieNode* temp = root;
	for (unsigned int i = 0; i < word.size(); i++) {
		temp = temp->children[word[i]];
		if (temp == nullptr)
			return false;
	}
	return temp->isEndOfWord;
}

bool isLastWord(TrieNode* root) {
	if (root->children.size() == 0)return true;
	else return false;
}


//Recursive functions to print autosuggestions for the give prefix
void Suggestions(TrieNode* temp, string prefix) {
	if (temp->isEndOfWord) {
		cout << prefix << endl;
	}
	if (isLastWord(temp))
		return;
	for (auto it = temp->children.begin(); it != temp->children.end(); it++) {
		if (it->first) {
			prefix.push_back(it->first);
			Suggestions(temp->children[it->first], prefix);
			prefix.pop_back();
		}
	}
}

int printAutoSuggestions(string query) {
	TrieNode* temp = root;
	for (unsigned int i = 0; i < query.size(); i++) { //Checks if prefix is present or not
		if (temp->children.find(query[i]) == temp->children.end())
			return 0;
		temp = temp->children[query[i]];
	}

	bool isWord = temp->isEndOfWord; //Checks if the prefix is present as a word
	bool isLast = isLastWord(temp); //checks if the prefix is the last node of the tree

	//If prefix is present as a word, but
	// there is no subtree below the last
	// matching node.
	if (isWord && isLast) {
		cout << query << endl;
		return -1;
	}

	if (!isLast) {
		string prefix = query;
		Suggestions(temp, prefix);
		return 1;
	}
	return 0;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("englishwords.dic", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string line;
	while (cin >> line) {
		insert(line);
	}

	int result = printAutoSuggestions("abc");
	if (result == -1)
		cout << "No other strings found with this match\n";
	else if (result == 0)
		cout << "No string found with this prefix\n";
	return 0;
}