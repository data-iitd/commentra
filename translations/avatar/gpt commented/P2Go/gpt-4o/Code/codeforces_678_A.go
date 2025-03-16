package main

import (
	"fmt"
)

func main() {
	var vamshi, z int
	// Read two integers from input, separated by a space
	fmt.Scan(&vamshi, &z)

	// Calculate the smallest multiple of z that is greater than or equal to vamshi
	result := (vamshi/z + 1) * z

	// Print the result
	fmt.Println(result)
}

// <END-OF-CODE>
