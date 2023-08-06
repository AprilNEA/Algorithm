package main

import "fmt"

// 模拟
func nextGreatestLetter1(letters []byte, target byte) byte {
	for _, b := range letters {
		if b > target {
			return b
		}
	}
	return letters[0]
}

// 二分查找
func nextGreatestLetter(letter []byte, target byte) byte {
	n := len(letter)
	left := 0
	result := n - 1
	for left <= result {
		mid := left + (result-left)/2
		if letter[mid] <= target {
			left = result + 1
		} else {
			result = mid - 1
		}
	}
	if left < n {
		return letter[left]
	}
	return letter[0]
}

func main() {
	letters := []byte("bfg")
	target := []byte("a")
	fmt.Printf(string(nextGreatestLetter(letters, target[0])))
}
