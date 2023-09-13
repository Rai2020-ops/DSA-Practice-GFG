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
    bool isPalindrome(ListNode* head) {
        if(head==NULL|| head->next==NULL){
            return true;
        }
        
        
        ListNode* temp=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            temp=temp->next;
            fast=fast->next->next;
           
            
        }
        temp->next=reverseList(temp->next);
        temp=temp->next;
       

      while(temp!=NULL){
          if(head->val!=temp->val){
              return false;
          }
          head=head->next;
          temp=temp->next;
      }
     return true;
    }

 ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        
        while(head!=NULL){
        ListNode*forward=head->next;
        head->next=prev;
        prev=head;
        head=forward;
        }
        return prev;
 }

};