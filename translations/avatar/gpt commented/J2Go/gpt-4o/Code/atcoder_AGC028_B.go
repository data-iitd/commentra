package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a BufferedReader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the integer n, which represents the number of elements
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1])

	// Read the next line of input and split it into an array of strings
	saStr, _ := reader.ReadString('\n')
	sa := bufio.NewScanner(bufio.NewReaderString(saStr))
	a := make([]int, n)

	// Parse the string array into an integer array
	i := 0
	for sa.Scan() {
		for _, s := range sa.Split() {
			a[i], _ = strconv.Atoi(s)
			i++
		}
	}

	// Define a modulus value for calculations to prevent overflow
	mod := 1000000007

	// Initialize a variable to hold the factorial product
	p := int64(1)

	// Calculate the factorial of n modulo mod
	for i := 2; i <= n; i++ {
		p = p * int64(i) % mod
	}

	// Initialize an array to hold cumulative sums of modular inverses
	q := make([]int64, n)
	q[0] = 1 // Base case for the first element

	// Calculate the cumulative sum of modular inverses
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(int64(i+1), mod)) % mod
	}

	// Initialize a variable to hold the final answer
	ans := int64(0)

	// Calculate the final answer using the cumulative sums and input array
	for i := 0; i < n; i++ {
		val := (q[i] + q[n-i-1] - 1) % mod // Combine values from the q array
		val = (val * int64(a[i])) % mod    // Multiply by the corresponding element in a
		val = (val * p) % mod               // Multiply by the factorial product
		ans = (ans + val) % mod             // Add to the final answer
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

// <END-OF-CODE>
