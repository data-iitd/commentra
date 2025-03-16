package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the console
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
				dsafe = int(math.Min(float64(dsafe+1), float64(h)))
			} else if t[i-1] == 'D' {
				usafe = int(math.Max(float64(usafe-1), float64(1)))
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
				rsafe = int(math.Min(float64(rsafe+1), float64(w)))
			} else if t[i-1] == 'R' {
				lsafe = int(math.Max(float64(lsafe-1), float64(1)))
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

