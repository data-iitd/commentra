package main

import (
	"fmt"
	"math"
)

func solve(n int, ls_xyh [][]int) string {
	// Initialize x0 to -1 (indicating not found)
	x0, y0, h0 := -1, -1, -1

	// Find the point with a positive height
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 {
			x0, y0, h0 = ls_xyh[i][0], ls_xyh[i][1], ls_xyh[i][2]
			break
		}
	}

	// Generate candidate points within a 101x101 grid
	cands := make([][3]int, 0)
	for cx := 0; cx <= 100; cx++ {
		for cy := 0; cy <= 100; cy++ {
			h := h0 + int(math.Abs(float64(cx-x0))) + int(math.Abs(float64(cy-y0)))
			cands = append(cands, [3]int{cx, cy, h})
		}
	}

	// Filter candidates to match the height of each point in ls_xyh
	for _, point := range ls_xyh {
		x, y, h := point[0], point[1], point[2]
		newCands := make([][3]int, 0)
		for _, c := range cands {
			cx, cy, ch := c[0], c[1], c[2]
			if int(math.Max(float64(ch-int(math.Abs(float64(cx-x))) - int(math.Abs(float64(cy-y)))), 0)) == h {
				newCands = append(newCands, c)
			}
		}
		cands = newCands
	}

	// Return the coordinates of the center of the tower
	xx, yy, hh := cands[0][0], cands[0][1], cands[0][2]
	return fmt.Sprintf("%d %d %d", xx, yy, hh)
}

func readQuestion() (int, [][]int) {
	var n int
	fmt.Scan(&n)
	ls_xyh := make([][]int, n)
	for i := 0; i < n; i++ {
		var x, y, h int
		fmt.Scan(&x, &y, &h)
		ls_xyh[i] = []int{x, y, h}
	}
	return n, ls_xyh
}

func main() {
	n, ls_xyh := readQuestion()
	fmt.Println(solve(n, ls_xyh))
}

// <END-OF-CODE>
