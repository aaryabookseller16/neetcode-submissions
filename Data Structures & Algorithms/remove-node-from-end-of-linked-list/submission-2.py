# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None:
            return None

        dummy = ListNode(0, head)  # new node with value 0 and its next pointer is head

        fast = head
        slow = head
        slower = dummy  # node BEFORE slow

        # move fast n steps ahead
        for _ in range(n):
            fast = fast.next

        # move all pointers until fast hits the end
        while fast is not None:
            slower = slow          # slower follows slow
            slow = slow.next       # slow moves forward
            fast = fast.next       # fast moves forward

        # now slow is the nth from end, slower is previous
        slower.next = slow.next    # delete slow from list
        slow.next = None           # detach the node

        return dummy.next