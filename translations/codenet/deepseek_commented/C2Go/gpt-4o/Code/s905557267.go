package main

import (
	"fmt"
)

// Function to return the smaller of two integers
func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

// Function to remove chains of four or more consecutive identical elements
func Chain(b []int, n int) int {
	var count int // To count the length of the chain
	var color int // To store the color of the chain
	a := make([]int, 10000) // Temporary array to hold the modified sequence

	// Copy the original array to a temporary array
	copy(a, b)

	// Iterate through the array to find and remove chains of four or more elements
	for i := 0; i < n-4; i++ {
		if a[i] != 0 && a[i] == a[i+1] && a[i] == a[i+2] && a[i] == a[i+3] {
			count = 0
			color = a[i]

			// Remove the chain by setting all elements to 0
			for j := i; j < n && a[j] == color; j++ {
				a[j] = 0
				count++
			}

			// Shift the remaining elements to fill the gap left by the removed chain
			for j := 0; i+j+count < 10000; j++ {
				a[i+j] = a[i+j+count]
				if i+j+count < n {
					a[i+j+count] = 0
				}
			}

			// Reset the index to start checking from the beginning
			i = -1 // Set to -1 because it will be incremented to 0 in the next iteration
		}
	}

	count = 0
	for count < n && a[count] != 0 {
		count++
	}

	// Check if the remaining sequence is a chain of four or more elements
	if count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3] {
		return 0
	}

	return count
}

// Main function to read input, process it, and print the result
func main() {
	var n int
	var ans int
	var color int

	for {
		// Initialize the array with zeros
		a := make([]int, 10000)

		// Read the number of elements
		fmt.Scan(&n)
		if n == 0 {
			break
		}
		ans = n

		// Read the elements themselves
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}

		// Iterate over possible starting points for chains of four or more elements
		for i := 0; i < n-4; i++ {
			count := [3]int{0, 0, 0} // To count occurrences of each color
			for j := i; j < i+4; j++ {
				if a[j]-1 >= 0 {
					count[a[j]-1]++
				}
			}

			color = 0
			for j := 0; j < 3; j++ {
				if count[j] >= 3 {
					color = j + 1
					break
				}
			}

			if color != 0 {
				for j := i; j < i+4; j++ {
					buf := a[j]
					a[j] = color
					ans = min(ans, Chain(a, n))
					a[j] = buf
				}
			}
		}

		// Print the minimum length after processing
		fmt.Println(ans)
	}
}

// <END-OF-CODE>
