package main

import (
	"fmt"
	"math"
	"os"
)

func solve(n int, ls_xyh [][]int) string {
	// Initialize the coordinates and height of the first building with a positive height
	var x0, y0, h0 int
	found := false
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 {
			x0, y0, h0 = ls_xyh[i][0], ls_xyh[i][1], ls_xyh[i][2]
			found = true
			break
		}
	}

	if !found {
		return ""
	}

	// Generate candidate positions (cx, cy) with their corresponding heights based on the first building
	var cands [][]int
	for cx := 0; cx <= 100; cx++ {
		for cy := 0; cy <= 100; cy++ {
			ch := h0 + int(math.Abs(float64(cx-x0))) + int(math.Abs(float64(cy-y0)))
			cands = append(cands, []int{cx, cy, ch})
		}
	}

	// Filter candidates based on the height constraints from the other buildings
	for _, building := range ls_xyh {
		x, y, h := building[0], building[1], building[2]
		var newCands [][]int
		for _, cand := range cands {
			cx, cy, ch := cand[0], cand[1], cand[2]
			if int(math.Max(float64(ch-int(math.Abs(float64(cx-x))) - int(math.Abs(float64(cy-y)))), 0)) == h {
				newCands = append(newCands, cand)
			}
		}
		cands = newCands
	}

	// Select the first valid candidate position and height
	xx, yy, hh := cands[0][0], cands[0][1], cands[0][2]

	// Return the result as a space-separated string
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
	result := solve(n, ls_xyh)
	fmt.Println(result)
}

// <END-OF-CODE>
