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
    int isBalanced_helper(TreeNode* root, bool &balanced) {
        if(root == NULL) {
            return 0;
        }
        if(!balanced) return 0;
        int height_left = isBalanced_helper(root->left, balanced);
        int height_right = isBalanced_helper(root->right, balanced);
        if(abs(height_left - height_right)  > 1) {
            balanced = false;
        }
        return max(height_left, height_right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool ret = true;
        isBalanced_helper(root, ret);
        return ret;
    }
};
