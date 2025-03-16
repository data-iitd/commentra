package main

import (
	"fmt"
)

func main() {
	// Read the number of characters
	var n int
	fmt.Scan(&n)

	// Read the sequence of characters as a byte slice
	var s []byte
	fmt.Scan(&s)

	// Create an integer slice to hold the numeric representation of colors
	ns := make([]int, n)
	// Convert characters to their respective numeric values
	for i := range s {
		switch s[i] {
		case 'R':
			ns[i] = 0 // 'R' is represented as 0
		case 'G':
			ns[i] = 1 // 'G' is represented as 1
		case 'B':
			ns[i] = 2 // 'B' is represented as 2
		}
	}

	// Create a 2D slice to hold cumulative counts of each color up to each index
	rgb := make([][]int, n+1)
	rgb[0] = make([]int, 3) // Initialize the first row with zero counts

	// Populate the cumulative counts for each color
	for i := 1; i <= n; i++ {
		rgb[i] = make([]int, 3) // Initialize the current row
		for j := 0; j < 3; j++ {
			rgb[i][j] = rgb[i-1][j] // Carry forward the previous counts
		}
		rgb[i][ns[i-1]]++ // Increment the count for the current color
	}

	// Variable to hold the total count of valid triplets
	var sum int

	// Iterate through all pairs of indices to find valid triplets
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			// Check if the colors at indices i and j are different
			if ns[i] != ns[j] {
				// Determine the third color that completes the triplet
				tn := 3 - ns[i] - ns[j]
				// Count how many times the third color appears after index j
				sum += rgb[n][tn] - rgb[j+1][tn]
				// Check if the third color appears at the position k
				k := 2*j - i
				if k < n && ns[k] == tn {
					sum-- // Adjust the count if the third color is at position k
				}
			}
		}
	}

	// Output the total count of valid triplets
	fmt.Println(sum)
}
