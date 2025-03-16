
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to count the number of digits in a given integer
func digit(n int64) int {
	res := 0 // Initialize digit count to zero
	// Loop until all digits are processed
	for n > 0 {
		res++ // Increment digit count
		n /= 10 // Remove the last digit
	}
	return res // Return the total count of digits
}

// Function to execute the main logic of the program
func run() {
	var n int64 // Variable to store the input number
	// Read a long long integer from standard input
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &n)

	// Initialize minimum digit count with the digit count of n
	min := digit(n)
	i := 1

	// Loop through all possible divisors of n
	for ; int64(i)*int64(i) <= n; i++ {
		// Skip if i is not a divisor of n
		if n%int64(i)!= 0 {
			continue
		}

		// Calculate the corresponding divisor
		a := int64(i)
		b := n / int64(i)

		// Update the minimum digit count based on the digits of the divisors
		min = int(MIN(int64(min), MAX(digit(a), digit(b))))
	}

	// Print the minimum digit count found
	fmt.Println(min)
}

// Main function to start the program execution
func main() {
	run() // Call the run function to execute the logic
}

// Define a type for 64-bit integers
type int64 int

// Macros for mathematical operations: MAX, MIN, and ABS
func MAX(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func MIN(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func ABS(a int64) int64 {
	if a > 0 {
		return a
	}
	return -a
}

// Translate the above C code to Go and end with comment "