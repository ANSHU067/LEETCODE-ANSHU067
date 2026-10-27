class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        ans.push_back(root->val);  // 1. Visit root
        preorder(root->left, ans); // 2. Visit left
        preorder(root->right, ans); // 3. Visit right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};