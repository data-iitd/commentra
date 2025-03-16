package main

import (
	"fmt"
	"math/big"
	"sort"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the first integer n

	var c = make([]int, n) // Initializing a slice of size n to store the integers
	var input string
	fmt.Scanln(&input) // Reading the second line
	sa := strings.Split(input, " ") // Splitting the input by spaces

	for i := 0; i < n; i++ {
		fmt.Sscan(sa[i], &c[i]) // Parsing each element and storing it in the slice c
	}

	mod := int64(1000000007) // Defining the modulo value
	if n == 1 {
		fmt.Println((int64(c[0]) * 2) % mod) // If n is 1, print the result directly
		return // Exit the program as no further computation is needed
	}

	sort.Ints(c) // Sorting the slice c in ascending order

	b := power(2, n, mod) // Calculating 2^n
	a := power(2, n-2, mod) // Calculating 2^(n-2)
	var ans int64 = 0 // Initializing the answer variable

	// Calculating the final answer
	for i := 2; i <= n+1; i++ {
		val := (a * int64(i)) % mod // Intermediate calculation
		val = (val * int64(c[n+1-i])) % mod // Intermediate calculation
		ans = (ans + val) % mod // Adding to the answer
	}
	ans = (ans * b) % mod // Multiplying the answer by b
	fmt.Println(ans) // Printing the final result
}

// Function to calculate x^n % mod
func power(x, n int, mod int64) int64 {
	if n == 0 {
		return 1 // Base case: x^0 is 1
	}
	val := power(x, n/2, mod) // Recursive call to calculate x^(n/2)
	val = (val * val) % mod // Squaring the result
	if n%2 == 1 {
		val = (val * int64(x)) % mod // Multiplying by x if n is odd
	}
	return val // Returning the result
}
