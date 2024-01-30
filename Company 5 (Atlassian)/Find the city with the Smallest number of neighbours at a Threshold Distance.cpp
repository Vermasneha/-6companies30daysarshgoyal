class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> v(n,vector<int> (n,1e9));

        for(auto it : edges){
            v[it[0]][it[1]] = it[2];
            v[it[1]][it[0]] = it[2];
        }

        for(int i = 0 ; i < n ; i++) v[i][i]=0;

        for(int via = 0 ; via < n ; via++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    v[i][j] = min(v[i][j] , v[i][via] + v[via][j]);
                }
            }
        }

        
        int maxCnt = n;
        int ans = -1;

        for(int i = 0 ; i < n ; i++){
            int cnt = 0;
            for(int j = 0 ; j < n ; j++){
                if(v[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=maxCnt){
                    maxCnt = cnt;
                    ans = i;
            }

        }

        return ans;

    }
};
