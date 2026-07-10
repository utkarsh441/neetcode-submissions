class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj(n + 1);
        vector<int>store(n + 1, 0);
        for(int i = 0; i < trust.size(); i++) {
            int a = trust[i][0], b = trust[i][1];
            adj[a].push_back(b);
            store[b]++;
        }
        int ans = -1;
        for(int i = 1; i <= n; i++) {
            if(store[i] == n - 1 && adj[i].size() == 0) {
                if(ans == -1) ans = i;
                else return -1;
            }
        }
        return ans;
    }
};