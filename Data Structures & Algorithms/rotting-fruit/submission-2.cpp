class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>>q;
        int total = 0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int time = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) total++;
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        if(total == 0) return 0;
        while(!q.empty()) {
            if(total == 0) return time;
            time++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for(int i = -1; i <= 1; i += 2) {
                    if(x + i >= 0 && x + i < n && grid[i + x][y] == 1 && !vis[x + i][y]) {
                        vis[i + x][y] = 1;
                        q.push({x + i, y});
                        total--;
                    }
                }

                for(int i = -1; i <= 1; i += 2) {
                    if(y + i >= 0 && y + i < m && grid[x][y + i] == 1 && !vis[x][y + i]) {
                        vis[x][y + i] = 1;
                        q.push({x, y + i});
                        total--;
                    }
                }
            }
        }
        return -1;
    }
};
