package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// min returns the minimum of two integers
func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

// Chain returns the count of remaining colors
func Chain(b []int, n int) int {
	var i, j int
	var count int // To count the number of consecutive colors
	var color int // To store the current color being processed
	var a []int // Array to hold the current state of colors

	// Copy input array b to array a
	for i = 0; i < n; i++ {
		a = append(a, b[i])
	}

	// Loop through the array to find sequences of four identical colors
	for i = 0; i < n-4; i++ {
		// Check if there are four consecutive identical colors
		if a[i]!= 0 && a[i] == a[i+1] && a[i] == a[i+2] && a[i] == a[i+3] {
			// Initialize count and set the current color
			count = 0
			color = a[i]

			// Set the found colors to zero and count them
			for j = i; a[j] == color; j++ {
				a[j] = 0 // Remove the color by setting it to zero
				count++ // Increment the count of removed colors
			}

			// Shift the remaining colors to fill the gap left by removed colors
			for j = 0; i+j+count < 10000; j++ {
				a[i+j] = a[i+j+count]
				a[i+j+count] = 0 // Set the shifted out colors to zero
			}

			// Reset the index to start checking from the beginning
			i = 0
		}
	}

	// Count the number of remaining colors in the array
	count = 0
	for count < n && a[count]!= 0 {
		count++
	}

	// Check if there are exactly four of the same color left at the start
	if count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3] {
		return 0 // Return 0 if four identical colors remain
	}

	return count // Return the count of remaining colors
}

// main is the entry point for the program
func main() {
	var n int // Number of colors
	var i, j int
	var a []int // Array to hold the colors
	var ans int // Variable to hold the answer
	var color int // Variable to store the current color being processed

	// Infinite loop to process multiple test cases
	for {
		// Initialize the array to zero
		a = make([]int, 0)

		// Read the number of colors
		fmt.Scanf("%d", &n)
		if n == 0 {
			break // Exit the loop if n is 0
		}
		ans = n // Initialize ans with the number of colors

		// Read the colors into the array
		for i = 0; i < n; i++ {
			var buf int
			fmt.Scanf("%d", &buf)
			a = append(a, buf)
		}

		// Check for groups of four colors to replace
		for i = 0; i < n-4; i++ {
			var count [3]int // Array to count occurrences of colors

			// Count occurrences of colors in the current window of four
			for j = i; j < i+4; j++ {
				if a[j]-1 >= 0 {
					count[a[j]-1]++
				}
			}

			color = 0 // Reset color
			// Determine if any color appears at least three times
			for j = 0; j < 3; j++ {
				if count[j] >= 3 {
					color = j + 1 // Set the color to replace
					break
				}
			}

			// If a color is found to replace, perform the replacement
			if color!= 0 {
				for j = i; j < i+4; j++ {
					var buf int // Temporary variable to hold the current color
					buf = a[j] // Store the current color
					a[j] = color // Replace with the new color
					ans = min(ans, Chain(a, n)) // Calculate the new answer
					a[j] = buf // Restore the original color
				}
			}
		}

		// Print the final answer for the current test case
		fmt.Printf("%d\n", ans)
	}
}

