package main

import (
	. "Algorithm/algorithm/tree"
	"fmt"
	"math"
)

var result bool

func isBalanced(root *TreeNode) bool {
	result = true
	maxDepth(root)
	return result
}

func maxDepth(node *TreeNode) int {
	if node == nil {
		return 0
	}
	left := maxDepth(node.Left)
	right := maxDepth(node.Right)
	if math.Abs(float64(left-right)) > 1 {
		result = false
	}
	return int(math.Max(float64(left), float64(right))) + 1
}

func main() {
	tree := BuildTree([]int{3, 9, 20, -1, -1, 15, 7})
	fmt.Printf("%t", isBalanced(tree))
}
