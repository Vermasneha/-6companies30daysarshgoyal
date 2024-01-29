class Solution {
public:
    std::vector<std::vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        // Create a vector to store distances and coordinates
        std::vector<std::vector<int>> distances;

        // Calculate distances and store coordinates
        for (int y = 0; y < R; ++y) {
            for (int x = 0; x < C; ++x) {
                distances.push_back({abs(r0 - y) + abs(c0 - x), y, x});
            }
        }

        // Sort the distances based on the first element (distance)
        std::sort(distances.begin(), distances.end(), [](const auto& p1, const auto& p2) {
            return p1[0] < p2[0];
        });

        // Extract and return the coordinates from the sorted distances
        std::vector<std::vector<int>> result;
        for (const auto& dist : distances) {
            result.push_back({dist[1], dist[2]});
        }

        return result;
    }
};
