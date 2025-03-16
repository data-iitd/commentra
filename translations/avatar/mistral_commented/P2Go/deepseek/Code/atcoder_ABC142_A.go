package main

import (
	"fmt"
	"strconv"
)

// Function to read an integer input from the user
func nextInt() int {
	var input string
	fmt.Scan(&input)
	num, _ := strconv.Atoi(input)
	return num
}

// Function to read a list of integers from the user
func nextInts() []int {
	var input string
	fmt.Scan(&input)
	parts := strings.Split(input, " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

func main() {
	// Read an integer `n` from the user
	n := nextInt()
	// Initialize a variable `t` to zero
	t := 0
	// Iterate through the range of integers from 0 to n-1
	for i := 0; i < n; i++ {
		// Check if the index i is odd
		if (i + 1) % 2 == 1 {
			// If it is odd, increment the variable t by 1
			t += 1
		}
	}
	// Print the result t/n as the output
	fmt.Println(float64(t) / float64(n))
}
