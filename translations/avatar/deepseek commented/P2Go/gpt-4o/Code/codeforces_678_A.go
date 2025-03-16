package main

import (
	"fmt"
)

func main() {
	var vamshi, z int
	// Taking input from the user
	fmt.Scan(&vamshi, &z)

	// Calculating the result using integer division and addition
	result := (vamshi/z + 1) * z

	// Printing the result
	fmt.Println(result)
}

// <END-OF-CODE>
