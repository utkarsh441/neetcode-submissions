class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>>q;
        int curr = 0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                int r = p[0], c = p[1];
                grid[r][c] = curr;
                for(int i = -1; i <= 1; i += 2) {
                    if(r + i >= 0 && r + i < n && !vis[r + i][c]) {
                        if(grid[r + i][c] == -1) continue;
                        vis[r + i][c] = 1;
                        q.push({r + i, c});
                    }
                }

                for(int i = -1; i <= 1; i += 2) {
                    if(c + i >= 0 && c + i < m && !vis[r][c + i]) {
                        if(grid[r][c + i] == -1) continue;
                        vis[r][c + i] = 1;
                        q.push({r, c + i});
                    }
                }
            }
            curr++;
        }
    }
};
