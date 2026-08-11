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
      //intialize current, previous, and next
      ListNode *current = head;
      ListNode *previous = nullptr;
      ListNode *next; 

      while(current != nullptr){
         
         // store next
         next = current->next;

         //reverse current's next pointer
         current->next = previous;

         //move pointers
         previous = current;
         current = next;
      }
      return previous;
    }
};
