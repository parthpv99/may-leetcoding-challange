/* Implement a trie with insert, search, and startsWith methods.

Example:
	Trie trie = new Trie();
	trie.insert("apple");
	trie.search("apple");   // returns true
	trie.search("app");     // returns false
	trie.startsWith("app"); // returns true
	trie.insert("app");   
	trie.search("app");     // returns true

Note:
-> You may assume that all inputs are consist of lowercase letters a-z.
-> All inputs are guaranteed to be non-empty strings.
*/

/*
To learn about trie(prefix tree): https://medium.com/basecs/trying-to-understand-tries-3ec6bede0014
*/

class Node{    
public:
    bool isPresent;
    Node *child[26];
    Node() {
        this->isPresent = false;
        for(int i=0;i<26;i++)
            this->child[i] = NULL;
    }
};

class Trie {
private:
    Node* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
        root->isPresent = true;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* currentNode = root;
        for(int i=0;i<word.length();i++) {
            int letterPosition = word[i] - 'a';
            if(!currentNode->child[letterPosition])
                currentNode->child[letterPosition] = new Node();
            currentNode = currentNode->child[letterPosition];
        }
        currentNode->isPresent = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* currentNode = root;
        for(int i=0;i<word.length();i++) {
            int letterPosition = word[i] - 'a';
            if(!currentNode->child[letterPosition])
                return false;
            currentNode = currentNode->child[letterPosition];
        }
        if(!currentNode->isPresent)
            return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* currentNode = root;
        for(int i=0;i<prefix.length();i++) {
            int letterPosition = prefix[i] - 'a';
            if(!currentNode->child[letterPosition])
                return false;
            currentNode = currentNode->child[letterPosition];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */