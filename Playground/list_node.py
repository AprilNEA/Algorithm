# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Create

node4 = ListNode(6)

node3 = ListNode(7, node4)

node2 = ListNode(4, node3)

node1 = ListNode(9, node2)

# Update

node2 = node1.next
node2.val = 44

# Read

node = node1
n = 3

for i in range(n - 1):
    node = node1.next

print(f"链表中第三个元素的值: {node.val}")

# Delete
node1.next = node1.next.next
