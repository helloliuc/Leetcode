#include <vector>
using namespace std;
class Solution {
private:
    //void flood(int row, int col, int n, int m, vector<vector<bool>> &visit) {
    void flood(int row, int col, int n, int m, bool* visit, vector<vector<char>> &grid) {
        int mv[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        for(int i=0; i<4;i++) {
            int x=row+mv[i][0], y=col+mv[i][1];
            if(x < 0 || x >=n || y < 0 || y >= m)   continue;
            if(!visit[x*m+y] && grid[x][y] == '1') {
                visit[x*m+y] = true;
                flood(x, y, n, m, visit, grid);
            }
        }
    }
    bool* visit;
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }

        int n = grid.size(), m = grid[0].size();
        //vector<vector<bool>> visit(n, vector<bool>(m, false));

        visit = new bool[n*m];
        memset(visit, false, sizeof(visit));
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m;j++) {
                if(!visit[i*m+j] && grid[i][j] == '1') {
                    ans++;
                    visit[i*m+j] = true;
                    flood(i, j, n, m, visit, grid);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    char abc[] = "abcj";
    vector<char> a(abc, abc+3);

    vector<vector<char>> grid = vector
    s.numIslands(grid);
    return 0;
}
