class Solution {
public:
int numFriendRequests(vector<int>& ages) {
        map<int,int> mp;
        for(auto it:ages){
            mp[it]++;
        }
        int cnt=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            int minAge=0.5*(it->first)+7;
            auto upper_bound=mp.upper_bound(minAge);
            if(upper_bound->first>it->first) continue;
            int tempCnt=0;
            for (auto i = upper_bound; i != mp.end(); i++) {
                if (i->first != it->first) {
                    cout<<it->first<<" "<<upper_bound->first<<" "<<i->first<<" "<<i->second<<endl;
                    tempCnt += i->second;
                }
                else{
                    break;
                }
            }
            if(it->second>1){
            cnt+=((it->second)*tempCnt);
            int temp=it->second;
            if(it->first>it->first*0.5+7)
            cnt+=((temp*(temp-1)));
            }
            else{
                cnt+=tempCnt;
            }
        }
        return cnt;
    }
};
