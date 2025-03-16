package main

import (
	"sort"
	"fmt"
	"bufio"
	"os"
	"strconv"
)

//=====I/O=====

// Declare scanner and writer for input and output
var (
	sc = bufio.NewScanner(os.Stdin)
	wr = bufio.NewWriter(os.Stdout)
)

// Function to scan an integer from input
func scanInt() int {
	sc.Scan() // Read the next token
	a, _ := strconv.Atoi(sc.Text()) // Convert the token to an integer
	return a // Return the integer
}

// Function to scan a 64-bit integer from input
func scanInt64() int64 {
	sc.Scan() // Read the next token
	a, _ := strconv.ParseInt(sc.Text(), 10, 64) // Convert the token to a 64-bit integer
	return a // Return the 64-bit integer
}

// Function to scan multiple integers from input
func scanInts(n int) []int {
	res := make([]int, n) // Create a slice to hold n integers
	for i := 0; i < n; i++ {
		res[i] = scanInt() // Fill the slice with integers from input
	}
	return res // Return the slice of integers
}

// Function to scan a single line of text from input
func scanText() string {
	sc.Scan() // Read the next token
	return sc.Text() // Return the text
}

// Function to print integers to output
func printInts(a ...int) {
	for i, e := range a {
		fmt.Fprint(wr, e) // Print each integer
		if i != len(a)-1 {
			fmt.Fprint(wr, " ") // Print space between integers
		}
	}
	fmt.Fprintln(wr) // Print a newline after all integers
	wr.Flush() // Flush the writer to ensure all output is written
}

//=====main=====

// Main function where execution starts
func main() {
	sc.Split(bufio.ScanWords) // Set the scanner to split input by words

	n := scanInt() // Read the number of integers

	c := scanInts(n) // Read n integers into slice c

	ans := 0 // Initialize answer variable
	sort.Ints(c) // Sort the slice of integers

	// Calculate the answer based on the sorted integers
	for i := 0; i < n; i++ {
		ans = (ans + (n+1-i)*c[i]%mod) % mod // Update the answer using the formula
	}

	// Print the final result after applying modular exponentiation
	fmt.Println(ans * modpow(4, n-1) % mod)
}

const mod = 1000000007 // Define a constant for the modulus

// Function to perform modular exponentiation
func modpow(a, n int) int {
	res := 1 // Initialize result
	for n > 0 {
		if n&1 == 1 { // If n is odd
			res = res * a % mod // Update result
		}
		a = a * a % mod // Square the base
		n = n >> 1 // Divide n by 2
	}
	return res // Return the final result
}
