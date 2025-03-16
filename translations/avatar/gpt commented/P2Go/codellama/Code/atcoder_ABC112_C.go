
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func solve(n int, ls_xyh [][]int) string {
	// Initialize the coordinates and height of the first building with a positive height
	x0 := -1
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 {
			x0 = ls_xyh[i][0]
			y0 := ls_xyh[i][1]
			h0 := ls_xyh[i][2]
			break
		}
	}

	// Generate candidate positions (cx, cy) with their corresponding heights based on the first building
	cands := make([][]int, 0)
	for cx := 0; cx < 101; cx++ {
		for cy := 0; cy < 101; cy++ {
			cands = append(cands, []int{cx, cy, h0 + abs(cx-x0) + abs(cy-y0)})
		}
	}

	// Filter candidates based on the height constraints from the other buildings
	for i := 0; i < n; i++ {
		x := ls_xyh[i][0]
		y := ls_xyh[i][1]
		h := ls_xyh[i][2]
		cands = filter(cands, func(cand []int) bool {
			cx := cand[0]
			cy := cand[1]
			ch := cand[2]
			return max(ch-abs(cx-x)-abs(cy-y), 0) == h
		})
	}

	// Select the first valid candidate position and height
	xx := cands[0][0]
	yy := cands[0][1]
	hh := cands[0][2]

	// Return the result as a space-separated string
	return strconv.Itoa(xx) + " " + strconv.Itoa(yy) + " " + strconv.Itoa(hh)
}

func readQuestion() (int, [][]int) {
	// Read input from standard input and parse the number of buildings and their properties
	ws := strings.Split(strings.TrimSpace(readLine()), " ")
	n, _ := strconv.Atoi(ws[0])
	ls_xyh := make([][]int, n)
	for i := 0; i < n; i++ {
		xyh := strings.Split(strings.TrimSpace(readLine()), " ")
		ls_xyh[i] = make([]int, 3)
		ls_xyh[i][0], _ = strconv.Atoi(xyh[0])
		ls_xyh[i][1], _ = strconv.Atoi(xyh[1])
		ls_xyh[i][2], _ = strconv.Atoi(xyh[2])
	}
	return n, ls_xyh
}

func main() {
	// Execute the solve function with the input read from readQuestion and print the result
	fmt.Println(solve(readQuestion()))
}

func readLine() string {
	var line string
	if _, err := fmt.Scan(&line); err != nil {
		panic(err)
	}
	return line
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func filter(ls [][]int, f func([]int) bool) [][]int {
	result := make([][]int, 0)
	for _, l := range ls {
		if f(l) {
			result = append(result, l)
		}
	}
	return result
}

