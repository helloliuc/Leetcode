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
private:
    int kthSmallestCore(TreeNode *root, int &k) {
        if(root == NULL) {
            return 0;
        }
        
        int ret = kthSmallestCore(root->left, k);
        if(k < 1) return ret;
        if(k-- == 1) return root->val;
        return kthSmallestCore(root->right, k);
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        kthSmallestCore(root, k);
    }
};
