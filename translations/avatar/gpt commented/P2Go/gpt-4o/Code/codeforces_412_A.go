package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	var v string
	fmt.Scan(&v)

	// Define the directions for movement: LEFT and RIGHT
	d := []string{"LEFT", "RIGHT"}

	// Determine if we should move LEFT or RIGHT based on the position k
	f := k-1 < n-k

	// Calculate the minimum number of moves needed to reach the desired position
	m := min(k-1, n-k)

	// Initialize a slice to store the sequence of moves and prints
	var a []string

	// Append the necessary number of LEFT or RIGHT moves to the slice based on the calculated minimum moves
	for i := 0; i < m; i++ {
		a = append(a, d[boolToInt(!f)]) // Append the opposite direction of f
	}

	// Append the print commands for each character in the string v
	// The slicing reverses the order of characters if moving RIGHT (f is True)
	if f {
		for i := len(v) - 1; i >= 0; i-- {
			a = append(a, "PRINT "+string(v[i])) // Append the print command for the current character
			a = append(a, d[f])                  // Append the direction for the next move
		}
	} else {
		for i := 0; i < len(v); i++ {
			a = append(a, "PRINT "+string(v[i])) // Append the print command for the current character
			a = append(a, d[f])                  // Append the direction for the next move
		}
	}

	// Print the final sequence of moves and print commands, excluding the last move
	fmt.Println(strings.Join(a[:len(a)-1], "\n"))
}

// Helper function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Helper function to convert bool to int (false -> 0, true -> 1)
func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}
