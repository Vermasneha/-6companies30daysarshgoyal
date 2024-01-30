class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        if (exp == 0) return 1;
        if (exp == 1) return base % mod;
        
        long long tmp = power(base, exp / 2, mod);
        
        if (exp % 2 == 0) { // If exponent is even
            return (tmp * tmp) % mod; // Compute (base ^ (exp / 2)) ^ 2
        }
        else { // If exponent is odd
            tmp = tmp * tmp % mod; // Compute (base ^ (exp / 2)) ^ 2
            base %= mod;
            return (tmp * base) % mod; // Multiply by base for odd exponent
        }
    }
    
    int minNonZeroProduct(int p) {
        long long range = (1LL << p) - 1; // Calculate the range
        long long mod = 1e9 + 7; // Modulo value
        long long tmp = power(range - 1, range / 2, mod); // Compute (range - 1)^(range / 2) % mod
        return (tmp * (range % mod)) % mod; // Multiply by (range % mod) and take modulo
    }
};
