class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int> freq;
        priority_queue<pair<int,char>> maxheap;

        //storing freq of every chars
        for(int i = 0; i<s.size(); i++){
            freq[s[i]]++;
        }


        //stoting into heap
        for(auto &pair: freq){
            maxheap.push({pair.second,pair.first});
        }

        //final ans
        while(!maxheap.empty()){
            char c = maxheap.top().second;
            int freq = maxheap.top().first;
            while(freq--){
                ans+=c;
            }
            maxheap.pop();
        }
        return ans;
    }
};
