package tree

import "container/list"

// TreeNode Definition for a binary tree node.
type TreeNode struct {
	val   int
	left  *TreeNode
	right *TreeNode
}

func buildTree(rootList []int) *TreeNode {
	if len(rootList) == 0 {
		return nil
	}

	queue := list.New()
	root := &TreeNode{val: rootList[0]}
	queue.PushBack(root)

	i := 1
	for queue.Len() > 0 {
		node := queue.Remove(queue.Front()).(*TreeNode)

		if i < len(rootList) && rootList[i] != -1 {
			node.left = &TreeNode{val: rootList[i]}
			queue.PushBack(node.left)
		}
		i++

		if i < len(rootList) && rootList[i] != -1 {
			node.right = &TreeNode{val: rootList[i]}
			queue.PushBack(node.right)
		}
		i++
	}

	return root
}
