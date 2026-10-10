/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traverse;
        vector<TreeNode*> save;
        TreeNode* current = root;
        while(current != nullptr || !save.empty()){
        while(current != nullptr){
            save.push_back(current);
            current = current->left;
        }
        current = save.back();
        traverse.push_back(current->val);
        save.pop_back();
        current = current->right;
        
        }
        return traverse;
    }
};