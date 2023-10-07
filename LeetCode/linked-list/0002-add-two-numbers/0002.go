package main

import (
	. "Algorithm/algorithm"
)

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{} // 哑节点
	current := dummy     // 当前节点
	carry := 0           // 进位

	for l1 != nil || l2 != nil {
		// 获取l1和l2的值，如果链表已经遍历完，则值为0
		x := 0
		y := 0
		if l1 != nil {
			x = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			y = l2.Val
			l2 = l2.Next
		}

		// 将l1和l2的值以及进位相加
		sum := x + y + carry

		// 更新进位
		carry = sum / 10

		// 创建新节点，并将个位数作为节点的值
		current.Next = &ListNode{Val: sum % 10}

		// 更新指针
		current = current.Next
	}

	// 如果最后一位相加后产生了进位，需要添加新节点
	if carry > 0 {
		current.Next = &ListNode{Val: carry}
	}

	return dummy.Next
}
