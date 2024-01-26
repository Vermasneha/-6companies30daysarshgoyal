class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& e)
    {
        sort(e.begin(),e.end(),cmp);
        vector<int> ans;
        for(int i=0;i<e.size();i++)
        {
            auto it=lower_bound(ans.begin(),ans.end(),e[i][1]);//if e[i][0] same then e[i][1] will greater;
            if(it==ans.end())
            {
                ans.push_back(e[i][1]); //get longest increasing subsequence for height although width is already sorted in increasing;
            }
            else
            {
                *it=e[i][1]; //
            }
        }
        return ans.size();
        
        
    }
};
