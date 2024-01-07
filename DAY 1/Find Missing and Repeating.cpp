class Solution{
public:
    long long  dupe(vector<int>arr){
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]){
                return arr[i];
            }
        }
    }
    
    long long  sum(vector<int>arr){
        long long int summ=0;
        for(int i=0;i<arr.size();i++){
            summ+=arr[i];
        }
        return summ;
    }
    
    vector<long> findTwoElement(vector<int> arr, int n) {
        // code here
        long long int y=n;
        long long  B=dupe(arr);
        long long int Sum=sum(arr);
        Sum-=B;
         long long int expectedSum=(y*(y+1))/2;

 

        long long int A= expectedSum-Sum;
        // cout<<expectedSum<<endl<<Sum <<endl;
        vector<long>ans;
        ans.push_back(B);
        ans.push_back(A);
        return ans;
    }
};


