package main

import (
	"fmt"
)

func getNums(num int, t int) []int {
	// Generate a list of numbers based on the distribution of t across num parts
	result := make([]int, num)
	for i := 0; i < num; i++ {
		if i < t % num {
			result[i] = t / num + 1
		} else {
			result[i] = t / num
		}
	}
	return result
}

func main() {
	var n, k, l, r, sa, sk int
	fmt.Scan(&n, &k, &l, &r, &sa, &sk)

	// Calculate the distribution of sk among k parts and sa - sk among the remaining n - k parts
	ans := append(getNums(k, sk), getNums(n - k, sa - sk)...)

	// Print the result as a space-separated string
	for i, num := range ans {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(num)
	}
	fmt.Println()
}
