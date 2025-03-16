package main

import (
	"fmt"
	"strconv"
)

var N int

// Define a function named `aaa` that takes an argument `n`
func aaa(n int) int {
	// Check if the integer value of `n` is greater than N. If it is, return 0
	if n > N {
		return 0
	}

	// Check if the digits of `n` are '7', '5', and '3'
	digits := strconv.Itoa(n)
	ans := 0
	if len(digits) == 3 && digits[0] == '7' && digits[1] == '5' && digits[2] == '3' {
		ans = 1
	}

	// Iterate over the string '753' and recursively call the function `aaa` with `n` incremented by each digit
	for _, i := range "753" {
		nextNum, _ := strconv.Atoi(digits + string(i))
		ans += aaa(nextNum)
	}

	// Return the value of `ans`
	return ans
}

func main() {
	fmt.Scan(&N) // Take an integer input N
	// Call the function `aaa` with the initial argument '0' and print the result
	fmt.Println(aaa(0))
}

// <END-OF-CODE>
