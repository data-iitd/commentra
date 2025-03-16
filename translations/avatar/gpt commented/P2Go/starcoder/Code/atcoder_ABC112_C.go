package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(n int, ls_xyh [][]int) string {
	// Initialize the coordinates and height of the first building with a positive height
	x0 := 0
	y0 := 0
	h0 := 0
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 {
			x0 = ls_xyh[i][0]
			y0 = ls_xyh[i][1]
			h0 = ls_xyh[i][2]
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
	for _, xyh := range ls_xyh {
		x := xyh[0]
		y := xyh[1]
		h := xyh[2]
		cands = filterCands(cands, x, y, h)
	}

	// Select the first valid candidate position and height
	xx := cands[0][0]
	yy := cands[0][1]
	hh := cands[0][2]

	// Return the result as a space-separated string
	return fmt.Sprintf("%d %d %d", xx, yy, hh)
}

func filterCands(cands [][]int, x, y, h int) [][]int {
	newCands := make([][]int, 0)
	for _, cand := range cands {
		ch := cand[2]
		if max(ch-abs(cand[0]-x)-abs(cand[1]-y), 0) == h {
			newCands = append(newCands, cand)
		}
	}
	return newCands
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func readQuestion() (int, [][]int) {
	// Read input from standard input and parse the number of buildings and their properties
	reader := bufio.NewReader(os.Stdin)
	ws, _ := reader.ReadString('\n')
	ws = strings.TrimSpace(ws)
	ws = strings.TrimSuffix(ws, "\n")
	ws = strings.TrimSuffix(ws, "\r")
	ws = strings.TrimSuffix(ws, "\n\r")
	ws = strings.TrimSuffix(ws, "\r\n")
	ws = strings.TrimSuffix(ws, "\n\n")
	ws = strings.TrimSuffix(ws, "\n\r\n")
	ws = strings.TrimSuffix(ws, "\r\n\r")
	ws = strings.TrimSuffix(ws, "\r\n\n")
	ws = strings.TrimSuffix(ws, "\n\r\r")
	ws = strings.TrimSuffix(ws, "\r\n\r\n")
	ws = strings.TrimSuffix(ws, "\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	ws = strings.TrimSuffix(ws, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n