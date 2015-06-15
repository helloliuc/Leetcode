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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return vector<vector<int> >();
        TreeNode *end = root, *next_end;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int> > ans;
        vector<int> cur;
        while(!q.empty()) {
            TreeNode *front = q.front();    q.pop();
            cur.push_back(front->val);
            if(front->left != NULL) {
                q.push(front->left);    next_end = front->left;
            }
            if(front->right != NULL) {
                q.push(front->right);   next_end = front->right;
            }
            if(front == end) {
                ans.push_back(cur);
                cur.clear();
                end = next_end;
            }
        }
        return ans;
    }
};
