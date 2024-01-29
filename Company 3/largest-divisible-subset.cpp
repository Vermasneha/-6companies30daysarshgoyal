class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(0));
        int mxSize=n-1;
        for(int i = 0; i<n; i++) dp[i].push_back(nums[i]);
        for(int i = n-1; i>=0; i--){
            for(int j = i+1; j<n; j++){
                if((nums[i]%nums[j]==0 || nums[j]%nums[i]==0) && dp[i].size()<dp[j].size()+1){
                    dp[i].clear();
                    dp[i].push_back(nums[i]);
                    for(int &num : dp[j]) dp[i].push_back(num);
                    if(dp[i].size()>dp[mxSize].size()) mxSize=i;
                }
            }
        }
        return dp[mxSize];
    }
};
