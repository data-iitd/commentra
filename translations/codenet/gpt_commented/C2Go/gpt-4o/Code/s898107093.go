package main

import (
	"fmt"
)

func main() {
	// Declare variables for storing team names and initialize scores
	var n int
	taro, hanako := 0, 0

	// Read the number of rounds (n) from input
	fmt.Scan(&n)

	// Create slices to store team names for both players
	t := make([]string, n)
	h := make([]string, n)

	// Loop through each round to read team names and calculate scores
	for i := 0; i < n; i++ {
		// Read team names for both players
		fmt.Scan(&t[i])
		fmt.Scan(&h[i])

		// Compare team names and update scores based on the comparison
		if t[i] < h[i] {
			// If Hanako's team name is lexicographically smaller, she gets 3 points
			hanako += 3
		} else if t[i] > h[i] {
			// If Taro's team name is lexicographically larger, he gets 3 points
			taro += 3
		} else {
			// If both team names are the same, both players get 1 point
			taro += 1
			hanako += 1
		}
	}

	// Output the final scores of Taro and Hanako
	fmt.Printf("%d %d\n", taro, hanako)
}

// <END-OF-CODE>
