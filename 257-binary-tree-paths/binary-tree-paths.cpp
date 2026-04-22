class Solution {
public:
    void findPaths(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;

        path += to_string(node->val);

        if (!node->left && !node->right) {
            result.push_back(path);
        } else {
            path += "->";
            findPaths(node->left, path, result);
            findPaths(node->right, path, result);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root) findPaths(root, "", result);
        return result;
    }
};