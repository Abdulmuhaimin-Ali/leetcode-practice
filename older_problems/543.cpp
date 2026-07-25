class Solution {
public:
    int x=0;
    int traverse(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int h1 = traverse(root->left);
        int h2 = traverse(root->right);
        x = max(x, h1+h2);

        return 1 + max(h1, h2);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return x;
    }
};