package main

import (
	"fmt"
	"math/bits"
)

// twosInFactorial calculates the number of factors of 2 in the factorial of n
func twosInFactorial(n int) int {
	// Calculate the number of factors of 2 in the factorial of n
	return n - bits.OnesCount(uint(n))
}

// parityOfNCR determines the parity (odd or even) of the binomial coefficient nCr
func parityOfNCR(n, i int) bool {
	// Determine the parity of the binomial coefficient nCr
	f := twosInFactorial
	return f(n) - f(n-i) - f(i) > 0
}

func main() {
	// Read an integer n and a list of integers from the input
	var n int
	fmt.Scan(&n)

	var nums []int
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		nums = append(nums, num-1)
	}

	// If the list does not contain the number 1, halve each number in the list and set noOne to true
	noOne := false
	if !contains(nums, 1) {
		for i := range nums {
			nums[i] /= 2
		}
		noOne = true
	}

	// Initialize isOdd to false
	isOdd := false

	// Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
	for i, num := range nums {
		if !parityOfNCR(n-1, i) && num&1 == 1 {
			isOdd = !isOdd
		}
	}

	// If isOdd is false, print 0; otherwise, print 1 << noOne (which is equivalent to 2 ** noOne)
	if !isOdd {
		fmt.Println(0)
	} else {
		fmt.Println(1 << noOne)
	}
}

// contains checks if a slice contains a specific element
func contains(slice []int, val int) bool {
	for _, num := range slice {
		if num == val {
			return true
		}
	}
	return false
}

