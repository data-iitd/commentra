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
	// Create a new buffered reader.
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input from stdin.
	input, _ := reader.ReadString('\n')

	// Split the input string into an array of strings.
	input = strings.Split(input, " ")

	// Parse the first element of the input array as an integer.
	n, _ := strconv.Atoi(input[0])

	// Read the second line of input from stdin.
	input, _ = reader.ReadString('\n')

	// Split the input string into an array of strings.
	input = strings.Split(input, " ")

	// Initialize an array of integers.
	c := make([]int, n)

	// Populate the array with integers from the input.
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(input[i])
	}

	// Define a modulus value for calculations.
	mod := 1000000007

	// If there is only one element, calculate and print the result directly.
	if n == 1 {
		fmt.Println(c[0]*2 % mod)
		return
	}

	// Sort the array in parallel.
	sort.Slice(c, func(i, j int) bool { return c[i] < c[j] })

	// Calculate powers of 2 for later use.
	b := power(2, n)
	a := power(2, n-2)

	// Initialize the answer variable.
	ans := 0

	// Calculate the final answer using a loop.
	for i := 2; i <= n+1; i++ {
		// Calculate the value for the current iteration.
		val := a * i % mod
		val *= c[n+1-i]
		val %= mod

		// Accumulate the result.
		ans += val
		ans %= mod
	}

	// Multiply the accumulated answer by 'b' and take modulus.
	ans *= b
	ans %= mod

	// Print the final result.
	fmt.Println(ans)
}

// Method to calculate (x^n) % mod using recursion.
func power(x, n int) int {
	// Base case: x^0 = 1.
	if n == 0 {
		return 1
	}

	// Define a modulus value for calculations.
	mod := 1000000007

	// Recursively calculate power.
	val := power(x, n/2)

	// Square the result and take modulus.
	val = val * val % mod

	// If n is odd, multiply by x and take modulus.
	if n%2 == 1 {
		val = val * x % mod
	}

	// Return the final result.
	return val
}

