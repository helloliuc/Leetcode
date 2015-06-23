class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return ;
        int m = board[0].size();
        if(m == 0) return ;
        
        const int mv[4][2] = {
            -1, 0, 1, 0, 0, -1, 0, 1
        };
        
        vector<vector<bool> > v(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!v[i][j] && board[i][j] == 'O') {
                    queue<pair<int, int> > q;
                    queue<pair<int, int> > q2;
                    q.push(make_pair(i, j));
                    v[i][j] = true;
                    bool touch = false;
                    while(!q.empty()) {
                        pair<int, int> cur = q.front(); q.pop(); q2.push(cur);
                        if(cur.first == 0 || cur.first == n-1 || cur.second == 0 || cur.second == m-1) {
                            touch = true;
                        }
                        for(int k = 0; k < 4; k++) {
                            int newrow = cur.first + mv[k][0], newcol = cur.second + mv[k][1];
                            if(newrow < 0 || newrow == n || newcol < 0 || newcol == m) {
                                continue;
                            }
                            if(board[newrow][newcol] == 'O' && !v[newrow][newcol]) {
                                v[newrow][newcol] = true;
                                q.push(make_pair(newrow, newcol));
                            }
                        }
                    }
                    if(!touch) {
                        while(!q2.empty()) {
                            pair<int, int> cur = q2.front();    q2.pop();
                            board[cur.first][cur.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};
