class Solution
{
public:
    map<vector<int>, int> dp;
    int t(vector<int> &p, vector<vector<int>> &s, vector<int> &n)
    {
        bool b = 1;
        if (dp.find(n) != dp.end())
            return dp[n];

        for (auto i : n)
            if (i != 0)
                b = 0;
        if (b)
            return 0;

        int x = INT_MAX;
        for (auto i : s)
        {
            vector<int> g = n;
            bool bn = 1;
            for (int j = 0; j < i.size() - 1; j++)
                if (i[j] > g[j])
                    bn = 0;
                else
                    g[j] -= i[j];

            if (bn)
                x = min(x, i[i.size() - 1] + t(p, s, g));
        }

        vector<int> g = n;
        int y = 0;
        for (int j = 0; j < p.size(); j++)
        {
            y += n[j] * p[j];
            g[j] = 0;
        }

        x = min(x, y + t(p, s, g));

        return dp[n] = x;
    }
    int shoppingOffers(vector<int> &p, vector<vector<int>> &s, vector<int> &n)
    {
        return t(p, s, n);
    }
};
