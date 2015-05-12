//2A
//1CE
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        memset(nxt, 0, sizeof(nxt));
        isEnd = false;
    }
    TrieNode *nxt[26];
    bool isEnd;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *p = root;
        for(int i=0; i<s.length();i++) {
            if(p -> nxt[s[i] - 'a'] == NULL) {
                p -> nxt[s[i] - 'a'] = new TrieNode();
            }
            p = p->nxt[s[i] - 'a'];
        }
        p -> isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *p = root;
        for(int i=0; i<key.length(); i++) {
            if(p -> nxt[key[i] - 'a'] == NULL) {
                return false;
            }
            p = p->nxt[key[i] - 'a'];
        }
        if(p -> isEnd) {    return true;    }
        else    {   return false;   }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(int i=0; i<prefix.length(); i++) {
            if(p -> nxt[prefix[i] - 'a'] == NULL) {
                return false;
            }
            p = p->nxt[prefix[i] - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
