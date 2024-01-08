class Solution {
    private:
    int calCulateTime(string &str1)
    {
        int k = 0,time = 0;
        //skip all the first zeroes
        if(str1[k] == '0') k++;
        if(str1[k] == '0') k++;
        if(str1[k] == '0') k++;
        if(str1[k] == '0') k++;
        if(k >= 4)
            time  = 0;
        else
        {
            string a = str1.substr(k);
            time = stoi(a);
        }
        return time;
    }
    bool isValid(int i,vector<int>&v)
    {
       return (abs(v[i]-v[i-1])<100 && abs(v[i]-v[i-2])<100 && abs(v[i-1]-v[i-2]) < 100);
    }
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& nums) 
    {
        vector<string>ans;
        int n = nums.size();
        map<string,vector<int>>uobj;
        for(int i=0;i<n;i++)
        {
            string str = nums[i][0];
            string str1 = nums[i][1];
            int time  = calCulateTime(str1);
            uobj[str].push_back(time);
        }
        
        for(auto &it : uobj)
        {
            vector<int>v = it.second;
            sort(v.begin(),v.end());
            for(int i=2;i<v.size();i++)
            {
                if(isValid(i,v))
                {
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
        
    }
};
