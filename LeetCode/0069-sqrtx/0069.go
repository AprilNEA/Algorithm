package main

func mySqrt(x int) int {
	if x <= 1 {
		return x
	}
	var left int = 1
	var result = x
	for left <= result {
		var mid = left + (result-left)/2
		var sqrt = x / mid
		if sqrt == mid {
			return mid
		} else if mid > sqrt {
			result = mid - 1
		} else {
			left = mid + 1
		}
	}
	return result
}

func main() {
	println(mySqrt(8))
}
