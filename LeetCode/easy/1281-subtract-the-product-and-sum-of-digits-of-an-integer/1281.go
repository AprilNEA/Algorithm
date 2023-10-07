package main

import "fmt"

func subtractProductAndSum(n int) int {
	m := 1
	s := 0
	for n > 0 {
		x := n % 10
		n /= 10
		m *= x
		s += x
	}
	return m - s
}

func main() {
	fmt.Printf("%d", subtractProductAndSum(234))
}
