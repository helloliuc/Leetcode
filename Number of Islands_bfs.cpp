class Solution {
public:
    void bfs(int x, int y, vector<vector<bool>> &vis, vector<vector<char>> &grid) {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));    vis[x][y] = true;
        int mv[4][2] = {1,0,-1,0,0,1,0,-1};
        while(!q.empty()) {
            pair<int, int> front = q.front();   q.pop();
            for(int i=0; i<4;i++) {
                int newx=front.first + mv[i][0], newy = front.second + mv[i][1];
                if(newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && vis[newx][newy] == false && grid[newx][newy] == '1') {
                    vis[newx][newy] = true;
                    q.push(make_pair(newx, newy));
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1' && vis[i][j] == false) {
                    ans++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return ans;
    }
};
