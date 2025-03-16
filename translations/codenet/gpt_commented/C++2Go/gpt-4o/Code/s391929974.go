package main

import (
	"fmt"
)

func main() {
	var n int // Variable to store the input number
	sq := make([]int, 10000) // Slice to store squares
	fr := make([]int, 5000) // Slice to store frequency counts
	com := []int{} // Slice to store unique square values
	var tmp int // Temporary variable for calculations

	// Infinite loop to continuously read input until a zero is entered
	for {
		fmt.Scan(&n) // Read an integer from input
		if n == 0 {
			break // Exit the loop if the input is zero
		}

		// Calculate the squares of numbers from 1 to n-1 modulo n
		for i := 1; i < n; i++ {
			sq[i] = (i * i) % n
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
			if f {
				com = append(com, sq[i]) // Add to 'com' if unique
			}
		}

		// Initialize frequency slice to count occurrences of differences
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

// <END-OF-CODE>
