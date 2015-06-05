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
    void pathSum_helper(TreeNode *root, int sum, vector<vector<int>> &ret, vector<int> &cur) {
        if(root == NULL) return ;
        cur.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == sum) {
            ret.push_back(cur);
        }
        pathSum_helper(root->left, sum - root->val, ret, cur);
        pathSum_helper(root->right, sum - root->val, ret, cur);
        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> cur;
        pathSum_helper(root, sum, ret, cur);
        return ret;
    }
};
