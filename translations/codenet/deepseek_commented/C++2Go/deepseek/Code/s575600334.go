package main

import (
	"fmt"
)

// Function to print the binary representation of an integer x with a specified number of bits
func binPrint(x int, bits int) {
	for i := bits - 1; i >= 0; i-- {
		fmt.Print(x & (1 << i) >> i)
	}
	fmt.Println()
}

func main() {
	var a, b uint
	fmt.Scan(&a, &b)  // Read two unsigned integers from standard input

	binPrint(int(a&b), 32)  // Print the binary AND of a and b
	binPrint(int(a|b), 32)  // Print the binary OR of a and b
	binPrint(int(a^b), 32)  // Print the binary XOR of a and b
}

