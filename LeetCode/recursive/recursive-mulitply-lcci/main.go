package main

import "fmt"

func multiply(A int, B int) int {
	if A < B {
		A, B = B, A
	}
	var dfs func(x int) int
	dfs = func(x int) int {
		if B == 1 {
			return x
		}
		B--
		return x + dfs(x)
	}
	return dfs(A)
}

func main() {
	fmt.Printf("%d", multiply(1, 2))
}
