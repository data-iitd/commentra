package main

import (
	"fmt"
	"math/big"
	"sort"
	"strings"
)

func main() {
	// Read input from the console
	var n int
	fmt.Scan(&n)

	// Read the second line of input and split it into an array of strings
	var c = make([]int, n)
	var input string
	fmt.Scanln(&input)
	sa := strings.Split(input, " ")

	// Populate the array 'c' with integers from the input
	for i := 0; i < n; i++ {
		fmt.Sscan(sa[i], &c[i])
	}

	// Define a modulus value for calculations
	const mod = 1000000007

	// If there is only one element, calculate and print the result directly
	if n == 1 {
		fmt.Println((int64(c[0]) * 2) % mod)
		return
	}

	// Sort the array 'c'
	sort.Ints(c)

	// Calculate powers of 2 for later use
	b := power(2, n, mod)
	a := power(2, n-2, mod)

	// Initialize the answer variable
	var ans int64 = 0

	// Calculate the final answer using a loop
	for i := 2; i <= n+1; i++ {
		// Calculate the value for the current iteration
		val := (a * int64(i)) % mod
		val = (val * int64(c[n+1-i])) % mod

		// Accumulate the result
		ans = (ans + val) % mod
	}

	// Multiply the accumulated answer by 'b' and take modulus
	ans = (ans * b) % mod

	// Print the final result
	fmt.Println(ans)
}

// Method to calculate (x^n) % mod using recursion
func power(x, n, mod int) int64 {
	if n == 0 {
		return 1
	}

	val := power(x, n/2, mod)
	val = (val * val) % int64(mod)

	if n%2 == 1 {
		val = (val * int64(x)) % int64(mod)
	}

	return val
}
