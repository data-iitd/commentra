package main

import (
	"fmt"
)

func main() {
	// Declare variables to hold scores
	var a, t, h int

	// Read the number of rounds
	fmt.Scan(&a)

	// Loop through each round
	for i := 0; i < a; i++ {
		var taro, hana string

		// Read the names of the players for the current round
		fmt.Scan(&taro, &hana)

		// Initialize scores for this round
		tt, hh := 0, 0

		// Compare the names and update scores based on the comparison
		if taro > hana {
			t += 3 // Taro wins this round
		} else if hana > taro {
			h += 3 // Hana wins this round
		} else {
			h += 1 // Tie: both get 1 point
			t += 1 // Tie: both get 1 point
		}
	}

	// Output the final scores of Taro and Hana
	fmt.Println(t, h)
}

// <END-OF-CODE>
