package main

import (
	"fmt"
	"strconv"
	"strings"
)

// Define a helper function 'twosInFactorial' to count the number of twos in the factorial of a given number
func twosInFactorial(n int) int {
	return n - countOnesInBinary(n)
}

// Count the number of '1' bits in the binary representation of 'n'
func countOnesInBinary(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}

// Define a helper function 'parityOfNCr' to check if the index 'i' has odd parity in the combination 'nCr'
func parityOfNCr(n, i int) bool {
	f := twosInFactorial
	return f(n) - f(n-i) - f(i) > 0
}

func main() {
	// Read the input values from the standard input
	var n int
	fmt.Scan(&n)
	var input string
	fmt.Scan(&input)
	numsStr := strings.Split(input, " ")
	nums := make([]int, len(numsStr))

	for i, s := range numsStr {
		num, _ := strconv.Atoi(s)
		nums[i] = num - 1
	}

	// Initialize a flag to indicate if there is no '1' in the list of numbers
	noOne := false

	// If there is no '1' in the list of numbers, then replace each number by half of it
	if !containsOne(nums) {
		for i := range nums {
			nums[i] = nums[i] / 2
		}
		noOne = true
	}

	// Initialize a flag to indicate if the result is odd
	isOdd := false

	// Iterate through each number in the list and check if it satisfies the given condition
	for i, num := range nums {
		// Skip the number if it doesn't satisfy the parity condition
		if !parityOfNCr(n-1, i) && num&1 == 1 {
			// Toggle the 'isOdd' flag
			isOdd = !isOdd
		}
	}

	// Print the result based on the value of the 'isOdd' flag
	if !isOdd {
		fmt.Println(0)
	} else {
		// If there is no '1' in the list of numbers, then print the result with the 'noOne' flag shifted to the left
		if noOne {
			fmt.Println(1 << 1) // 1 shifted left by 1
		} else {
			fmt.Println(1)
		}
	}
}

// Helper function to check if the slice contains '1'
func containsOne(nums []int) bool {
	for _, num := range nums {
		if num == 1 {
			return true
		}
	}
	return false
}

// <END-OF-CODE>
