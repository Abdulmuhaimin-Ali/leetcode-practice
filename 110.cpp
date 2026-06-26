class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return DFS(root).first;
    }
private:
     pair<bool, int> DFS(TreeNode* root){
        if(!root){
            return {true, 0};
        }

        pair<bool, int> left = DFS(root->left);
        pair<bool, int> right = DFS(root->right);

        bool balanced = (abs(left.second - right.second) <= 1) && (left.first == true && right.first == true);
        int height = 1 + max(left.second, right.second);
        return {balanced, height};
    }
};