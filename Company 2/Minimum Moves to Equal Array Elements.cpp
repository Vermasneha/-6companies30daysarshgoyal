class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        // Find the median of the sorted nums array
        std::sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        // Calculate the sum of absolute differences between each element and the median
        int moves = 0;
        for (int num : nums) {
            moves += std::abs(num - median);
        }

        return moves;
    }
};
