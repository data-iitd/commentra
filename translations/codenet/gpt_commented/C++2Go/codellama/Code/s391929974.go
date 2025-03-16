package main

import (
	"fmt"
	"math"
)

func main() {
	var n int // Variable to store the input number
	var sq [10000]int // Array to store squares
	var fr [5000]int // Array to store frequency counts
	var com []int // Slice to store unique square values
	var tmp int // Temporary variable for calculations

	// Infinite loop to continuously read input until a zero is entered
	for {
		fmt.Scan(&n) // Read an integer from input
		if n == 0 { // Exit the loop if the input is zero
			break
		}

		// Calculate the squares of numbers from 1 to n-1 modulo n
		for i := 1; i < n; i++ {
			sq[i] = int(math.Mod(float64(i*i), float64(n)))
		}
		com = com[:0] // Clear the slice for storing unique squares

		// Collect unique square values into the slice 'com'
		for i := 1; i < n; i++ {
			f := true // Flag to check if the square is unique
			for j := 0; j < len(com); j++ {
				if com[j] == sq[i] { // Check if the square is already in 'com'
					f = false // Not unique
					break
				}
			}
			if f { // Add to 'com' if unique
				com = append(com, sq[i])
			}
		}

		// Initialize frequency array to count occurrences of differences
		for i := 0; i <= (n-1)/2; i++ {
			fr[i] = 0
		}

		// Calculate the frequency of differences between unique squares
		for i := 0; i < len(com); i++ {
			for j := 0; j < len(com); j++ {
				if i != j { // Ensure we are not comparing the same element
					tmp = com[i] - com[j] // Calculate the difference
					if tmp < 0 {
						tmp += n // Adjust if negative
					}
					if tmp > (n-1)/2 {
						tmp = n - tmp // Adjust to be within the range
					}
					fr[tmp]++ // Increment the frequency count for this difference
				}
			}
		}

		// Output the frequency counts for differences from 1 to (n-1)/2
		for i := 1; i <= (n-1)/2; i++ {
			fmt.Println(fr[i])
		}
	}
}

