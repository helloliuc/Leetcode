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
    bool isSymmetric(TreeNode *p, TreeNode *q) {
        return (!p && !q) || (p && q && p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left));
    }
    bool isSymmetric(TreeNode* root) {
        return !root || isSymmetric(root->left, root->right);
    }
};
