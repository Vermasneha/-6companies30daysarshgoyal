#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        for (const auto& query : queries) {
            int k = query[0];
            int trim = query[1];

            priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;

            for (int j = 0; j < nums.size(); j++) {
                pq.push({nums[j].substr(nums[j].size() - trim), j});
            }

            int idx;
            while (!pq.empty() && k--) {
                idx = pq.top().second;
                pq.pop();
            }

            ans.push_back(idx);
        }

        return ans;
    }
};
