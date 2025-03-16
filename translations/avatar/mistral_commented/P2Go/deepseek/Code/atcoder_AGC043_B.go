package main

import (
	"fmt"
	"math/bits"
	"strconv"
)

// Define a helper function 'twosInFactorial' to count the number of twos in the factorial of a given number
func twosInFactorial(n int) int {
	// Calculate the number of twos in the factorial of 'n' using the number of '1' bits in the binary representation of 'n'
	return n - bits.OnesCount(uint(n))
}

// Define a helper function 'parityOfNCR' to check if the index 'i' has odd parity in the combination 'nCr'
func parityOfNCR(n, i int) bool {
	// Use the 'twosInFactorial' function to calculate the number of twos in 'n', 'n-i', and 'i'
	f := twosInFactorial
	// Return true if the difference between the number of twos in 'n' and the sum of twos in 'n-i' and 'i' is greater than zero
	return f(n) - f(n-i) - f(i) > 0
}

func main() {
	// Read the input values from the standard input
	var n int
	fmt.Scan(&n)
	
	var numsStr string
	fmt.Scan(&numsStr)
	
	// Convert the input string to a slice of integers
	numsStrSlice := strings.Split(numsStr, " ")
	nums := make([]int, len(numsStrSlice))
	for i, numStr := range numsStrSlice {
		num, _ := strconv.Atoi(numStr)
		nums[i] = num - 1
	}
	
	// Initialize a flag to indicate if there is no '1' in the list of numbers
	noOne := false
	
	// If there is no '1' in the list of numbers, then replace each number by half of it
	if !contains(nums, 1) {
		for i := range nums {
			nums[i] /= 2
		}
		noOne = true
	}
	
	// Initialize a flag to indicate if the result is odd
	isOdd := false
	
	// Iterate through each number in the list and check if it satisfies the given condition
	for i, num := range nums {
		// Skip the number if it doesn't satisfy the parity condition
		if !parityOfNCR(n-1, i) && num&1 == 1 {
			// Toggle the 'isOdd' flag
			isOdd = !isOdd
		}
	}
	
	// Print the result based on the value of the 'isOdd' flag
	if !isOdd {
		fmt.Println(0)
	} else {
		// If there is no '1' in the list of numbers, then print the result with the 'noOne' flag shifted to the left
		fmt.Println(1 << noOne)
	}
}

// Helper function to check if a slice contains a specific element
func contains(slice []int, val int) bool {
	for _, num := range slice {
		if num == val {
			return true
		}
	}
	return false
}
