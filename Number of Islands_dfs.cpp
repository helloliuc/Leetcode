class Solution {
public:
    void dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<char>> &grid) {
        if(vis[x][y] == true) {
            return;
        }
        vis[x][y] = true;
        int mv[4][2] = {-1,0, 1, 0, 0, 1, 0, -1};
        for(int i=0; i<4;i++) {
            int newx=x+mv[i][0], newy=y+mv[i][1];
            if(newx >=0 && newx < grid.size() && newy >=0 && newy < grid[0].size() && grid[newx][newy] == '1') {
                dfs(newx, newy, vis, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] == false && grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return ans;
    }
};
