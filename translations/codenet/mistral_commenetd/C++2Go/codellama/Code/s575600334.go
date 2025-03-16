package main

import (
	"fmt"
)

// Function to print binary representation of a number
func binPrint(x, bits int) {
	// Iterate through each bit starting from the last one
	for i := bits - 1; i >= 0; i-- {
		// Print the bit value based on the bitwise AND operation with the mask (1<<i)
		fmt.Printf("%d", x&(1<<i))
	}
	// Print newline character after printing the binary number
	fmt.Println()
}

func main() {
	// Declare unsigned integer variables a and b
	var a, b uint

	// Read integer values of a and b from the standard input
	fmt.Scanf("%d %d", &a, &b)

	// Print binary representation of bitwise AND of a and b
	binPrint(int(a&b), 32)

	// Print binary representation of bitwise OR of a and b
	binPrint(int(a|b), 32)

	// Print binary representation of bitwise XOR of a and b
	binPrint(int(a^b), 32)

	// Return 0 to indicate successful execution of the program
	return 0
}

