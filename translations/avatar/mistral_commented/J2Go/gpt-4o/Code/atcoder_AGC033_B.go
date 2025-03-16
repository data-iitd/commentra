package main

import (
	"fmt"
)

func main() {
	var h, w, n int
	var sr, sc int
	var s, t string

	// Reading the height of the grid, width of the grid, and number of steps
	fmt.Scan(&h, &w, &n)
	// Reading the starting row and column of the safe zone
	fmt.Scan(&sr, &sc)
	// Reading the sequence of 'U' and 'D' for vertical movements
	fmt.Scan(&s)
	// Reading the sequence of 'L' and 'R' for horizontal movements
	fmt.Scan(&t)

	end := false // Variable to track if the safe zone is valid
	usafe := 1   // Upper boundary of the safe zone
	dsafe := h   // Lower boundary of the safe zone

	// Checking the vertical boundaries of the safe zone based on the sequence 's'
	for i := n - 1; i >= 0; i-- {
		if s[i] == 'U' { // If the current character is 'U', increase the upper boundary
			usafe++
		} else if s[i] == 'D' { // If the current character is 'D', decrease the lower boundary
			dsafe--
		}
		if usafe > dsafe { // If the upper boundary exceeds the lower boundary, the safe zone is invalid
			end = true
			break
		}
		if i > 0 { // Check the previous character in the sequence 't'
			if t[i-1] == 'U' {
				dsafe = min(dsafe+1, h) // Increase the lower boundary
			} else if t[i-1] == 'D' {
				usafe = max(usafe-1, 1) // Decrease the upper boundary
			}
		}
	}

	lsafe := 1 // Left boundary of the safe zone
	rsafe := w // Right boundary of the safe zone

	// Checking the horizontal boundaries of the safe zone based on the sequence 't'
	for i := n - 1; i >= 0; i-- {
		if t[i] == 'L' { // If the current character is 'L', increase the left boundary
			lsafe++
		} else if t[i] == 'R' { // If the current character is 'R', decrease the right boundary
			rsafe--
		}
		if lsafe > rsafe { // If the left boundary exceeds the right boundary, the safe zone is invalid
			end = true
			break
		}
		if i > 0 { // Check the previous character in the sequence 's'
			if s[i-1] == 'L' {
				rsafe = min(rsafe+1, w) // Increase the right boundary
			} else if s[i-1] == 'R' {
				lsafe = max(lsafe-1, 1) // Decrease the left boundary
			}
		}
	}

	// Checking if the starting position of the safe zone is within the safe zone boundaries and the safe zone is valid
	if sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
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

// <END-OF-CODE>
