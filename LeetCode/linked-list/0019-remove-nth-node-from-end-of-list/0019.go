package _019_remove_nth_node_from_end_of_list

import (
	. "Algorithm/algorithm"
)

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummy := &ListNode{Next: head}
	left, right := dummy, dummy
	for ; n > 0; n-- {
		right = right.Next
	}
	for right.Next != nil {
		left = left.Next
		right = right.Next
	}
	left.Next = left.Next.Next
	return dummy.Next
}
