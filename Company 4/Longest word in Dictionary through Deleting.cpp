class Solution {
public:
    bool isPossible(string s,string dic){
        int n=s.length();
        int m=dic.length();
        if(m>n) return false;

        int i=0;int j=0;
        while(i<n && j<m){
            if(s[i]==dic[j]){
                i++;j++;
            }else{
                i++;
            }
        }
        if(j==m) return true;
        return false;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        int n=dictionary.size();
        string ans;

        for(int i=0;i<n;i++){
            if(isPossible(s,dictionary[i])){
                string temp=dictionary[i];
                if(temp.length()>ans.length()) ans=temp;
                else if(temp.length()==ans.length()){
                    if(temp<ans) ans=temp;
                }
            }
        }

        return ans;
    }
};
