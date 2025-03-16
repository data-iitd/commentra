package main

import (
	"fmt"
	"math"
	"strings"
)

// Function to compute the greatest common divisor (GCD) using recursion
func gcd(a, b int) int {
	if b == 0 {
		return a // Base case: if b is 0, return a
	}
	return gcd(b, a%b) // Recursive case
}

func main() {
	var n int // Variable to hold the input number

	// Read an integer from standard input
	fmt.Scan(&n)

	// Initialize an empty string to hold the binary representation
	s := ""

	// Special case: if the input number is 0, output '0' and exit
	if n == 0 {
		fmt.Println("0")
		return
	}

	// Loop to convert the number to its binary representation in a specific format
	for n != 0 {
		// Check if the current number is even or odd
		if n%2 == 0 {
			s += "0" // Append '0' for even numbers
		} else {
			s += "1" // Append '1' for odd numbers
		}

		// Adjust the number for the next iteration
		n -= int(math.Abs(float64(n % 2))) // Reduce n by 1 if it's odd
		n /= -2                              // Divide n by -2 to continue the conversion
	}

	// Reverse the string to get the correct binary representation
	s = reverse(s)

	// Output the final binary string
	fmt.Println(s)
}

// Function to reverse a string
func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// <END-OF-CODE>
