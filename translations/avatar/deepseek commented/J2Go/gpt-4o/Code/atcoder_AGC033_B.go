package main

import (
	"fmt"
)

func main() {
	var h, w, n, sr, sc int
	fmt.Scan(&h, &w, &n, &sr, &sc)

	var s, t string
	fmt.Scan(&s, &t)

	// Initializing variables to track safe bounds
	end := false // Flag to check if an unsafe condition is encountered
	usafe := 1   // Safe upper bound for row
	dsafe := h   // Safe lower bound for row

	// Processing moves in reverse order for rows
	for i := n - 1; i >= 0; i-- {
		if s[i] == 'U' {
			usafe++ // Move up, increase upper safe bound
		} else if s[i] == 'D' {
			dsafe-- // Move down, decrease lower safe bound
		}
		if usafe > dsafe { // Check if upper safe bound exceeds lower safe bound
			end = true // Set end flag to true if unsafe
			break       // Break out of the loop
		}
		if i > 0 { // Check if it's not the first move
			if t[i-1] == 'U' {
				dsafe = min(dsafe+1, h) // Adjust lower safe bound if previous move was up
			} else if t[i-1] == 'D' {
				usafe = max(usafe-1, 1) // Adjust upper safe bound if previous move was down
			}
		}
	}

	// Initializing variables to track safe bounds for columns
	lsafe := 1 // Safe left bound for column
	rsafe := w // Safe right bound for column

	// Processing moves in reverse order for columns
	for i := n - 1; i >= 0; i-- {
		if s[i] == 'L' {
			lsafe++ // Move left, increase left safe bound
		} else if s[i] == 'R' {
			rsafe-- // Move right, decrease right safe bound
		}
		if lsafe > rsafe { // Check if left safe bound exceeds right safe bound
			end = true // Set end flag to true if unsafe
			break       // Break out of the loop
		}
		if i > 0 { // Check if it's not the first move
			if t[i-1] == 'L' {
				rsafe = min(rsafe+1, w) // Adjust right safe bound if previous move was left
			} else if t[i-1] == 'R' {
				lsafe = max(lsafe-1, 1) // Adjust left safe bound if previous move was right
			}
		}
	}

	// Checking if the final position is safe
	if sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end {
		fmt.Println("YES") // Output YES if safe
	} else {
		fmt.Println("NO") // Output NO if not safe
	}
}

// Helper function to get the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
