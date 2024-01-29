class Solution {
public:
    // 3 4 3
    // 4- 11|11 or 1111 
    // 發現 unordered_map<int,int> 會 Memory Limit Exceeded ...
    // 改用 vector<char> 還是會 Memory Limit Exceeded ...
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,char> masks;
        for(int i=0;i<reservedSeats.size();i++){
            int row=reservedSeats[i][0];
            int col=reservedSeats[i][1];
            if(col>1 && col<10) masks[row-1]|=(1<<(col-2));
        }
        int max_seat=n*2;
        int res=0;
        for(auto &[row,seat]:masks){
            // 11-11 優先 在來 1111
            // 算出不能做的seats
            bool left=seat&0b11110000;
            bool right=seat&0b00001111;
            bool mid=seat&0b00111100;
            res+=left&&right&&mid?2:1;
        }
        return max_seat-res;
    }
};
