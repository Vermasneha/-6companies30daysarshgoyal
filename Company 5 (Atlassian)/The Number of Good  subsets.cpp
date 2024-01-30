class Solution {
public:
    const long MODULO = 1e9 + 7;
    long result = 0;
    int primes[10] = {2,3,5,7,11,13,17,19,23,29};
    int nonprimes[8] = {6,10,14,15,21,22,26,30};
    int count[31];
    vector<int> bitRep;

    long powerOfTwo(int x) {
        long res = 1;
        while(x--) res = (res * 2) % MODULO;
        return res;
    }

    void dfs(int index, int curSetBits, long countSoFar) {
        if(index == 8) {
            for(int prime : primes) {
                if((curSetBits & bitRep[prime]) == 0) {
                    countSoFar = (countSoFar * (1 + count[prime])) % MODULO;
                }
            }
            result = (result + countSoFar) % MODULO;
            return ;
        }
        dfs(index+1, curSetBits, countSoFar);
        if((curSetBits & bitRep[nonprimes[index]]) == 0 && count[nonprimes[index]] != 0) {
            countSoFar = (countSoFar * count[nonprimes[index]]) % MODULO;
            dfs(index+1, curSetBits | bitRep[nonprimes[index]], countSoFar);
        }
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        bitRep.clear(); 
        bitRep.resize(31, 0);
        for(int i : nums) count[i]++;
        for(int i : primes) bitRep[i] = 1 << i;
        for(int i : nonprimes) {
            for(int prime : primes) if(i % prime == 0) bitRep[i] |= (1 << prime);
        }
        dfs(0, 0, 1);
        result = (result + MODULO - 1) % MODULO;
        result = (result * powerOfTwo(count[1])) %  MODULO;
        return result;
    }
};
