class Solution {
private:
    //makes top connection and finds starting node
    void topConnect(TreeNode *root, unordered_map<TreeNode*,TreeNode*>&top, TreeNode *&st, int s){
        top[root]=NULL; queue<TreeNode*>q; q.push(root);
        if(root->val==s) st=root;
        
        while(!q.empty()){
            TreeNode *cur=q.front(); q.pop();
            if(cur->val==s)st=cur;
            if(cur->left){
                top[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right){
                top[cur->right]=cur;
                q.push(cur->right);
            }
        }
    }
public:
    int bfs(TreeNode *root, unordered_map<TreeNode*, TreeNode*> top){
        /*infection starts from given infected node and using 
            null to seperate each infected section*/
        int time=0; unordered_set<TreeNode*>mp;
        queue<TreeNode*>q; q.push(root); q.push(NULL);
        
        while(!q.empty()){
            TreeNode *cur=q.front(); q.pop();
            //end time of current infection
            if(!cur){
                ++time;
                if(!q.empty())q.push(NULL);
            }

            //infection spread
            else {
                //top
                if(top[cur] && !mp.count(top[cur])) q.push(top[cur]);
                //left
                if(cur->left && !mp.count(cur->left)) q.push(cur->left);
                //right
                if(cur->right && !mp.count(cur->right)) q.push(cur->right);
                
                //map update -> to prevent self loop
                mp.insert(cur);
            }
        }        
        return time-1;
    }

    int amountOfTime(TreeNode *root, int start) {
        TreeNode *st=NULL;
        unordered_map<TreeNode *, TreeNode *>top; topConnect(root, top, st, start);
        return bfs(st, top);
    }
};
