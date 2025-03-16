package main

import (
	"fmt"
	"math"
	"os"
)

func solve(n int, ls_xyh [][]int) string {
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

	cands := make([][3]int, 0)
	for cx := 0; cx <= 100; cx++ {
		for cy := 0; cy <= 100; cy++ {
			cands = append(cands, [3]int{cx, cy, h0 + int(math.Abs(float64(cx-x0))) + int(math.Abs(float64(cy-y0)))})
		}
	}

	for _, point := range ls_xyh {
		x, y, h := point[0], point[1], point[2]
		newCands := make([][3]int, 0)
		for _, ch := range cands {
			cx, cy, hh := ch[0], ch[1], ch[2]
			if max(hh-int(math.Abs(float64(cx-x)))-int(math.Abs(float64(cy-y))), 0) == h {
				newCands = append(newCands, ch)
			}
		}
		cands = newCands
	}

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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	n, ls_xyh := readQuestion()
	fmt.Println(solve(n, ls_xyh))
}

// <END-OF-CODE>
