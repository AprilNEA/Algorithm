package main

import "fmt"

func romanToInt(s string) int {
	valueMap := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	sum := 0
	preNum := valueMap[s[0]]
	for i := 1; i < len(s); i++ {
		num := valueMap[s[i]]
		if preNum < num {
			sum -= preNum
		} else {
			sum += preNum
		}
		preNum = num
	}
	sum += preNum
	return sum
}

func main() {
	result := romanToInt("MCMXCIV") // Example input
	fmt.Println(result)
}
