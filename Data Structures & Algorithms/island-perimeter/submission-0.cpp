class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>&grid, vector<vector<int>>&vis) {
        vis[r][c] = 1;
        int ans = 4;
        for(int i = -1; i <= 1; i += 2) {
            if(r + i >= 0 && r + i < grid.size()) {
                if(grid[r + i][c] == 1) {
                    ans--;
                    if(!vis[r + i][c]) ans += dfs(r + i, c, grid, vis);
                }
            }
        }

        for(int i = -1; i <= 1; i += 2) {
            if(c + i >= 0 && c + i < grid[0].size()) {
                if(grid[r][c + i] == 1) {
                    ans--;
                    if(!vis[r][c + i]) ans += dfs(r, c + i, grid, vis);
                }
                
            }
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) ans += dfs(i, j, grid, vis);
            }
        }
        return ans;
    }
};