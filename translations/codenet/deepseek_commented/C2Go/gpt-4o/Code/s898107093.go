package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of rounds

	taro := 0
	hanako := 0

	// Loop through each round
	for i := 0; i < n; i++ {
		var t, h string
		fmt.Scan(&t) // Read Tarō's string
		fmt.Scan(&h) // Read Hanako's string

		// Compare and update scores
		if strings.Compare(t, h) < 0 {
			hanako += 3 // Hanako wins
		} else if strings.Compare(t, h) > 0 {
			taro += 3 // Tarō wins
		} else {
			taro += 1 // Tie
			hanako += 1
		}
	}

	fmt.Printf("%d %d\n", taro, hanako) // Print the final scores
}

// <END-OF-CODE>
