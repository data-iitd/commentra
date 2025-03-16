package main

import (
	"fmt"
	"math"
)

func main() {
	var h, w, n, sr, sc int
	fmt.Scan(&h, &w, &n, &sr, &sc)
	var s, t string
	fmt.Scan(&s, &t)

	end := false
	usafe := 1
	dsafe := h

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
				usafe = int(math.Max(float64(usafe-1), 1))
			}
		}
	}

	lsafe := 1
	rsafe := w

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
				lsafe = int(math.Max(float64(lsafe-1), 1))
			}
		}
	}

	if sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
