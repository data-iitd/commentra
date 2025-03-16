package main

import (
	"fmt"
)

// Function to print the binary representation of an integer
func binPrint(x uint32, bits int) {
	// Loop through each bit from the most significant to the least significant
	for i := bits - 1; i >= 0; i-- {
		// Print 1 if the ith bit is set, otherwise print 0
		if (x & (1 << i)) != 0 {
			fmt.Print("1")
		} else {
			fmt.Print("0")
		}
	}
	// Print a newline after the binary representation
	fmt.Println()
}

func main() {
	// Declare two unsigned integers to hold user input
	var a, b uint32

	// Read two unsigned integers from standard input
	fmt.Scan(&a, &b)

	// Print the binary representation of the bitwise AND of a and b
	binPrint(a&b, 32)

	// Print the binary representation of the bitwise OR of a and b
	binPrint(a|b, 32)

	// Print the binary representation of the bitwise XOR of a and b
	binPrint(a^b, 32)
}

// <END-OF-CODE>
