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
    void flatten(TreeNode* root) {
        TreeNode* flatten = root;
        TreeNode* cache = root;
        while(cache != nullptr){
            if(flatten->left != nullptr){
            flatten = flatten->left;
            while(flatten->right != nullptr){
                flatten = flatten->right;
            }
            flatten->right = cache->right;
            cache->right = cache->left;
            cache->left = nullptr;
            }
            cache = cache->right;
            flatten = cache;
           
        }
    }
};