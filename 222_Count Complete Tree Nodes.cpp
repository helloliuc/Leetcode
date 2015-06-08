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
    int getHeight(TreeNode *root) {
        int ret = 0;
        while(root != NULL) {
            ret++;
            root = root->left;
        }
        return ret;
    }
    bool exists(TreeNode* root, int height, int pos) {
        int len = pow(2, height-1) / 2;
        int st = 1;
        while(len > 0) {
            if(pos <= st + len - 1) {
                root = root->left;
                if(root == NULL) {
                    return false;
                }
            }
            else {
                root = root->right;
                if(root == NULL) {
                    return false;
                }
                st = st + len;
            }
            len = len / 2;
        }
        return true;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int h = getHeight(root);
        int lt = 1, rt = pow(2, h-1) + 1;
        while(lt < rt) {
            int mid = lt + (rt - lt) /2;
            if(exists(root, h, mid)) {
                lt = mid + 1;
            }
            else {
                rt = mid;
            }
        }
        return pow(2, h-1) - 1 + lt - 1;
    }
};
