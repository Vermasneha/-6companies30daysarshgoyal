#include <iostream>
#include <unordered_map>
#include <string>

class TrieNode {
public:
    // member variables
    char letter;
    std::unordered_map<char, TrieNode*> children;
    bool endOfWord;
    
    // constructors
    TrieNode() : letter('\0'), endOfWord(false) {} // '\0' is a null character
    TrieNode(char x) : letter(x), endOfWord(false) {}
};

class WordDictionary {
private:
    // root node should not be accessed by user
    TrieNode* root;

public:
    WordDictionary() {
        // upon constructing a word dictionary, the root node variable is initialised
        root = new TrieNode();
    }

    void addWord(std::string word) {
        TrieNode* current = root;

        for (char c : word) { // iterate through every character in the input string
            if (!current->children.count(c)) { // if character is not in hash map...
                current->children[c] = new TrieNode(c); // add character to hash map, mapped to new trie node 
            }
            current = current->children[c]; // set current node to the character node from the hash map
        }
        current->endOfWord = true; // once word is fully iterated through, set endOfWord boolean value to true. 
    }

    bool dfs(int i, TrieNode* current, std::string word) {
        if (i == word.size()) {
            return current->endOfWord;
        }

        char character = word[i];

        if (character == '.') {
            for (auto& child : current->children) {
                if (dfs(i + 1, child.second, word)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!current->children.count(character)) {
                return false;
            }
            return dfs(i + 1, current->children[character], word);
        }
    }

    bool search(std::string word) {
        return dfs(0, root, word);
    }

    // Destructor to free allocated memory
    ~WordDictionary() {
        deleteTrie(root);
    }

private:
    // Helper function to recursively delete the trie
    void deleteTrie(TrieNode* node) {
        if (node) {
            for (auto& child : node->children) {
                deleteTrie(child.second);
            }
            delete node;
        }
    }
};
