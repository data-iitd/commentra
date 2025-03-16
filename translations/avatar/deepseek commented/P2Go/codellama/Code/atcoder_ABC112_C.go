
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func solve(n int, ls_xyh [][]int) string {
	// Initialize x0 to None
	x0 := -1
	
	// Find the point with a positive height
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 {
			x0 = ls_xyh[i][0]
			y0 := ls_xyh[i][1]
			h0 := ls_xyh[i][2]
			break
		}
	}
	
	// Generate candidate points within a 101x101 grid
	cands := make([][]int, 0)
	for cx := 0; cx < 101; cx++ {
		for cy := 0; cy < 101; cy++ {
			cands = append(cands, []int{cx, cy, h0 + abs(cx - x0) + abs(cy - y0)})
		}
	}
	
	// Filter candidates to match the height of each point in ls_xyh
	for i := 0; i < n; i++ {
		x := ls_xyh[i][0]
		y := ls_xyh[i][1]
		h := ls_xyh[i][2]
		cands = filter(cands, func(cand []int) bool {
			cx := cand[0]
			cy := cand[1]
			ch := cand[2]
			return max(ch - abs(cx - x) - abs(cy - y), 0) == h
		})
	}
	
	// Return the coordinates of the center of the tower
	xx := cands[0][0]
	yy := cands[0][1]
	hh := cands[0][2]
	return fmt.Sprintf("%d %d %d", xx, yy, hh)
}

func readQuestion() (int, [][]int) {
	// Read input from stdin and parse the number of points and their coordinates and heights
	ws := strings.Split(strings.TrimSpace(string(readLine())), " ")
	n, _ := strconv.Atoi(ws[0])
	ls_xyh := make([][]int, n)
	for i := 0; i < n; i++ {
		xyh := strings.Split(strings.TrimSpace(string(readLine())), " ")
		ls_xyh[i] = make([]int, 3)
		ls_xyh[i][0], _ = strconv.Atoi(xyh[0])
		ls_xyh[i][1], _ = strconv.Atoi(xyh[1])
		ls_xyh[i][2], _ = strconv.Atoi(xyh[2])
	}
	return n, ls_xyh
}

func main() {
	// Read input, solve the problem, and print the result
	fmt.Println(solve(readQuestion()))
}

func readLine() string {
	var buf = make([]byte, 0, 1000000)
	for {
		l, p, e := bufio.NewReader(os.Stdin).ReadLine()
		if e != nil {
			panic(e)
		}
		buf = append(buf, l...)
		if !p {
			break
		}
	}
	return string(buf)
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
	res := make([][]int, 0)
	for _, l := range ls {
		if f(l) {
			res = append(res, l)
		}
	}
	return res
}

