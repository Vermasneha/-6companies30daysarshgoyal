class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxLength = 1;
        int startIdx = 0;
        unordered_map<int, int> frequency;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (frequency.find(nums[i]) == frequency.end()) {
                frequency[nums[i]] = 1;
            } else {
                frequency[nums[i]] += 1;
                
                if (frequency[nums[i]] > k) {
                    // Move the start index to the right until the count of the current number becomes <= k
                    while (nums[startIdx] != nums[i]) {
                        frequency[nums[startIdx]] -= 1;
                        startIdx += 1;
                    }
                    startIdx += 1;
                    frequency[nums[i]] -= 1;
                }
            }
            maxLength = max(maxLength, i - startIdx + 1);
        }
        return maxLength;
    }
};
