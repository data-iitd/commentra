
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input and split it into an array of strings
	scanner.Scan()
	sa := strings.Split(scanner.Text(), " ")

	// Parse the first element as an integer 'n'
	n, _ := strconv.Atoi(sa[0])

	// Read the second line of input and split it into an array of strings
	scanner.Scan()
	sa = strings.Split(scanner.Text(), " ")

	// Initialize an integer array 'c' of size 'n'
	c := make([]int, n)

	// Populate the array 'c' with integers from the input
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(sa[i])
	}

	// Close the scanner
	scanner.Close()

	// Define a modulus value for calculations
	mod := 1000000007

	// If there is only one element, calculate and print the result directly
	if n == 1 {
		fmt.Println(c[0] * 2 % mod)
		return
	}

	// Sort the array 'c' in parallel
	parallelSort(c)

	// Calculate powers of 2 for later use
	b := power(2, n)
	a := power(2, n-2)

	// Initialize the answer variable
	ans := int64(0)

	// Calculate the final answer using a loop
	for i := 2; i <= n+1; i++ {
		// Calculate the value for the current iteration
		val := a * int64(i) % int64(mod)
		val *= int64(c[n+1-i])
		val %= int64(mod)

		// Accumulate the result
		ans += val
		ans %= int64(mod)
	}

	// Multiply the accumulated answer by 'b' and take modulus
	ans *= b
	ans %= int64(mod)

	// Print the final result
	fmt.Println(ans)
}

// Method to calculate (x^n) % mod using recursion
func power(x int64, n int64) int64 {
	// Base case: x^0 = 1
	if n == 0 {
		return 1
	}

	// Define a modulus value for calculations
	mod := 1000000007

	// Recursively calculate power
	val := power(x, n/2)

	// Square the result and take modulus
	val = val * val % int64(mod)

	// If n is odd, multiply by x and take modulus
	if n%2 == 1 {
		val = val * x % int64(mod)
	}

	// Return the final result
	return val
}

// Method to sort an array in parallel
func parallelSort(arr []int) {
	// Implement parallel sorting algorithm here
}

// END-OF-CODE