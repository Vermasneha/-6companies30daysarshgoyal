class Solution {
public:
    int wordCount(std::vector<std::string>& startWords, std::vector<std::string>& targetWords) {
        // Map to store the occurrence count of unique hashes of startWords
        std::unordered_map<int, int> hashCount;
        
        // Calculate and count the unique hashes of startWords
        for (const std::string& str : startWords) {
            int hash = calculateHash(str);
            hashCount[hash]++;
        }
        
        // Count the number of targetWords that share a common hash with startWords
        int count = 0;
        for (const std::string& str : targetWords) {
            int hash = calculateHash(str);
            // Check if removing any character from the targetWord results in a hash present in startWords
            for (int i = 0; i < 26; i++) {
                if (!(hash & (1 << i))) continue;
                int modifiedHash = hash & ~(1 << i); // Remove the ith character from the hash
                if (hashCount.count(modifiedHash)) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
    
private:
    // Function to calculate the hash of a string
    int calculateHash(const std::string& str) {
        int hash = 0;
        for (char ch : str) {
            hash |= (1 << (ch - 'a')); // Set the corresponding bit for each character
        }
        return hash;
    }
};
