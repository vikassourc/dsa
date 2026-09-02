class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* cur = root;

        while (cur != NULL) {

            if (cur->left != NULL) {

                TreeNode* prev = cur->left;

                // Find rightmost node of left subtree
                while (prev->right != NULL) {
                    prev = prev->right;
                }

                // Attach original right subtree
                prev->right = cur->right;

                // Move left subtree to right
                cur->right = cur->left;

                // Remove left
                cur->left = NULL;
            }

            cur = cur->right;
        }
    }
};