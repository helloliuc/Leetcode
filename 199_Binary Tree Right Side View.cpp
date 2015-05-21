//1CE,1A
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Q_NODE {
    TreeNode *p;
    int level;
    Q_NODE(TreeNode* p, int level) : p(p), level(level) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        queue<Q_NODE> q;
        q.push(Q_NODE(root, 0));
        while(!q.empty()) {
            Q_NODE node = q.front();    q.pop();
            if(q.empty() || q.front().level > node.level) {
                ans.push_back(node.p->val);
            }
            if(node.p->left != NULL) {
                q.push(Q_NODE(node.p->left, node.level+1));
            }
            if(node.p->right != NULL) {
                q.push(Q_NODE(node.p->right, node.level+1));
            }
        }
        return ans;
    }
};
