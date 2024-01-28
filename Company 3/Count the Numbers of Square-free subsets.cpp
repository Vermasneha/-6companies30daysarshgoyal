#include <vector>
#include <algorithm>

class Solution {
private:
    const int MOD = 1000000007;
    const int primeFactors[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

public:
    int squareFreeSubsets(std::vector<int>& nums) {
        std::vector<int> squareFreeBitmaps;
        // Create a vector of bitmaps for square-free numbers
        for (int num : nums) {
            if (isSquareFree(num)) {
                squareFreeBitmaps.push_back(convertToBitmap(num));
            }
        }

        // Initialize memoization table for dynamic programming
        std::vector<std::vector<int>> dp(squareFreeBitmaps.size() + 1, std::vector<int>(1 << 10, -1));

        // Start the recursive function to count subsets
        return countSubsets(0, 0, dp, squareFreeBitmaps);
    }

    // Recursive function to count subsets using bitmasking
    int countSubsets(int idx, int bitmask, std::vector<std::vector<int>>& dp, const std::vector<int>& squareFreeBitmaps) {
        if (idx >= squareFreeBitmaps.size()) {
            return 0;
        }

        // If the result is already memoized, return it
        if (dp[idx][bitmask] >= 0) {
            return dp[idx][bitmask];
        }

        // Current square-free bitmap
        int currentBitmap = squareFreeBitmaps[idx];
        // Count subsets without including the current bitmap
        int count = countSubsets(idx + 1, bitmask, dp, squareFreeBitmaps);

        // If the current bitmap is not overlapping with the existing ones, include it
        if ((bitmask & currentBitmap) == 0) {
            count = (count + 1 + countSubsets(idx + 1, bitmask | currentBitmap, dp, squareFreeBitmaps)) % MOD;
        }

        // Memoize the result and return
        dp[idx][bitmask] = count;
        return count;
    }

    // Convert a number to a bitmap based on its prime factors
    int convertToBitmap(int num) {
        int bitmap = 0;
        for (int i = 0; i < 10; ++i) {
            if (num % primeFactors[i] == 0) {
                bitmap += 1 << i;
            }
        }
        return bitmap;
    }

    // Check if a number is square-free
    bool isSquareFree(int num) {
        for (int pf : primeFactors) {
            if (num % (pf * pf) == 0) {
                return false;
            }
        }
        return true;
    }
};
