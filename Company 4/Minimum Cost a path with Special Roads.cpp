class Solution {
public:
    struct HashPair {
        template <class T1, class T2>
        size_t operator()(const std::pair<T1, T2>& p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);

            if (hash1 != hash2) {
                return hash1 ^ hash2;
            }

            return hash1;
        }
    };

    int minimumCost(std::vector<int>& s, std::vector<int>& t, std::vector<std::vector<int>>& a) {
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> pq;
        std::unordered_map<std::pair<int, int>, int, HashPair> costMap;

        pq.push({0, s[0], s[1]});
        costMap[{s[0], s[1]}] = 0;

        int cx, cy, cz;

        while (!pq.empty()) {
            int sx = pq.top()[1];
            int sy = pq.top()[2];
            int c = pq.top()[0];

            pq.pop();

            if (sx == t[0] && sy == t[1]) return c;

            pq.push({c + abs(sx - t[0]) + abs(sy - t[1]), t[0], t[1]});

            for (int i = 0; i < a.size(); i++) {
                if (a[i][2] == sx && a[i][3] == sy) continue;

                cx = abs(sx - a[i][0]);
                cy = abs(sy - a[i][1]);
                cz = a[i][4];

                auto destination = std::make_pair(a[i][2], a[i][3]);

                if (costMap[destination] == 0 || costMap[destination] > c + cx + cy + cz) {
                    costMap[destination] = c + cx + cy + cz;
                    pq.push({c + cx + cy + cz, a[i][2], a[i][3]});
                }
            }
        }

        return 0;
    }
};
