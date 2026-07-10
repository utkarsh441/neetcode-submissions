class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>&grid, vector<vector<int>>&vis) {
        vis[r][c] = 1;
        int len = 1;
        for(int i = -1; i <= 1; i += 2) {
            if(r + i >= 0 && r + i < grid.size() && grid[r + i][c] == 1 && !vis[r + i][c]) len += dfs(r + i, c, grid, vis);
        }

        for(int i = -1; i <= 1; i += 2) {
            if(c + i >= 0 && c + i < grid[0].size() && grid[r][c + i] == 1 && !vis[r][c + i]) len += dfs(r, c + i, grid, vis);
        }
        return len;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) ans = max(ans, dfs(i, j, grid, vis));
            }
        }
        return ans;
    }
};
