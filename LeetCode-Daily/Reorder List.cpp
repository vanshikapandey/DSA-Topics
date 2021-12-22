//Problem Link:https://leetcode.com/problems/reorder-list/


//QUES

/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.*/

/************CODE*****************/

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
    void reorderList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return;
        }
       ListNode* fast = head, *slow = head,*slowHead;
        
       while(fast!=NULL && fast->next!=NULL){
           slowHead = slow; 
           fast = fast->next->next;
           slow = slow->next;
           
       }
        slowHead->next = NULL;
        
        ListNode* curr = slow,*prev = NULL ;
        
        while(curr!=NULL){
         
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        ListNode* newHead = new ListNode();
        ListNode* temp = newHead;
        slow = prev;
        
        while(head!=NULL && slow!=NULL){
         
           temp->next = head;
           head = head->next;
           temp = temp->next;
            
            temp->next = slow;
            slow = slow->next;
            temp = temp->next;         
            
        }
        
        head = newHead->next;
    }
};