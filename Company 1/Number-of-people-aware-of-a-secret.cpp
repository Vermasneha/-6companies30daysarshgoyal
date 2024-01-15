class Solution {
public:
    int mod = 1e9+7;

    int find(int currDay, int remainDay,int delay, int forget, int n, vector<vector<int>> &dp){

        if(currDay>n) return remainDay>=0?1:0;

        if(remainDay<=0) return 0;

        if(dp[currDay][remainDay]!=-1) return dp[currDay][remainDay];

        int ans = 0;

        ans += find(currDay+delay, forget-delay, delay, forget, n,dp)%mod;
        ans += find(currDay+1, remainDay-1, delay, forget, n,dp)%mod;

        return dp[currDay][remainDay] = ans%mod;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<vector<int>> dp(n+delay+1, vector<int>(n, -1));

        int ans = find(1+delay, forget-delay, delay, forget, n, dp);
        return ans;
    }
};
