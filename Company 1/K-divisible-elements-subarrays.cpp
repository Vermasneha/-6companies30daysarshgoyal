class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int n = nums.size();
        unordered_set<string>hashing;

        for(int i = 0; i < n; i++) {
            string hash = "";
            int count = 0;
            for(int j = i; j < n; j++) {
                hash += (nums[j] + '0');
                if(nums[j] % p == 0) {
                    count++;
                }
                if(count > k) {
                    break;
                }
                hashing.insert(hash);
            }
        }

        return hashing.size();

    }
};
