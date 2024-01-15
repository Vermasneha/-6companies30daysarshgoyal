class Solution {
public:
    string getHint(string s, string g) {
        string ans ;
        int c=0;
        int k = min(s.size(), g.size());
       
      
        int freq1[10]={0};
        int freq2[10]={0};
        int d=0;
        for(int i=0;i< s.size(); i++)
        {
                   freq1[s[i]-'0']++;
        }
                for(int i =0;i< g.size(); i++)
        {
                   freq2[g[i]-'0']++;
        }
                for(int i =0;i<k; i++)
        {
             if(s[i]==g[i])
             {c++;
              freq1[s[i]-'0']--;
              freq2[s[i]-'0']--;
             }

        }
         string con = to_string(c);
        ans=ans+con+"A";
        for(int i =0;i< 10; i++)
        {
            if(freq1[i]!=0 && freq2[i]!=0)
            {
               if(freq1[i]<=freq2[i])   //  intersection of two frequencies  to be considerd.
               d+= freq1[i];
               else
               d+= freq2[i];
            }
        }
    
        ans+= to_string(d)+"B";
        return ans ;
            }
};
