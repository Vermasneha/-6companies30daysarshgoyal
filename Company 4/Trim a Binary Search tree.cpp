class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // Base case: if the current node is null, return null
        if (!root) return nullptr;

        // Recursively trim left and right subtrees
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        // Check if the current node value is outside the desired range [low, high]
        if (root->val < low)
            return root->right;
        else if (root->val > high)
            return root->left;
        else
            return root;
    }
};
