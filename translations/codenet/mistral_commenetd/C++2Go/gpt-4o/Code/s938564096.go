package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

const MOD = 1e9 + 7 // Define a constant `MOD` for the purpose of modular arithmetic

func main() {
	var r int // Declare an integer variable `r` to store the value read from the standard input

	// Read an integer `r` from the standard input
	fmt.Scan(&r)

	// Calculate and print the square of `r` to the standard output
	fmt.Println(r * r)
}

// <END-OF-CODE>
