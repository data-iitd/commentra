package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(n int, ls_xyh [][]int) string {
	// Initialize x0 to None
	var x0 int
	var y0 int
	var h0 int

	// Find the point with a positive height
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 {
			x0 = ls_xyh[i][0]
			y0 = ls_xyh[i][1]
			h0 = ls_xyh[i][2]
			break
		}
	}

	// Generate candidate points within a 101x101 grid
	var cands [][]int
	for cx := 0; cx < 101; cx++ {
		for cy := 0; cy < 101; cy++ {
			ch := h0 + abs(cx - x0) + abs(cy - y0)
			cands = append(cands, []int{cx, cy, ch})
		}
	}

	// Filter candidates to match the height of each point in ls_xyh
	for _, point := range ls_xyh {
		x := point[0]
		y := point[1]
		h := point[2]
		var newCands [][]int
		for _, cand := range cands {
			cx := cand[0]
			cy := cand[1]
			ch := cand[2]
			if max(ch-abs(cx-x)-abs(cy-y), 0) == h {
				newCands = append(newCands, cand)
			}
		}
		cands = newCands
	}

	// Return the coordinates of the center of the tower
	cx := cands[0][0]
	cy := cands[0][1]
	ch := cands[0][2]
	return fmt.Sprintf("%d %d %d", cx, cy, ch)
}

func readQuestion() (int, [][]int) {
	// Read input from stdin and parse the number of points and their coordinates and heights
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	ws := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(ws[0])
	var ls_xyh [][]int
	for j := 0; j < n; j++ {
		line, _ := reader.ReadString('\n')
		nums := strings.Split(strings.TrimSpace(line), " ")
		numsInt := []int{}
		for _, numStr := range nums {
			num, _ := strconv.Atoi(numStr)
			numsInt = append(numsInt, num)
		}
		ls_xyh = append(ls_xyh, numsInt)
	}
	return n, ls_xyh
}

func main() {
	// Read input, solve the problem, and print the result
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
