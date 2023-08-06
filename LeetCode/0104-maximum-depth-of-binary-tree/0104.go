package main

import "fmt"

type TreeNode struct {
	val   int
	left  *TreeNode
	right *TreeNode
}

func max(a int, b int) int {
	if a >= b {
		return a
	} else {
		return b
	}
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return max(maxDepth(root.left), maxDepth(root.right)+1)
}

func main() {
	root := &TreeNode{
		val: 1,
		left: &TreeNode{
			val: 2,
			left: &TreeNode{
				val: 4,
			},
			right: &TreeNode{
				val: 5,
			},
		},
		right: &TreeNode{
			val: 3,
			right: &TreeNode{
				val: 6,
			},
		},
	}

	fmt.Println("Maximum depth:", maxDepth(root)) // Output: Maximum depth: 3

}
