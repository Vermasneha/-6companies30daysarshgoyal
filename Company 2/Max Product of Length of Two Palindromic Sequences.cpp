class Solution {
public:
    // mask mean subsequence - 1:exist 0: no exist
    int ispalindromic(string& s,int mask){
        int start=0,end=s.size()-1,res=0;
        while(start<=end){
            if((mask & (1<<start))==0) start++; // check character is exist
            else if((mask & (1<<end))==0) end--; // check character is exist
            else if(s[start]!=s[end]) return 0; // check is palindromic
            else{
                res+=1+(start!=end);
                start++;
                end--;
            }
        }
        return res;
    }
    int maxProduct(string s) {
        // note max s.length is 12
        int dp[4096]={},res=0,n=s.size();
        int masks=(1<<n)-1;
        // record
        for(int mask=0;mask<masks;mask++) dp[mask]=ispalindromic(s,mask);
        // find all possible
        for(int mask1=0;mask1<masks;mask1++){
            if(dp[mask1]!=0 && dp[mask1]*(n-dp[mask1])>res){
                for(int mask2=masks^mask1;mask2;mask2=(mask2-1)&(masks^mask1)){
                    res=max(res,dp[mask1]*dp[mask2]);
                }
            }
        }
        return res;
    }
};
