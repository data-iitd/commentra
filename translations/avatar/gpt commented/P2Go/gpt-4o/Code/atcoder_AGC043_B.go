package main

import (
	"fmt"
)

func twosInFactorial(n int) int {
	// Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
	return n - countOnesInBinary(n)
}

func countOnesInBinary(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}

func parityOfNCr(n, i int) bool {
	// Determine the parity (even or odd) of the binomial coefficient C(n, i)
	f := twosInFactorial // Reference to the function that calculates the number of factors of 2
	// The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
	return f(n) > f(n-i) + f(i)
}

func main() {
	var n int
	fmt.Scan(&n)
	
	var nums []int
	var input int
	for i := 0; i < n; i++ {
		fmt.Scan(&input)
		nums = append(nums, input-1) // Subtracting 1 from each input value
	}

	noOne := false // Flag to check if there are no '1's in the input list
	if !containsOne(nums) {
		// If there are no '1's, divide each number in nums by 2
		for i := range nums {
			nums[i] /= 2
		}
		noOne = true // Set the flag to True since there were no '1's
	}

	isOdd := false // Flag to track if the overall parity is odd
	for i, num := range nums {
		// Check the parity of C(n-1, i) and if num is odd
		if !parityOfNCr(n-1, i) && (num&1) == 1 {
			isOdd = !isOdd // Toggle the isOdd flag if the conditions are met
		}
	}

	// Print the result based on the parity
	if !isOdd {
		fmt.Println(0) // If the overall parity is even, print 0
	} else {
		if noOne {
			fmt.Println(2) // If odd and no '1's, print 2
		} else {
			fmt.Println(1) // If odd and there are '1's, print 1
		}
	}
}

func containsOne(nums []int) bool {
	for _, num := range nums {
		if num == 1 {
			return true
		}
	}
	return false
}

// <END-OF-CODE>
