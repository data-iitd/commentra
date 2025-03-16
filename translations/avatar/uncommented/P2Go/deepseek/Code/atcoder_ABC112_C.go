package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(n int, ls_xyh [][]int) string {
	var x0, y0, h0 int
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 {
			x0, y0, h0 = ls_xyh[i][0], ls_xyh[i][1], ls_xyh[i][2]
			break
		}
	}
	cands := [][]int{}
	for cx := 0; cx <= 100; cx++ {
		for cy := 0; cy <= 100; cy++ {
			cand := []int{cx, cy, h0 + abs(cx-x0) + abs(cy-y0)}
			cands = append(cands, cand)
		}
	}
	for _, xyh := range ls_xyh {
		x, y, h := xyh[0], xyh[1], xyh[2]
		newCands := [][]int{}
		for _, cand := range cands {
			cx, cy, ch := cand[0], cand[1], cand[2]
			if max(ch-abs(cx-x)-abs(cy-y), 0) == h {
				newCands = append(newCands, cand)
			}
		}
		cands = newCands
	}
	cx, cy, ch := cands[0][0], cands[0][1], cands[0][2]
	return fmt.Sprintf("%d %d %d", cx, cy, ch)
}

func readQuestion() (int, [][]int) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	ws := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(ws[0])
	ls_xyh := [][]int{}
	for j := 0; j < n; j++ {
		scanner.Scan()
		line := strings.Split(scanner.Text(), " ")
		row := []int{}
		for _, numStr := range line {
			num, _ := strconv.Atoi(numStr)
			row = append(row, num)
		}
		ls_xyh = append(ls_xyh, row)
	}
	return n, ls_xyh
}

func main() {
	n, ls_xyh := readQuestion()
	fmt.Println(solve(n, ls_xyh))
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
