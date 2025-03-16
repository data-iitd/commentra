package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read two integers N and P from input
	var N, P int
	fmt.Scan(&N, &P)

	// Function to calculate combinations C(N, K)
	func combi(N, K int) int {
		a := 1
		// Calculate the numerator of the combination formula
		for i := 0; i < K; i++ {
			a *= N - i
		}
		// Calculate the denominator of the combination formula
		for j := 0; j < K; j++ {
			a /= j + 1
		}
		return a
	}

	// Initialize the answer variable
	ans := 0

	// Read a list of integers from input
	var lis []int
	fmt.Scan(&lis)

	// Create a list to hold the parity (0 or 1) of each number
	ls := make([]int, len(lis))
	for a := range lis {
		// Append the remainder when divided by 2 (0 for even, 1 for odd)
		ls[a] = lis[a] % 2
	}

	// Count the number of 1s (odd numbers) and 0s (even numbers) in the list
	one := 0
	zero := 0
	for _, a := range ls {
		if a == 1 {
			one++
		} else {
			zero++
		}
	}

	// Initialize variables to count patterns
	pattern_a := 0
	pattern_b := 0

	// Calculate the total number of patterns for the even numbers
	for j := 0; j <= zero; j++ {
		pattern_b += combi(zero, j)
	}

	// Initialize a variable to track the number of odd numbers used
	time := 0

	// Loop through all possible counts of odd numbers used
	for time <= one {
		// Check if the current count of odd numbers is congruent to P modulo 2
		if time%2 == P {
			// If it is, add the number of combinations to pattern_a
			pattern_a += combi(one, time)
		}
		time++
	}

	// Print the final result, which is the product of pattern_a and pattern_b
	fmt.Println(pattern_a * pattern_b)
}

// 