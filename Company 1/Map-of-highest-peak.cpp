class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<vector<int>> ans(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                q.push({{i,j},0});
                vis[i][j]=1;
                    
                }
            }
        }
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int height = q.front().second;
            ans[row][col]=height;
            q.pop();
            for(int i=0;i<4;i++){
                int neigrow = row + drow[i];
                int neigcol = col + dcol[i];
                if(neigrow <n && neigrow >=0 && neigcol<m && neigcol>=0 && vis[neigrow][neigcol]==0){
                    vis[neigrow][neigcol]=1;
                    q.push({{neigrow,neigcol},height+1});
                }
            }
        }
        return ans;
    }
};
