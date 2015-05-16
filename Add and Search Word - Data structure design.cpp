struct NODE {
    NODE *next[26];
    bool finish;
    NODE() {
        memset(next, 0, sizeof(next));
        finish = false;
    }
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        NODE *cur = root;
        for(int i=0; i<word.length();i++) {
            if(cur -> next[word[i]-'a'] == NULL) {
                cur -> next[word[i] - 'a'] = new NODE();
            }
            cur = cur->next[word[i] - 'a'];
        }
        cur -> finish = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        search_helper(word, root, 0);
    }

    bool search_helper(string &word, NODE *cur, int pos) {
        if(pos == word.length()) return cur->finish;
        if(word[pos] != '.') {
            if(cur -> next[word[pos]-'a'] == NULL)  return false;
            else return search_helper(word, cur->next[word[pos]-'a'], pos+1);
        }
        else {
            for(int i=0; i<26; i++) {
                if(cur->next[i] != NULL) {
                    if(search_helper(word, cur->next[i], pos+1) == true) {
                        return true;
                    }
                }
            }
            return false;
        }
    }

    WordDictionary() {
        root = new NODE();
    }

    private:
    NODE *root;

};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
