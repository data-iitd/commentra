package main

import (
	"fmt"
)

func main() {
	// Declare variables for input values
	var N, K, R, S, P int
	var T string
	
	// Read input values: N (length of string), K (window size), R, S, P (points for each move)
	fmt.Scan(&N, &K, &R, &S, &P)
	fmt.Scan(&T)

	// Initialize a dictionary to count occurrences of each move
	dict := map[string]int{"r": 0, "s": 0, "p": 0}
	char := ""
	
	// Create slices to track the state of each move within the last K moves
	s := make([]bool, N) // For 's'
	r := make([]bool, N) // For 'r'
	p := make([]bool, N) // For 'p'
	
	// Initialize all moves as available (true)
	for i := 0; i < N; i++ {
		s[i] = true
	}
	copy(r, s) // Copy the initial state to r
	copy(p, s) // Copy the initial state to p
	
	// Iterate through each character in the input string T
	for i := 0; i < len(T); i++ {
		char = T[i : i+1] // Get the current character

		// Check if we are within the bounds of K
		if i >= K {
			// If the current character is the same as the character K positions back
			if char == T[i-K:i+1-K] {
				// Toggle the availability of the move based on the current character
				switch char {
				case "s":
					if s[i%K] {
						s[i%K] = false // Mark 's' as used
						continue
					} else {
						s[i%K] = true // Mark 's' as available again
					}

				case "r":
					if r[i%K] {
						r[i%K] = false // Mark 'r' as used
						continue
					} else {
						r[i%K] = true // Mark 'r' as available again
					}

				case "p":
					if p[i%K] {
						p[i%K] = false // Mark 'p' as used
						continue
					} else {
						p[i%K] = true // Mark 'p' as available again
					}
				}
			} else {
				// If the current character is different from the character K positions back
				switch char {
				case "s":
					s[i%K] = true // Mark 's' as available
				case "r":
					r[i%K] = true // Mark 'r' as available
				case "p":
					p[i%K] = true // Mark 'p' as available
				}
			}
		}

		// Count the occurrences of each move
		switch char {
		case "s":
			dict["s"] = dict["s"] + 1 // Increment count for 's'
		case "r":
			dict["r"] = dict["r"] + 1 // Increment count for 'r'
		case "p":
			dict["p"] = dict["p"] + 1 // Increment count for 'p'
		}
	}

	// Calculate the total score based on the counts and respective points
	res := P*dict["r"] + S*dict["p"] + R*dict["s"]
	
	// Print the final result
	fmt.Println(res)
}
