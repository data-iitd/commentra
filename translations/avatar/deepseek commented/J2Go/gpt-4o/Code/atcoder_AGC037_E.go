package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K) // Read the integers N and K
	var S string
	fmt.Scan(&S) // Read the string S

	firstTime := true // Initialize a flag to check if it's the first time through the loop
	step := 1        // Initialize the step size

	// Main loop to manipulate the string based on the value of K
	for K > 0 {
		T := reverse(S) // Reverse the string S
		revU := S + T   // Concatenate S with its reverse
		revU = reverse(revU) // Reverse the concatenated string
		sDash := S // Initialize sDash with the original string S

		// Iterate over the reversed concatenated string to find the best substring
		for i := N; i >= 0; i -= step {
			if i+N > len(revU) {
				continue // Ensure we don't go out of bounds
			}
			tmp := revU[i : i+N] // Get a substring of length N
			if sDash > tmp { // Compare lexicographically
				sDash = tmp // Update sDash if a better substring is found
			} else {
				if !firstTime { // If it's not the first time, break the loop
					break
				}
			}
		}

		// Check if it's the first time through the loop
		if firstTime {
			firstTime = false // Set the flag to false
			if math.Pow(2, float64(K)) > float64(N) { // Check the power of 2 of K
				c := string(sDash[0]) // Get the first character of sDash
				for i := 0; i < N; i++ { // Print the character N times
					fmt.Print(c)
				}
				fmt.Println() // Print a newline
				return // Exit the program
			}
		} else {
			step *= 2 // Double the step size
		}
		K-- // Decrement K
		S = reverse(sDash) // Update S with the best substring found
	}
	fmt.Println(reverse(S)) // Print the final reversed string S
}

// Function to reverse a string
func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}
