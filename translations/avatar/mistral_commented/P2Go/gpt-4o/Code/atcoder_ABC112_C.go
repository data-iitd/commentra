package main

import (
	"fmt"
	"math"
	"os"
)

func solve(n int, ls_xyh [][]int) string {
	var x0, y0, h0 int
	found := false

	// Iterate through the list ls_xyh to find the point with the highest height
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 { // Check if the height is positive
			x0, y0, h0 = ls_xyh[i][0], ls_xyh[i][1], ls_xyh[i][2] // Assign x0, y0, and h0
			found = true
			break
		}
	}

	if !found {
		return ""
	}

	// Generate a list of candidate points based on the given height and the position of x0, y0
	var cands [][]int
	for cx := 0; cx <= 100; cx++ {
		for cy := 0; cy <= 100; cy++ {
			cands = append(cands, []int{cx, cy, h0 + abs(cx-x0) + abs(cy-y0)})
		}
	}

	// Filter out the invalid candidate points based on the given height
	for _, point := range ls_xyh {
		x, y, h := point[0], point[1], point[2]
		var validCands [][]int
		for _, ch := range cands {
			if max(ch[2]-abs(ch[0]-x)-abs(ch[1]-y), 0) == h {
				validCands = append(validCands, ch)
			}
		}
		cands = validCands
	}

	// Find the point with the minimum height among the valid candidates
	xx, yy, hh := cands[0][0], cands[0][1], cands[0][2]

	// Return the solution as a string
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
	solution := solve(n, ls_xyh)
	fmt.Println(solution)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
