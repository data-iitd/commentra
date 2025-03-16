package main

import (
	"fmt"
)

func main() {
	var vamshi, z int
	// Read a line of text from the standard input stream and convert it into integers
	fmt.Scan(&vamshi, &z)

	// Calculate the number of complete divisions of z into vamshi
	// Add 1 to account for the remainder
	// Multiply the result by z
	result := (vamshi/z + 1) * z
	fmt.Println(result)
}

// <END-OF-CODE>
