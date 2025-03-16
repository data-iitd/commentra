
package main

import (
	"fmt"
	"os"
)

// Function to print the binary representation of an integer
func binPrint(x int, bits int) {
	// Loop through each bit from the most significant to the least significant
	for i := bits - 1; i >= 0; i-- {
		// Print 1 if the ith bit is set, otherwise print 0
		fmt.Printf("%d", x&(1<<i)>>i)
	}
	// Print a newline after the binary representation
	fmt.Println()
}

func main() {
	// Declare two unsigned integers to hold user input
	var a, b uint

	// Read two unsigned integers from standard input
	fmt.Fscanf(os.Stdin, "%d %d\n", &a, &b)

	// Print the binary representation of the bitwise AND of a and b
	binPrint(int(a&b), 32)

	// Print the binary representation of the bitwise OR of a and b
	binPrint(int(a|b), 32)

	// Print the binary representation of the bitwise XOR of a and b
	binPrint(int(a^b), 32)
}

