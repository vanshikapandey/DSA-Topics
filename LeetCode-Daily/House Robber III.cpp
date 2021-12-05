//Problem Link:https://leetcode.com/problems/house-robber-iii/

//QUES

/******************CODE***************/

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
    map<TreeNode*, int> mp;
    int maxRob(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        if(mp.find(root)!=mp.end()){
            return mp[root];
        }
        int sum = 0;
        
        if(root->left){
            sum+= maxRob(root->left->left) + maxRob(root->left->right);
        }
        
        if(root->right){
            sum+= maxRob(root->right->left) + maxRob(root->right->right);
        }
        
        return mp[root] = max(sum+root->val,maxRob(root->left)+maxRob(root->right));
    }
    int rob(TreeNode* root) {
        
        
        return maxRob(root);
        
    }
};