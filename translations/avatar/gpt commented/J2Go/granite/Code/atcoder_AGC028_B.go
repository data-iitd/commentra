
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the integer n, which represents the number of elements
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Read the next line of input and split it into an array of strings
	scanner.Scan()
	sa := scanner.Text()

	// Initialize an integer array to hold the parsed values
	a := make([]int, n)

	// Parse the string array into an integer array
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(sa[i*2 : i*2+2])
	}

	// Define a modulus value for calculations to prevent overflow
	mod := 1000000007

	// Initialize a variable to hold the factorial product
	p := int64(1)

	// Calculate the factorial of n modulo mod
	for i := 2; i <= n; i++ {
		p = p * int64(i) % int64(mod)
	}

	// Initialize an array to hold cumulative sums of modular inverses
	q := make([]int64, n)
	q[0] = 1 // Base case for the first element

	// Calculate the cumulative sum of modular inverses
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(int64(i+1), int64(mod))) % int64(mod)
	}

	// Initialize a variable to hold the final answer
	ans := int64(0)

	// Calculate the final answer using the cumulative sums and input array
	for i := 0; i < n; i++ {
		val := q[i] + q[n-i-1] - 1 // Combine values from the q array
		val *= int64(a[i]) // Multiply by the corresponding element in a
		val %= int64(mod) // Take modulo
		val *= p // Multiply by the factorial product
		val %= int64(mod) // Take modulo again
		ans += val // Add to the final answer
		ans %= int64(mod) // Take modulo to keep the answer manageable
	}

	// Print the final result
	fmt.Println(ans)
}

// Function to compute the modular inverse using the Extended Euclidean Algorithm
func modinv(a, m int64) int64 {
	b := m
	u := int64(1)
	v := int64(0)
	tmp := int64(0)

	// Apply the Extended Euclidean Algorithm
	for b > 0 {
		t := a / b
		a -= t * b
		tmp = a
		a = b
		b = tmp
		u -= t * v
		tmp = u
		u = v
		v = tmp
	}

	// Ensure u is positive and within the modulus
	u %= m
	if u < 0 {
		u += m
	}

	// Return the modular inverse
	return u
}

// END-OF-CODE