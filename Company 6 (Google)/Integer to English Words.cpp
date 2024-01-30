class Solution {
public:
    unordered_map<int,string>ones,tens,ten1;
    Solution(){   // Created mapping for ones digits 
        ones[1]=" One";
        ones[2]=" Two";
        ones[3]=" Three";
        ones[4]=" Four";
        ones[5]=" Five";
        ones[6]=" Six";
        ones[7]=" Seven";
        ones[8]=" Eight";
        ones[9]=" Nine";

        // Mapping for the Tens Place except for the 1. type like 11 12 ..
        tens[2]=" Twenty";
        tens[3]=" Thirty";
        tens[4]=" Forty";
        tens[5]=" Fifty";
        tens[6]=" Sixty";
        tens[7]=" Seventy";
        tens[8]=" Eighty";
        tens[9]=" Ninety";

        // This is  mapping for the Tens place for like 11 12 10 ..
        ten1[0]=" Ten";
        ten1[1]=" Eleven";
        ten1[2]=" Twelve";
        ten1[3]=" Thirteen";
        ten1[4]=" Fourteen";
        ten1[5]=" Fifteen";
        ten1[6]=" Sixteen";
        ten1[7]=" Seventeen";
        ten1[8]=" Eighteen";
        ten1[9]=" Nineteen";
    
    }
    vector<int>num_to_array(int x){  // Extractig the digits from the number and will traverse the numner from right side 
        vector<int>ans;
        while(x){
            ans.push_back(x%10); x/=10;
        }
        return ans;
    }
    string reverse_word(string s){  // Reversing the answer string word wise as we have traversed number digits from right side 
                                    // E.G-> Here I Am --->> Am I Here
        string ans="",t="";
        for(int i=s.size()-1;i>=0;i--){
             t+=s[i];
            if(s[i]==' ') {
                reverse(t.begin(),t.end());
                ans+=t;
                t="";
            }
        }
        ans=ans.substr(1,ans.size()-1);
        return ans;
    }
    bool isSafe(int i,vector<int>v){  // Spceial function for edge cases containing 0 like 2002100, 10000 
        return (v[i]!=0) || (i+1<v.size() && v[i+1]!=0) || (i+2<v.size() && v[i+2]!=0) ;
    }

    string numberToWords(int num) {
        //Separatley if num==0
        if(num==0) return "Zero";
        vector<int>input;
        string ans="";
        input=num_to_array(num);

        for(int i=0;i<input.size();i++){
             //Adding these at appropiate place if any of their three consecutive are non zero
            if((i==3)&& (isSafe(i, input)))ans+=" Thousand"; 
            if((i==6) && (isSafe(i, input))) ans+=" Million";
            if((i==9)&& (isSafe(i, input))) ans+=" Billion";
            // If any digit is zero then continue but just check for '10' like cases
            if(input[i]==0){
                if(i==0 || i%3==0){
                if(i+1<input.size() && input[i+1]==1){
                        ans+=" Ten";
                        i++;
                }}
                continue;
                }
                // Here starts the all other normal cases
                // Condition for tens place
            if(i==0 || i%3==0){
                // Condition for 1* like 11 12 10 16 type input
                if(i+1<input.size() && input[i+1]==1){
                        ans+=ten1[input[i]];
                        i++;
                }
                // Condition for all other tens place digits 
                    else{
                        ans+=ones[input[i]];
                    }
            }
            // For Ones just simply add the Word
            if(i-1==0 || (i-1)%3==0){
                ans+=tens[input[i]];
            }
            // For Hundered Place add the Hundered and add the word corresponding to that digit
            else if(i-2==0 ||(i-2)%3==0) {
                ans+=" Hundred";
                ans+=ones[input[i]];
            }
        }
        //Reverse String word wise as we have formed answer from right side of number
        ans=reverse_word(ans);
        return ans;
    }
};
