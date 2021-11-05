    //Problem Link:https://leetcode.com/problems/reverse-linked-list/

    //QUES
    /*Given the head of a singly linked list, reverse the list, and return the reversed list.*/

    /************Iterative Code********************/

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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* temp;
        ListNode *prev = NULL;
        
        while(head!=NULL){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        
        head = prev;
        return  head;
    }
};



/**********************Recursive Code*******************/
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
ListNode* h;
void reverseLL(ListNode* head){
    if(head==NULL){
        return ;
    }
    
    if(head->next==NULL){
        h=head;
        return;
    }
    
    reverseLL(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    
}
    ListNode* reverseList(ListNode* head) {
        
        reverseLL(head);
        
        return h;
        
    }
};