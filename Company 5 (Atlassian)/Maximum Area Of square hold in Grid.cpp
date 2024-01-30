class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, std::vector<int>& hBars, std::vector<int>& vBars) {
        // Initialize variables to store the lengths of horizontal and vertical bars
        int hLen = 1, vLen = 1, prev, temp = 1;
        
        // Sort the horizontal and vertical bars arrays
        std::sort(hBars.begin(), hBars.end());
        std::sort(vBars.begin(), vBars.end());

        // Calculate the length of consecutive horizontal bars
        prev = hBars[0];
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == prev + 1) {
                temp++;
                prev = hBars[i];
            } else {
                hLen = std::max(hLen, temp);
                temp = 1;
                prev = hBars[i];
            }
        }
        hLen = std::max(hLen, temp);
        
        // Calculate the length of consecutive vertical bars
        prev = vBars[0];
        temp = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == prev + 1) {
                temp++;
                prev = vBars[i];
            } else {
                vLen = std::max(vLen, temp);
                temp = 1;
                prev = vBars[i];
            }
        }
        vLen = std::max(vLen, temp);
        
        // Add 1 to both horizontal and vertical lengths to consider the gaps
        hLen += 1;
        vLen += 1;
        
        // Calculate and return the area of the maximum square hole
        return std::min(hLen, vLen) * std::min(hLen, vLen);
    }
};
