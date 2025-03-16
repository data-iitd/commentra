package main

import (
	"fmt"
)

func twosInFactorial(n int) int {
	// Calculate the number of factors of 2 in the factorial of n
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
	// Determine the parity (odd or even) of the binomial coefficient nCr
	f := twosInFactorial
	return f(n) - f(n-i) - f(i) > 0
}

func main() {
	var n int
	fmt.Scan(&n)

	var nums []int
	var input int
	for {
		_, err := fmt.Scan(&input)
		if err != nil {
			break
		}
		nums = append(nums, input-1)
	}

	// If the list does not contain the number 1, halve each number in the list and set noOne to true
	noOne := false
	containsOne := false
	for _, num := range nums {
		if num == 1 {
			containsOne = true
			break
		}
	}

	if !containsOne {
		for i := range nums {
			nums[i] /= 2
		}
		noOne = true
	}

	// Initialize isOdd to false
	isOdd := false

	// Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
	for i, num := range nums {
		if !parityOfNCr(n-1, i) && num&1 == 1 {
			isOdd = !isOdd
		}
	}

	// If isOdd is false, print 0; otherwise, print 1 << noOne (which is equivalent to 2 ** noOne)
	if !isOdd {
		fmt.Println(0)
	} else {
		if noOne {
			fmt.Println(2)
		} else {
			fmt.Println(1)
		}
	}
}

// <END-OF-CODE>
