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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                TreeNode *cur = q.front();  q.pop();
                if(i == 0) ans.push_back(cur->val);
                if(cur->right != NULL) { q.push(cur->right); }
                if(cur->left != NULL)  { q.push(cur->left);  }
            }
        }
        return ans;
    }
};
