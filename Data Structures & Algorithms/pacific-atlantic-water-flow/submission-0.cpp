class Solution {
public:
    bool dfs(int r, int c, vector<vector<int>>&v, vector<vector<int>>&vis, 
    vector<vector<int>>&store, int flag) {
        if(!flag) {
            if(c == 0 || r == 0) return true;
        }
        else {
            if(r == v.size() - 1 || c == v[0].size() - 1) return true;
        }
        vis[r][c] = 1;
        bool ans = false;
        for(int i = -1; i <= 1; i += 2) {
            if(r + i >= 0 && r + i < v.size()) {
                if(v[r + i][c] <= v[r][c]) {
                    if(vis[r + i][c]) ans = ans || store[r + i][c];
                    else ans = ans || dfs(r + i, c, v, vis, store, flag);
                }
            }
        }

        for(int i = -1; i <= 1; i += 2) {
            if(c + i >= 0 && c + i < v[0].size()) {
                if(v[r][c + i] <= v[r][c]) {
                    if(vis[r][c + i]) ans = ans || store[r][c + i];
                    else ans = ans || dfs(r, c + i, v, vis, store, flag);
                }
            }
        }
        return store[r][c] = ans;
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>>p(n, vector<int>(m, 0)), a(n, vector<int>(m, 0));
        vector<vector<int>>pv(n, vector<int>(m, 0)), av(n, vector<int>(m, 0));

        vector<vector<int>>ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                bool a1 = pv[i][j] == 1 ? p[i][j] : dfs(i, j, v, pv, p, 0);
                bool a2 = av[i][j] == 1 ? a[i][j] : dfs(i, j, v, av, a, 1);
                if(a1 && a2)ans.push_back({i, j});
            }
        }
        return ans;
    }
};
