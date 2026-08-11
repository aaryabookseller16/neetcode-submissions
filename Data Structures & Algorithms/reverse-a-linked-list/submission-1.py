# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head

        while curr:
            temp = curr.next #move the temp pointer ahead so that we do not lose the connection
            curr.next = prev # reverse the link
            prev = curr # move previous forward
            curr = temp # move temp forward

        return prev
        