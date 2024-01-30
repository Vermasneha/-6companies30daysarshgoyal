/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,vector<TreeNode*>> mp;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> leafs;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->right==node->left) leafs.push_back(node);
            if(node->right){
                mp[node].push_back(node->right);
                mp[node->right].push_back(node);
                q.push(node->right);
            }
            if(node->left){
                mp[node].push_back(node->left);
                mp[node->left].push_back(node);
                q.push(node->left);
            }
        }
        int ans = 0;
        for(auto &node : leafs){
            unordered_map<TreeNode*,int> vis;
            queue<pair<TreeNode*,int>> Q;
            Q.push({node,0});
            while(!Q.empty()){
                auto Node = Q.front();
                Q.pop();
                vis[Node.first] = 1;
                for(const auto &nodes : mp[Node.first]){
                    if(vis[nodes]) continue;
                    vis[nodes] = 1;
                    if(Node.second+1<=distance){
                        if(nodes->left==nodes->right) ans++;
                        else Q.push({nodes,Node.second+1});
                    }
                }
            }
        }
        return ans/2;
    }
};
