 
class Solution {
public:
    Solution(std::vector<std::vector<int>>& rects) {
        arrays = rects;
        sum = 0;

        for (int i = 0; i < rects.size(); i++) {
            std::vector<int>& rect = rects[i];
            sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            map[sum] = i;
        }
    }

    std::vector<int> pick() {
        int c = map.upper_bound(std::rand() % sum + 1)->second;
        return pickInRect(arrays[c]);
    }

private:
    std::map<int, int> map;
    std::vector<std::vector<int>> arrays;
    int sum;

    std::vector<int> pickInRect(std::vector<int>& rect) {
        int left = rect[0], right = rect[2], bot = rect[1], top = rect[3];
        return {left + std::rand() % (right - left + 1), bot + std::rand() % (top - bot + 1)};
    }
};
