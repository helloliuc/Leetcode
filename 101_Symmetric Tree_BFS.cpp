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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> q, p;
        q.push(root);   p.push(root);
        while(!q.empty()) {
            TreeNode *cur_p = p.front(), *cur_q = q.front();
            p.pop(); q.pop();
            if(!cur_p && !cur_q) continue;
            else if(cur_p && cur_q && cur_p->val == cur_q->val) {
                p.push(cur_p->left);
                p.push(cur_p->right);
                q.push(cur_q->right);
                q.push(cur_q->left);
            }
            else return false;
        }
        return true;
    }
};
