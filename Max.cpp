/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int dfs(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mpp){
        if(root == NULL) return -1 ;
        if(root->left){
            mpp[root->left] = root;
            dfs(root->left, mpp); 
        }
        if(root->right){
            mpp[root->right] = root;
            dfs(root->right, mpp);
        }
        return 1 ;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> v ; 
        if(root == NULL) return v ;
        unordered_map<TreeNode*, TreeNode*> mpp;
        queue<TreeNode*> q;
        dfs(root, mpp);
        q.push(target); 
        set<TreeNode*> s ; 

        while(k){
            int size = q.size();
            while(size){
                TreeNode* temp = q.front();
                q.pop();
                s.insert(temp); 
                if(temp->left && !s.contains(temp->left))
                        q.push(temp->left);
                if(temp->right && !s.contains(temp->right))
                        q.push(temp->right);
                if(mpp[temp] && !s.contains(mpp[temp]))
                        q.push(mpp[temp]); 

                size--; 
            }
            k--;
        } 
        while(!q.empty()){
            TreeNode* temp = q.front(); 
            q.pop();
            v.push_back(temp->val); 
        }
        return v; 
    }
};
