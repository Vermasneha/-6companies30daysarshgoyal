class Solution {
public:
    bool check(vector<int>&temp)
    {
        for(int i=1;i<temp.size();i++)
        {
            if(temp[i-1] >= temp[i])return false;
        }
        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) 
    {   
        int count=0;
        for(int i=0;i<nums.size();i++)
        {  
            
            for (int j=i;j<nums.size();j++)
            {   
                vector<int>temp;
                for(int k=0;k<i;k++)
                {
                    temp.push_back(nums[k]);
                }
                for(int k=j+1;k<nums.size();k++)
                {
                    temp.push_back(nums[k]);
                }

                if(check(temp))count++;
               
            }
             
        }
        return count;      
    }

};
