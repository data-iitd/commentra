package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var n int
	// Input the number of digits in binary representation
	fmt.Scan(&n)

	// Initialize an empty string 's' to store binary representation
	s := ""

	// Check if the number is zero and print '0' if it is
	if n == 0 {
		fmt.Println("0")
		return
	}

	// Iterate through the number from the least significant bit to the most significant bit
	for n != 0 {
		// If the number is even, add '0' to the binary representation
		if n%2 == 0 {
			s += "0"
		} else {
			// If the number is odd, add '1' to the binary representation
			s += "1"
		}

		// Update the number by subtracting the absolute value of the remainder when the number is divided by 2 and the remainder itself
		n -= int(math.Abs(float64(n % 2)))

		// Update the number by dividing it by -2
		n /= -2
	}

	// Reverse the binary representation and print it
	reversed := reverse(s)
	fmt.Println(reversed)
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
