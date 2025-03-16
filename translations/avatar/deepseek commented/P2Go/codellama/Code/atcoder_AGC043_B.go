package main

import (
	"fmt"
	"strconv"
	"strings"
)

func twosInFactorial(n int) int {
	// Calculate the number of factors of 2 in the factorial of n
	return n - strings.Count(strconv.FormatInt(int64(n), 2), "1")
}

func parityOfnCr(n, i int) bool {
	// Determine the parity (odd or even) of the binomial coefficient nCr
	f := twosInFactorial
	return f(n) - f(n-i) - f(i) > 0
}

func main() {
	// Read an integer n and a list of integers from the input
	var n int
	fmt.Scan(&n)
	var nums []int
	fmt.Scan(&nums)

	// If the list does not contain the number 1, halve each number in the list and set no_one to True
	no_one := false
	if !contains(nums, 1) {
		for i, num := range nums {
			nums[i] = num / 2
		}
		no_one = true
	}

	// Initialize is_odd to False
	is_odd := false

	// Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
	for i, num := range nums {
		if !parityOfnCr(n-1, i) && num%2 == 1 {
			is_odd = !is_odd
		}
	}

	// If is_odd is False, print 0; otherwise, print 1 << no_one (which is equivalent to 2 ** no_one)
	if !is_odd {
		fmt.Println(0)
	} else {
		fmt.Println(1 << no_one)
	}
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

