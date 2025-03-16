package main

import (
	"fmt"
	"math"
)

// Function to read a single integer from input
func nextInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Function to read a list of integers from input
func nextInts() []int {
	var nums []int
	var num int
	for {
		_, err := fmt.Scan(&num)
		if err != nil {
			break
		}
		nums = append(nums, num)
	}
	return nums
}

func main() {
	// Read the number of iterations or elements
	n := nextInt()

	// Initialize a counter for odd indices
	t := 0

	// Loop through the range of n
	for i := 0; i < n; i++ {
		// Check if the current index (i + 1) is odd
		if (i+1)%2 != 0 {
			t += 1 // Increment the counter for odd indices
		}
	}

	// Calculate and print the ratio of odd indices to total elements
	fmt.Println(float64(t) / float64(n))
}
