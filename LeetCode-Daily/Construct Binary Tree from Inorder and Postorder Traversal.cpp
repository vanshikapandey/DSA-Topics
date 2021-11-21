//Problem Link:https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

//QUES

/**************CODE*********************/

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
    int search(vector<int>& inorder , int start, int end,int ele){
        for(int i=start;i<=end;i++){
            if(inorder[i]==ele){
                return i;
            }
        }
        return 0;
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int start , int end,int &index ){
        if(start>end){
            return NULL;
        }
       
       
        int ele = postorder[index];
        index--;
        
        TreeNode *node = new TreeNode(ele);
        
         if(start==end){
            return node;
        }
        int pos = search(inorder,start,end,ele);
        
        node->right = build(inorder,postorder,pos+1,end,index);
        node->left = build(inorder,postorder,start,pos-1,index);
       
        
        return node;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size();
        int index = n-1;
        
        return build(inorder,postorder,0,n-1,index);
        
    }
};