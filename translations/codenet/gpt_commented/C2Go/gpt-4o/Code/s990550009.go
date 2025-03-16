package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n int
	const maxSize = 100000
	var a [maxSize]int
	cnt := 1 // Count of segments
	var isup bool // Flag to indicate if the current segment is increasing
	issame := false // Flag to indicate if the current segment has the same values

	// Read the number of elements
	fmt.Scan(&n)

	// Read the elements into the array
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Determine the initial trend based on the first two elements
	if a[0] < a[1] {
		isup = true // Initial trend is increasing
	} else if a[0] > a[1] {
		isup = false // Initial trend is decreasing
	} else {
		issame = true // Initial elements are the same
	}

	// Iterate through the array to count segments
	for i := 1; i < n-1; i++ {
		// Handle the case where previous elements are the same
		if issame {
			if a[i] != a[i+1] {
				issame = false // Found a different value, update flag
				if a[i] < a[i+1] {
					isup = true // New trend is increasing
				} else {
					isup = false // New trend is decreasing
				}
			}
		} else {
			// Check if the current trend is maintained
			if isup && a[i] <= a[i+1] {
				// Trend is increasing and maintained
				continue
			} else if !isup && a[i] >= a[i+1] {
				// Trend is decreasing and maintained
				continue
			} else {
				// Trend has changed
				if i+2 < n {
					// Determine the new trend based on the next element
					if a[i+1] < a[i+2] {
						isup = true // New trend is increasing
					} else if a[i+1] > a[i+2] {
						isup = false // New trend is decreasing
					} else {
						issame = true // New elements are the same
					}
					cnt++ // Increment the segment count
				} else {
					cnt++ // Increment the segment count for the last element
					break // Exit the loop as we reached the end
				}
			}
		}
	}

	// Output the total number of segments
	fmt.Println(cnt)
}

// <END-OF-CODE>
