class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int result = 0;
        sort(reservedSeats.begin(), reservedSeats.end());

        int prerow = 0;
        int p = 0;
        
        while(p < reservedSeats.size()){
            vector<int> iv(10, 0);
            int curstart = reservedSeats[p][0]; 
            iv[reservedSeats[p][1] - 1] = 1;
            result += (curstart - 1 - prerow) * 2;
            
            p++;
            while(p < reservedSeats.size() && curstart == reservedSeats[p][0]){
                iv[reservedSeats[p][1] - 1] = 1; p++;
            }

            vector<int> dp(10, 0);
            
            for(int i = 4; i <= 8; i++){
                if((i == 4 || i == 8 || i == 6) && (iv[i] == 0 && iv[i - 1] == 0 && iv[i - 2] == 0 && iv[i - 3] == 0)){
                        dp[i] = max(1 + dp[i - 4], dp[i - 1]);
                }
                else {
                    dp[i] = dp[i - 1];
                }
            }
            result += dp[8];
            prerow = curstart;

            // printf("prerow %d, result %d\n", prerow, result);
        }


        result += (n - prerow) * 2;

        return result;
    }
};
