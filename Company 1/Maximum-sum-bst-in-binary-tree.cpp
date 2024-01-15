class Solution {
public:
    // Function to find the maximum sum of a Binary Search Tree (BST)
    int maxSumBST(TreeNode* root) {
        int maxSum = 0; // Variable to store the maximum sum found
        bool isBST; // Flag indicating whether the current subtree is a valid BST
        int minValue, maxValue, sum; // Variables to store information about the current subtree

        // Call the helper function to perform the recursive traversal and find the maximum sum
        isValidBST(root, isBST, minValue, maxValue, sum, maxSum);
        
        // Return the maximum sum found
        return maxSum;
    }

    // Helper function to check if a subtree is a valid BST and update the maximum sum accordingly
    void isValidBST(TreeNode* node, bool& isBST, int& minValue, int& maxValue, int& sum, int& maxSum) {
        if (node == nullptr) {
            // If the node is null, it is a valid BST with no values
            isBST = true;
            minValue = INT_MAX;
            maxValue = INT_MIN;
            sum = 0;
            return;
        }

        bool leftIsBST, rightIsBST;
        int leftMin, leftMax, leftSum;
        int rightMin, rightMax, rightSum;

        // Recursively check the left and right subtrees
        isValidBST(node->left, leftIsBST, leftMin, leftMax, leftSum, maxSum);
        isValidBST(node->right, rightIsBST, rightMin, rightMax, rightSum, maxSum);

        // Check if the current subtree is a valid BST and update the maximum sum
        if (leftIsBST && rightIsBST && (node->left == nullptr || node->val > leftMax) &&
            (node->right == nullptr || node->val < rightMin)) {

            // Calculate the sum of values in the current subtree
            sum = node->val + leftSum + rightSum;

            // Update the maximum sum if the current sum is greater
            maxSum = std::max(maxSum, sum);

            // Determine the minimum and maximum values in the current subtree
            minValue = (node->left == nullptr) ? node->val : leftMin;
            maxValue = (node->right == nullptr) ? node->val : rightMax;

            // Set the flag indicating that the current subtree is a valid BST
            isBST = true;
        } else {
            // If the current subtree is not a valid BST, set the flag accordingly
            isBST = false;
        }
    }
};
