class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()   # start of merged list
        tail = dummy         # pointer to end of merged list
        
        while list1 and list2:
            if list1.val <= list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next

        #attach remainder
        if list1:
            tail.next = list1
        else:
            tail.next = list2

        return dummy.next