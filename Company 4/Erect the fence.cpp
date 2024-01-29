class Solution { 
public:
    bool ori(vector<int> &a, vector<int> &b, vector<int> &c){
        return (c[1] - b[1])*(b[0] - a[0]) < (b[1] - a[1])*(c[0] - b[0]); 
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = trees.size();
        if(n <= 3) return trees; 
        sort(trees.begin(), trees.end());
        vector<int> vis(n, 0), uh, lh;
        for(int i = 0; i < n; i++){
            // upper hull
            int szu = uh.size();
            while(szu >= 2 and ori(trees[uh[szu-2]], trees[uh[szu-1]], trees[i])) 
                vis[uh[szu-1]]--, szu--, uh.pop_back();
            uh.push_back(i);
            vis[i]++;
            // lower hull
            int szl = lh.size();
            while(szl >= 2 and ori(trees[lh[szl-2]], trees[lh[szl-1]], trees[n-i-1])) 
                vis[lh[szl-1]]--, szl--, lh.pop_back();
            lh.push_back(n-i-1);
            vis[n-i-1]++;
        }    
        vector<vector<int>> ch;
        for(int i = 0; i < n; i++) if(vis[i]) ch.push_back(trees[i]);
        return ch;
    }
};
