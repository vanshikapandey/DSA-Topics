//Problem link:https://leetcode.com/problems/count-complete-tree-nodes/

//QUES
/*Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 */


 /******************CODE*********************/
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
    int lheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh = 1+ lheight(root->left);
        return lh;
    }
    int rheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int rh = 1+ rheight(root->right);
        return rh;
    }
    int countComplete(TreeNode* root){
        
        if(root==NULL)
            return 0;
        
        int lh = lheight(root);
        int rh = rheight(root);
        
        if(lh==rh){
            return pow(2,lh)-1;
        }
        
        return 1+countComplete(root->left)+countComplete(root->right);
        
    }
    int countNodes(TreeNode* root) {
        
        return countComplete(root);
    }
};