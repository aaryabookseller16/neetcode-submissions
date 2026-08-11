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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // start at the head of both lists
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        // create dummy head for result list
        ListNode dummy(0);
        ListNode* curr3 = &dummy;

        while (curr1 != nullptr && curr2 != nullptr) {
            // add smaller element first
            if (curr1->val > curr2->val) {
                curr3->next = curr2;     // add less than element
                curr2 = curr2->next;     // increment pointer in list2
            } else {
                curr3->next = curr1;     // add less than element
                curr1 = curr1->next;     // increment pointer in list1
            }
            curr3 = curr3->next;         // increment pointer in merged list
        }
        
        // if one runs out, exit and add the rest
        while (curr1 != nullptr) {
            curr3->next = curr1;
            curr1 = curr1->next;         // increment pointer
            curr3 = curr3->next;
        }

        while (curr2 != nullptr) {
            curr3->next = curr2;
            curr2 = curr2->next;         // increment pointer
            curr3 = curr3->next;
        }

        return dummy.next;               // head of merged list
    }
};
