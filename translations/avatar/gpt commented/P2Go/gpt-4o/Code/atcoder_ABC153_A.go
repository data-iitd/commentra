package main

import (
	"fmt"
)

func main() {
	var h, a int
	// Read two integers from input
	fmt.Scan(&h, &a)

	// Calculate the number of shoes needed by performing integer division
	sho := h / a

	// Calculate the remaining height after accounting for full shoes
	am := h % a

	// If there is any remaining height, we need one additional shoe
	if am != 0 {
		sho++ // Increment the shoe count by 1 for the remaining height
	}

	// Print the total number of shoes required
	fmt.Println(sho)
}

// <END-OF-CODE>
