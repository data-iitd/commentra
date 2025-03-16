
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Reading input values
	h, _ := strconv.Atoi(os.Args[1])
	w, _ := strconv.Atoi(os.Args[2])
	n, _ := strconv.Atoi(os.Args[3])
	sr, _ := strconv.Atoi(os.Args[4])
	sc, _ := strconv.Atoi(os.Args[5])

	// Reading the moves
	s := os.Args[6]
	t := os.Args[7]

	// Initializing variables to track safe bounds
	end := false
	usafe := 1
	dsafe := h

	// Processing moves in reverse order for rows
	for i := n - 1; i >= 0; i-- {
		if s[i] == 'U' {
			usafe++
		} else if s[i] == 'D' {
			dsafe--
		}
		if usafe > dsafe {
			end = true
			break
		}
		if i > 0 {
			if t[i-1] == 'U' {
				dsafe = int(math.Min(float64(dsafe+1), float64(h)))
			} else if t[i-1] == 'D' {
				usafe = int(math.Max(float64(usafe-1), float64(1)))
			}
		}
	}

	// Initializing variables to track safe bounds for columns
	lsafe := 1
	rsafe := w

	// Processing moves in reverse order for columns
	for i := n - 1; i >= 0; i-- {
		if s[i] == 'L' {
			lsafe++
		} else if s[i] == 'R' {
			rsafe--
		}
		if lsafe > rsafe {
			end = true
			break
		}
		if i > 0 {
			if t[i-1] == 'L' {
				rsafe = int(math.Min(float64(rsafe+1), float64(w)))
			} else if t[i-1] == 'R' {
				lsafe = int(math.Max(float64(lsafe-1), float64(1)))
			}
		}
	}

	// Checking if the final position is safe
	if sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

