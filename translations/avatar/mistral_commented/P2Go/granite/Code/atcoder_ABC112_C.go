
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of points from the first line
	reader := bufio.NewReader(os.Stdin)
	ws, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(ws))

	// Read the list of points from the second line
	ls_xyh := make([][]int, n)
	for i := 0; i < n; i++ {
		ws, _ := reader.ReadString('\n')
		ws = strings.TrimSpace(ws)
		ws_split := strings.Split(ws, " ")
		ls_xyh[i] = make([]int, 3)
		for j := 0; j < 3; j++ {
			ls_xyh[i][j], _ = strconv.Atoi(ws_split[j])
		}
	}

	// Call the solve function to get the solution
	solution := solve(n, ls_xyh)

	// Print the solution
	fmt.Println(solution)
}

func solve(n int, ls_xyh [][]int) string {
	// Initialize x0 as None
	x0 := -1

	// Iterate through the list ls_xyh to find the point with the highest height
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 { // Check if the height is positive
			x0 = i
			break
		}
	}

	// Generate a list of candidate points based on the given height and the position of x0
	cands := make([][]int, 0)
	for cx := 0; cx < 101; cx++ {
		for cy := 0; cy < 101; cy++ {
			cands = append(cands, []int{cx, cy, ls_xyh[x0][2] + abs(cx-ls_xyh[x0][0]) + abs(cy-ls_xyh[x0][1])})
		}
	}

	// Filter out the invalid candidate points based on the given height
	for i := 0; i < len(cands); i++ {
		for j := 0; j < n; j++ {
			if max(cands[i][2]-abs(cands[i][0]-ls_xyh[j][0])-abs(cands[i][1]-ls_xyh[j][1]), 0)!= ls_xyh[j][2] {
				cands = append(cands[:i], cands[i+1:]...)
				i--
				break
			}
		}
	}

	// Find the point with the minimum height among the valid candidates
	xx, yy, hh := cands[0][0], cands[0][1], cands[0][2]
	for i := 1; i < len(cands); i++ {
		if cands[i][2] < hh {
			xx, yy, hh = cands[i][0], cands[i][1], cands[i][2]
		}
	}

	// Return the solution as a string
	return fmt.Sprintf("%d %d %d", xx, yy, hh)
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

// Translate the above Go code to C++ and end with comment "