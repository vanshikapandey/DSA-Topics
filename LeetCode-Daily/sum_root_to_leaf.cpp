//Problem Link:https://leetcode.com/problems/sum-root-to-leaf-numbers/

//QUES:
/*You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.*/

/***************CODE***************************/
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
    vector<int> ans;
    void pathSum(TreeNode* root,int sum){
        
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            sum=sum*10+root->val;
            ans.push_back(sum);
            return ;
        }
        
       sum = sum*10+root->val;
       pathSum(root->left,sum);
       pathSum(root->right,sum);
        
    }
    int sumNumbers(TreeNode* root) {
        
        int sum = 0;
        pathSum(root,sum);
       
        int res = 0;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
            res+=ans[i];
        }
        
        return res;
    }
};


