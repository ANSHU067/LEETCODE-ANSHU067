# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # Definition for singly-linked list.



        dummy = ListNode(0)   # Dummy node to make code simple
        curr = dummy          # Pointer to build result
        carry = 0

        while l1 or l2 or carry:
            # Get values (0 if list is shorter)
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            # Add digits + carry
            total = v1 + v2 + carry
            carry = total // 10      # new carry
            digit = total % 10       # digit to store

            # Add new node
            curr.next = ListNode(digit)
            curr = curr.next

            # Move to next nodes
            if l1: l1 = l1.next
            if l2: l2 = l2.next

        return dummy.next


        