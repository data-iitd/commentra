package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner from the input file
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input and split it into an array of strings
	var n int
	var c []int
	if scanner.Scan() {
		line := scanner.Text()
		tokens := strings.Split(line, " ")
		n, _ = strconv.Atoi(tokens[0])
		c = make([]int, n)
		for i := 0; i < n; i++ {
			c[i], _ = strconv.Atoi(tokens[i+1])
		}
	}

	// If there is only one element, calculate and print the result directly
	if n == 1 {
		fmt.Println((c[0] * 2) % 1000000007)
		return
	}

	// Sort the array 'c' in parallel
	sort.Ints(c)

	// Calculate powers of 2 for later use
	b := power(2, n)
	a := power(2, n-2)

	// Initialize the answer variable
	ans := 0

	// Calculate the final answer using a loop
	for i := 2; i <= n+1; i++ {
		// Calculate the value for the current iteration
		val := a * i % 1000000007
		val *= c[n+1-i]
		val %= 1000000007

		// Accumulate the result
		ans += val
		ans %= 1000000007
	}

	// Multiply the accumulated answer by 'b' and take modulus
	ans *= b
	ans %= 1000000007

	// Print the final result
	fmt.Println(ans)
}

// Method to calculate (x^n) % mod using recursion
func power(x, n int) int {
	// Base case: x^0 = 1
	if n == 0 {
		return 1
	}

	// Define a modulus value for calculations
	mod := 1000000007

	// Recursively calculate power
	val := power(x, n/2)

	// Square the result and take modulus
	val = val * val % mod

	// If n is odd, multiply by x and take modulus
	if n%2 == 1 {
		val = val * x % mod
	}

	// Return the final result
	return val
}

// 