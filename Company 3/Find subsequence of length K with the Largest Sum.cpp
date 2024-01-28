class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>temp = nums, ans; unordered_map<int,int>m;
        sort(temp.begin(), temp.end(), greater<int>());
        for(int i=0; i<k; i++){
            m[temp[i]]++;
        }
        for(int &a:nums){
            if(m.find(a) != m.end()) {
                ans.push_back(a), m[a]--;
                if(m[a] == 0) m.erase(a); 
            }
        }
        return ans;
    }
};
