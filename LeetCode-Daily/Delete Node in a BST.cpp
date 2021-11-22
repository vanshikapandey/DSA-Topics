//Peoblem Link:https://leetcode.com/problems/delete-node-in-a-bst/

//QUES

/*Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.*/



/****************CODE********************/

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
    TreeNode*  findMin(TreeNode* root){
        
        while(root->left!=NULL){
            root=root->left;
        }
        
        return root;

    }
    
    TreeNode* del(TreeNode* root, int key){
        
        if(root==NULL){
            return NULL;
        }
        
        if(key>root->val){
            root->right = del(root->right,key);   
        }
        else if(key<root->val){
            root->left = del(root->left,key);
        }
        
        else{
            
            if(root->left==NULL && root->right==NULL){
                delete(root);
                return NULL;
            }
            else if((root->left==NULL && root->right) || (root->left && root->right==NULL)){
                if(root->left){
                    TreeNode* temp = root->left;
                    delete(root);
                    return temp;
                }
                 else{
                    TreeNode* temp = root->right;
                    delete(root);
                    return temp;
                }
            }
            else{
                
                TreeNode * minm = findMin(root->right);
                root->val = minm->val;
                root->right = del(root->right,minm->val);   
            }
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        
        return del(root,key);
        
    }
};