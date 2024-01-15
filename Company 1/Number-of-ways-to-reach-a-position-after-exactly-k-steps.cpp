class Solution {
public:
    int solve(int startPos, int endPos, int k){
        //Base Condn
        if(k==0){
            if(startPos==endPos) return 1;  //If we reach the endpos in k steps
            else return 0;
        }
        
        int a = solve(startPos+1, endPos, k-1);   //Step Forward
        int b = solve(startPos-1, endPos, k-1);   //Step Backward
        
        return (a+b);   //Return total ways
    }

    int numberOfWays(int startPos, int endPos, int k) {
        return solve(startPos, endPos, k);
    }
};
