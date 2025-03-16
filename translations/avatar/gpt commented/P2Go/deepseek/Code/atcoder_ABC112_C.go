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
	var x0, y0, h0 int
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 {
			x0, y0, h0 = ls_xyh[i][0], ls_xyh[i][1], ls_xyh[i][2]
			break
		}
	}

	// Generate candidate positions (cx, cy) with their corresponding heights based on the first building
	var cands [][]int
	for cx := 0; cx <= 100; cx++ {
		for cy := 0; cy <= 100; cy++ {
			ch := h0 + abs(cx - x0) + abs(cy - y0)
			cands = append(cands, []int{cx, cy, ch})
		}
	}

	// Filter candidates based on the height constraints from the other buildings
	for _, xyh := range ls_xyh {
		x, y, h := xyh[0], xyh[1], xyh[2]
		var newCands [][]int
		for _, cand := range cands {
			cx, cy, ch := cand[0], cand[1], cand[2]
			if max(ch-abs(cx-x)-abs(cy-y), 0) == h {
				newCands = append(newCands, cand)
			}
		}
		cands = newCands
	}

	// Select the first valid candidate position and height
	cx, cy, ch := cands[0][0], cands[0][1], cands[0][2]

	// Return the result as a space-separated string
	return fmt.Sprintf("%d %d %d", cx, cy, ch)
}

func readQuestion() (int, [][]int) {
	// Read input from standard input and parse the number of buildings and their properties
	reader := bufio.NewReader(os.Stdin)
	ws, _ := reader.ReadString('\n')
	ws = strings.TrimSpace(ws)
	parts := strings.Split(ws, " ")
	n, _ := strconv.Atoi(parts[0])
	var ls_xyh [][]int
	for j := 0; j < n; j++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		nums := strings.Split(line, " ")
		row := []int{}
		for _, numStr := range nums {
			num, _ := strconv.Atoi(numStr)
			row = append(row, num)
		}
		ls_xyh = append(ls_xyh, row)
	}
	return n, ls_xyh
}

func main() {
	// Execute the solve function with the input read from readQuestion and print the result
	n, ls_xyh := readQuestion()
	result := solve(n, ls_xyh)
	fmt.Println(result)
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
