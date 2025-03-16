package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a BufferedReader to read input from the console
	br := bufio.NewReader(os.Stdin)

	// Read the integer n, which represents the number of elements
	n, _ := strconv.Atoi(br.ReadString('\n'))

	// Read the next line of input and split it into an array of strings
	sa := strings.Split(br.ReadString('\n'), " ")

	// Initialize an integer array to hold the parsed values
	a := make([]int, n)

	// Parse the string array into an integer array
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(sa[i])
	}

	// Define a modulus value for calculations to prevent overflow
	mod := 1000000007

	// Initialize a variable to hold the factorial product
	p := 1

	// Calculate the factorial of n modulo mod
	for i := 2; i <= n; i++ {
		p = (p * i) % mod
	}

	// Initialize an array to hold cumulative sums of modular inverses
	q := make([]int, n)
	q[0] = 1 // Base case for the first element

	// Calculate the cumulative sum of modular inverses
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(i+1, mod)) % mod
	}

	// Initialize a variable to hold the final answer
	ans := 0

	// Calculate the final answer using the cumulative sums and input array
	for i := 0; i < n; i++ {
		val := q[i] + q[n-i-1] - 1 // Combine values from the q array
		val *= a[i]                 // Multiply by the corresponding element in a
		val %= mod                  // Take modulo
		val *= p                    // Multiply by the factorial product
		val %= mod                  // Take modulo again
		ans += val                  // Add to the final answer
		ans %= mod                  // Take modulo to keep the answer manageable
	}

	// Print the final result
	fmt.Println(ans)
}

// Function to compute the modular inverse using the Extended Euclidean Algorithm
func modinv(a, m int) int {
	b := m
	u := 1
	v := 0
	tmp := 0

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

// 