class Solution {
public:
    string findPermutation(string S) {
        int n = S.size();
        string result;
        stack<int> stk;

        for (int i = 0; i <= n; ++i) {
            stk.push(i + 1);

            if (i == n || S[i] == 'I') {
                while (!stk.empty()) {
                    result += to_string(stk.top());
                    stk.pop();
                }
            }
        }

        return result;
    }
};
