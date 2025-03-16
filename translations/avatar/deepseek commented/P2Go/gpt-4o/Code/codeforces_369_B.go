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
	extra := t % num
	for i := 0; i < num; i++ {
		if i < extra {
			result[i] = base + 1
		} else {
			result[i] = base
		}
	}
	return result
}

func main() {
	var n, k, l, r, sa, sk int
	// Read input values for n, k, l, r, sa, and sk
	fmt.Scan(&n, &k, &l, &r, &sa, &sk)

	// Use the getNums function to calculate the distribution of sk and sa - sk
	ans := append(getNums(k, sk), getNums(n-k, sa-sk)...)

	// Print the result as a space-separated string of numbers
	for i, v := range ans {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Println()
}

// <END-OF-CODE>
