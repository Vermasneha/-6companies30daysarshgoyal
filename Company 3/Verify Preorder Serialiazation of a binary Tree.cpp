class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<int> ans;
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]>='0' && preorder[i]<='9'){
                int temp=0;
                while(preorder[i]>='0' && preorder[i]<='9'){
                    temp=temp*10+preorder[i]-'0';
                    i++;
                }
                ans.push_back(temp);
            }
            else if(preorder[i]=='#'){
                ans.push_back(-1);
            }
        }
        if(ans.size()==0)return 1;
        if(ans[0]==-1 && ans.size()!=1)return 0;
        if(ans[0]==-1 && ans.size()==1)return 1;
        int count=1;
        for(auto i:ans){
            if(count==0)return false;
            if(i!=-1){
                count+=2;
            }
            count--;
        }
        return count==0;
    }
};
