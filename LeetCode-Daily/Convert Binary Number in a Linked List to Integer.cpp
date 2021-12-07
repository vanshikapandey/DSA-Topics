
//Problem Link:https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

//QUES


/***************CODE****************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        int res=head->val;
       
        ListNode* temp = head;
        
        while(temp->next!=NULL){
            res = res*2+(temp->next->val);
            temp = temp->next;
        }
      
        return res;
    }
};