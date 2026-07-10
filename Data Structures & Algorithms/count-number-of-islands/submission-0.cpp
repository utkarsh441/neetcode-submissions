class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>&grid, vector<vector<int>>&vis) {
        vis[r][c] = 1;
        for(int i = -1; i <= 1; i += 2) {
            if(r + i >= 0 && r + i < grid.size() && 
            grid[r + i][c] == '1' && !vis[r + i][c]) dfs(r + i, c, grid, vis);
        }

        for(int i = -1; i <= 1; i += 2) {
            if(c + i >= 0 && c + i < grid[0].size() && 
            grid[r][c + i] == '1' && !vis[r][c + i]) dfs(r, c + i, grid, vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    ans ++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return ans;
    }
};
