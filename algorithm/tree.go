package algorithm

import "container/list"

// TreeNode Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func BuildTree(rootList []int) *TreeNode {
	if len(rootList) == 0 {
		return nil
	}

	queue := list.New()
	root := &TreeNode{Val: rootList[0]}
	queue.PushBack(root)

	i := 1
	for queue.Len() > 0 {
		node := queue.Remove(queue.Front()).(*TreeNode)

		if i < len(rootList) && rootList[i] != -1 {
			node.Left = &TreeNode{Val: rootList[i]}
			queue.PushBack(node.Left)
		}
		i++

		if i < len(rootList) && rootList[i] != -1 {
			node.Right = &TreeNode{Val: rootList[i]}
			queue.PushBack(node.Right)
		}
		i++
	}

	return root
}
