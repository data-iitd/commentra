package main

import (
	"fmt"
)

func getNums(num, t int) []int {
	// This function distributes the value t among num parts.
	// It calculates the base number for each part by dividing t by num.
	// It adds 1 to the base number for the first t % num parts.
	result := make([]int, num)
	base := t / num
	remainder := t % num
	for i := 0; i < num; i++ {
		if i < remainder {
			result[i] = base + 1
		} else {
			result[i] = base
		}
	}
	return result
}

func main() {
	// Read input values for n, k, l, r, sa, and sk
	var n, k, l, r, sa, sk int
	fmt.Scan(&n, &k, &l, &r, &sa, &sk)

	// Use the getNums function to calculate the distribution of sk and sa - sk
	ans := append(getNums(k, sk), getNums(n-k, sa-sk)...)

	// Print the result as a space-separated string of numbers
	for i, num := range ans {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(num)
	}
	fmt.Println()
}
