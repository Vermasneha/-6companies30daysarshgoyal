class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int,int>>v;

        for(auto it : buildings){
            int start = it[0] , end = it[1] , height = it[2];

            v.push_back({start , -height});
            v.push_back({end , height});
        }

        sort(v.begin() , v.end());

        multiset<int>st;
        st.insert(0);
        int maxHeight = 0;

        vector<vector<int>>ans;

        for(auto it : v){
            int point = it.first , height = it.second;

            if(height < 0){
                st.insert(abs(height));
            }
            else{
                auto it1 = st.find(height);
                st.erase(it1);
            }

            if(maxHeight != *st.rbegin()){
                maxHeight = *st.rbegin();
                ans.push_back({point , maxHeight});
            }
        }

        return ans;
    }
};
