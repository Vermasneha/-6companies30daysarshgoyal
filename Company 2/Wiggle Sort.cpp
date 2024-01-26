class Solution {
public:
    void wiggleSort(vector<int>& nums) {
         ios_base::sync_with_stdio(false); 
         cin.tie(NULL);    
      
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int right=n-1;
        int left=n/2;
        if(n%2==0){
            left--;
        }
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            if(i%2==0){
                temp[i]=nums[left];
                left--;
            }
            else{
                  temp[i]=nums[right];
                  right--;
            }
        }
        nums=temp;


        
    }
};
