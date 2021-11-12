//Problem Link: https://leetcode.com/problems/remove-linked-list-elements/

//QUES:
/*Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
*/

/********************CODE*******************/
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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* curr = head , *prev = NULL;
        
        while(curr!=NULL){
            
            if(curr->val==val && prev==NULL){
                head = head->next;
            }
            else if(curr->val==val && prev){
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr=curr->next;
        }
        
        return head;
    }
};
