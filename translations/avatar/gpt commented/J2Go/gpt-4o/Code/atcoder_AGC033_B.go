package main

import (
	"fmt"
)

func main() {
	// Read the height (h), width (w), number of moves (n), starting row (sr), and starting column (sc)
	var h, w, n, sr, sc int
	fmt.Scan(&h, &w, &n, &sr, &sc)

	// Read the strings representing the moves and the obstacles
	var s, t string
	fmt.Scan(&s, &t)

	// Initialize a flag to indicate if the position is unsafe
	end := false

	// Initialize the safe boundaries for vertical movement
	usafe := 1 // Upper safe boundary
	dsafe := h // Lower safe boundary

	// Process the vertical moves in reverse order
	for i := n - 1; i >= 0; i-- {
		// Update the safe boundaries based on the moves
		if s[i] == 'U' {
			usafe++
		} else if s[i] == 'D' {
			dsafe--
		}

		// Check if the upper safe boundary exceeds the lower safe boundary
		if usafe > dsafe {
			end = true
			break
		}

		// Adjust the safe boundaries based on the obstacles
		if i > 0 {
			if t[i-1] == 'U' {
				dsafe = min(dsafe+1, h)
			} else if t[i-1] == 'D' {
				usafe = max(usafe-1, 1)
			}
		}
	}

	// Initialize the safe boundaries for horizontal movement
	lsafe := 1 // Left safe boundary
	rsafe := w // Right safe boundary

	// Process the horizontal moves in reverse order
	for i := n - 1; i >= 0; i-- {
		// Update the safe boundaries based on the moves
		if s[i] == 'L' {
			lsafe++
		} else if s[i] == 'R' {
			rsafe--
		}

		// Check if the left safe boundary exceeds the right safe boundary
		if lsafe > rsafe {
			end = true
			break
		}

		// Adjust the safe boundaries based on the obstacles
		if i > 0 {
			if t[i-1] == 'L' {
				rsafe = min(rsafe+1, w)
			} else if t[i-1] == 'R' {
				lsafe = max(lsafe-1, 1)
			}
		}
	}

	// Check if the starting position is within the safe boundaries and not marked as unsafe
	if sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end {
		fmt.Println("YES") // Output "YES" if the position is safe
	} else {
		fmt.Println("NO") // Output "NO" if the position is unsafe
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
