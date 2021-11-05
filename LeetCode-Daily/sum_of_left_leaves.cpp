<<<<<<< HEAD
//Problem Link: https://leetcode.com/problems/sum-of-left-leaves/

//QUES

/*Given the root of a binary tree, return the sum of all left leaves.*/

/********************CODE**************/

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
    int ans = 0;
    bool isLeaf(TreeNode * root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    void sumLeft(TreeNode* root){
        if(root==NULL){
            return ;
        }
        
        if(root->left && isLeaf(root->left)){
            ans+=root->left->val;
        }
        
        sumLeft(root->left);
        sumLeft(root->right);
            
        return;
      
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
         sumLeft(root);
        
        return ans;
    }
};
=======
//Problem Link: https://leetcode.com/problems/sum-of-left-leaves/

//QUES

/*Given the root of a binary tree, return the sum of all left leaves.*/

/********************CODE**************/

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
    int ans = 0;
    bool isLeaf(TreeNode * root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    void sumLeft(TreeNode* root){
        if(root==NULL){
            return ;
        }
        
        if(root->left && isLeaf(root->left)){
            ans+=root->left->val;
        }
        
        sumLeft(root->left);
        sumLeft(root->right);
            
        return;
      
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
         sumLeft(root);
        
        return ans;
    }
};
>>>>>>> dd6cf6711608fd402d6a79748df3263bda7ce53e
