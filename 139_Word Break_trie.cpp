struct TRIE {
    bool finish;
    struct TRIE *nxt[128];
}trie[10000];
int trie_cnt;

void init_trie(unordered_set<string>& wordDict) {
    memset(trie,  0, sizeof(trie));
    trie_cnt = 1;
    for(auto it = wordDict.begin(); it != wordDict.end(); it++) {
        int len = (*it).length();
        TRIE *pt = &trie[0];
        for(int j = 0; j < len; j++) {
            if(pt->nxt[(*it)[j]] == NULL) {
                pt->nxt[(*it)[j]] = &trie[trie_cnt++];
            }
            pt = pt->nxt[(*it)[j]];
        }
        pt->finish = true;
    }
}

void query_trie(string &s, int pos, int len, vector<bool> &flag) {
    TRIE *pt = &trie[0];
    while( pos < len && pt->nxt[s[pos]] != NULL) {
        if(pt->nxt[s[pos]]->finish == true) {
            flag[pos+1] = true;
        }
        
        pt = pt->nxt[s[pos]];
        pos++;
    }
}

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        init_trie(wordDict);
        vector<bool> flag(s.length()+1, false);
        flag[0] = true;
        for(int i = 0; i < s.length(); i++) {
            if(flag[i]) {
                query_trie(s, i, s.length(), flag);
                if(flag[s.length()]) {
                    return true;
                }
            }
        }
        return false;
    }
};
