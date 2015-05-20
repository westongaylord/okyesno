#include <iostream>
using namespace std;

typedef struct node {
	bool isWord;
	node *children[26];
} node;


private:
	node *root;
	bool recContainsPrefix(string prefix, node *curr);
	bool recContains(string word, node *curr);

Lexicon::Lexicon() {
	node *root = new node(); 
	root->isWord = false;
	for(int i = 0; i < node->children.length(); i++) {
		node->children[i] = NULL;
	}
}

bool recContainsPrefix(string prefix, node *curr) {
	bool temp = false;
	if(prefix == "") {
		return true; 
	}
	if(curr == NULL) {
		return false;
	}
	char ch = prefix[0] - 'a';
	if(ch >= 0 && ch < 26) {
		temp = recContainsPrefix(prefix.substr(1, prefix.length()), curr->children[ch]);
	} 
	return temp;
}

bool recContains(string word, node *curr) {
	bool temp = false;
	if(curr == NULL) {
		return false;
	}
	if(word == "") {
		return curr->isWord; 
	}
	char ch = word[0] - 'a';
	if(ch >= 0 && ch < 26) {
		temp = recContainsPrefix(word.substr(1, word.length()), curr->children[ch]);
	} 
	return temp;
}


//NO ARMS LENGTH RECURSION, NEED TO PASS IN A START STAR
void addHelper(node* &root, string word) {
  if (root == NULL) {
    // create new child
    node *child = new node();
    child->isWord = false;
    for (char i = 'a'; i <= 'z'; i++) {
      child->children[i - 'a'] = NULL;
    }
    root = child;
  }
  if (word == "") {
    root->isWord = true;
    return;
  }
  if (word[0] - 'a' < 0 || word[0] - 'a' >= 26) {
    return;
  }
  char ch = word[0] - 'a';
  addHelper(root->children[ch], word.substr(1));
}



void recAdd(string word, node *curr) {
	if (word == "") {
		curr->isWord = true;
		return;
	} 
	char ch = word[0] - 'a';
	if(ch >= 0 && ch < 26) {
		if(curr->children[ch] != NULL) {
			recAdd(word.substr(1, word.length()), curr->children[ch]);
		} else {
			node *next = new node();
			next->isWord = false;
			for(int i = 0; i < node->children.length(); i++) {
				next->children[i] = NULL;
			}
			curr->children[ch] = next;
			recAdd(word.substr(1, word.length()), curr->children[ch]);
		}
	}
}

bool containsPrefix(string prefix) {
	return recContainsPrefix(prefix, root);
}

bool contains(string word) {
	return recContains(word, root);
}

void add(string word) {
	if(curr == NULL) return;
	recAdd(word, node *curr);
}

void recPrint(string curr, node * root) {
	if(root == NULL) return;
	if(root->isWord) cout << curr;
	for(int i = 0; i < 26; i++) {
		curr = 'a'+i;
		recPrint(curr, root->children[i]);
	}
}

void printAll() {
	recPrint("", root);
	
}

void unionWith(Lexicon& other) {
	foreach (string word in other)	{
		if(!contains(word)) {
			add(word);
		}
	}
}

int main {
	return 0;
}