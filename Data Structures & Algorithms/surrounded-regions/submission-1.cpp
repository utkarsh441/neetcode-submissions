class Solution {
public:
    bool dfs(int r, int c, vector<vector<char>>&board, vector<vector<int>>&vis) {
        int n = board.size(), m = board[0].size();
        if(r == 0 || r == n - 1 || c == 0 || c == m - 1) return false;
        vis[r][c] = 1;
        bool p = true;
        for(int i = -1; i <= 1; i += 2) {
            if(r + i >= 0 && r + i < n &&
            !vis[r + i][c] && board[r + i][c] == 'O') {
                bool ans = dfs(r + i, c, board, vis);
                p = p && ans;
            }
        }


        for(int i = -1; i <= 1; i += 2) {
            if(c + i >= 0 && c + i < m &&
            !vis[r][c + i] && board[r][c + i] == 'O') {
               bool ans = dfs(r, c + i, board, vis);
               p = p && ans;
            }
        }
        return p;
    }

    void bb(int r, int c, vector<vector<char>>&board, vector<vector<int>>&vis) {
        int n = board.size(), m = board[0].size();
        vis[r][c] = 1;
        board[r][c] = 'X'; 
        for(int i = -1; i <= 1; i += 2) {
            if(r + i >= 0 && r + i < n &&
            !vis[r + i][c] && board[r + i][c] == 'O') bb(r + i, c, board, vis);
        }


        for(int i = -1; i <= 1; i += 2) {
            if(c + i >= 0 && c + i < m &&
            !vis[r][c + i] && board[r][c + i] == 'O') bb(r, c + i, board, vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>>vis1(n, vector<int>(m, 0)), vis2(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis1[i][j] && board[i][j] == 'O') {
                    bool x = dfs(i, j, board, vis1);
                    if(x) bb(i, j, board, vis2);
                }
            }
        }
    }
};
