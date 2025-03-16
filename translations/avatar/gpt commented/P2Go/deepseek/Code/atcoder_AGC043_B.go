package main

import (
	"fmt"
	"math/bits"
)

// twosInFactorial calculates the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
func twosInFactorial(n int) int {
	return n - bits.OnesCount(uint(n))
}

// parityOfNCR determines the parity (even or odd) of the binomial coefficient C(n, i)
func parityOfNCR(n, i int) bool {
	f := twosInFactorial // Reference to the function that calculates the number of factors of 2
	// The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
	return twosInFactorial(n) - twosInFactorial(n-i) - twosInFactorial(i) > 0
}

func main() {
	var n int
	// Read an integer n from input
	fmt.Scan(&n)

	// Read a list of integers, subtracting 1 from each input value
	var nums []int
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		nums = append(nums, num-1)
	}

	noOne := false // Flag to check if there are no '1's in the input list
	if !contains(nums, 1) {
		// If there are no '1's, divide each number in nums by 2
		for i := range nums {
			nums[i] /= 2
		}
		noOne = true // Set the flag to True since there were no '1's
	}

	isOdd := false // Flag to track if the overall parity is odd
	for i, num := range nums {
		// Check the parity of C(n-1, i) and if num is odd
		if !parityOfNCR(n-1, i) && num&1 == 1 {
			isOdd = !isOdd // Toggle the isOdd flag if the conditions are met
		}
	}

	// Print the result based on the parity
	if !isOdd {
		fmt.Println(0) // If the overall parity is even, print 0
	} else {
		fmt.Println(1 << noOne) // If odd, print 1 or 2 based on the noOne flag
	}
}

// contains checks if a slice contains a specific value
func contains(slice []int, value int) bool {
	for _, num := range slice {
		if num == value {
			return true
		}
	}
	return false
}

