/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode *p;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
        if(root == NULL) {
            p = NULL;
            return ;
        }
        p = root;
        while(p -> left != NULL) {
            s.push(p);
            p = p -> left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return p != NULL;
    }

    /** @return the next smallest number */
    int next() {
        int ret = p->val;
        if(p -> right != NULL) {
            p = p -> right;
            while(p -> left != NULL) {
                s.push(p);
                p = p -> left;
            }
        }
        else {
            if(s.empty()) {
                p = NULL;
            }
            else {
                p = s.top();
                s.pop();
            }
        }
        
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
