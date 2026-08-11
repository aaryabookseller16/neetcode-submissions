# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def findMidPoint(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head

        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        return slow

    def reverseLinkedList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head

        while curr:
            temp = curr.next #increment temp pointer
            curr.next = prev #reverse the link
            prev = curr
            curr = temp
        
        return prev

    def reorderList(self, head: Optional[ListNode]) -> None:
        mid = self.findMidPoint(head) # find mid point

        # reverse starting from mid.next, not mid itself
        second = self.reverseLinkedList(mid.next) # reverse the second half

        mid.next = None # cut the first half

        first = head

        while second:
            # save the next connections
            temp1 = first.next
            temp2 = second.next

            #join the elements
            first.next = second
            second.next = temp1

            # move it along
            first = temp1
            second = temp2