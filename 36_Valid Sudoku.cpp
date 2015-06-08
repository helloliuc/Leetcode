class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                vector<bool> vis(10, false);
                for(int k=0; k<3; k++) {
                    for(int l=0; l<3; l++) {
                        int row = i * 3 + k;
                        int col = j * 3 + l;
                        if(board[row][col] == '.') continue;
                        if(vis[board[row][col]] == true) {
                            return false;
                        }
                        vis[board[row][col]] = true;
                    }
                }
            }
        }
        for(int i=0; i<9; i++) {
            vector<bool> vis(10, false);
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;
                if(vis[board[i][j]] == true) {
                    return false;
                }
                vis[board[i][j]] = true;
            }
        }
        for(int j=0; j<9; j++) {
            vector<bool> vis(10, false);
            for(int i=0; i<9; i++) {
                if(board[i][j] == '.') continue;
                if(vis[board[i][j]] == true) {
                    return false;
                }
                vis[board[i][j]] = true;
            }
        }
        return true;
    }
};
