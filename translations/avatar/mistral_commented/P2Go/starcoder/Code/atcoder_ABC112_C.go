package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to solve the problem
func solve(n int, ls_xyh [][]int) string {
	// Initialize x0 as None
	x0 := 0
	y0 := 0
	h0 := 0

	// Iterate through the list ls_xyh to find the point with the highest height
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 {  // Check if the height is positive
			x0 = ls_xyh[i][0]  // Assign x0, y0, and h0
			y0 = ls_xyh[i][1]
			h0 = ls_xyh[i][2]
			break
		}
	}

	// Generate a list of candidate points based on the given height and the position of x0, y0
	cands := make([][]int, 0)
	for cx := 0; cx < 101; cx++ {
		for cy := 0; cy < 101; cy++ {
			ch := h0 + abs(cx-x0) + abs(cy-y0)
			cands = append(cands, []int{cx, cy, ch})
		}
	}

	// Filter out the invalid candidate points based on the given height
	for _, xyh := range ls_xyh {
		x := xyh[0]
		y := xyh[1]
		h := xyh[2]
		cands = filter(cands, x, y, h)
	}

	// Find the point with the minimum height among the valid candidates
	xx := 0
	yy := 0
	hh := 0
	for _, cand := range cands {
		if cand[2] < hh || hh == 0 {
			xx = cand[0]
			yy = cand[1]
			hh = cand[2]
		}
	}

	// Return the solution as a string
	return fmt.Sprintf("%d %d %d", xx, yy, hh)
}

// Function to filter the candidate points based on the given height
func filter(cands [][]int, x, y, h int) [][]int {
	cands_new := make([][]int, 0)
	for _, cand := range cands {
		ch := cand[2]
		if ch > h {
			cands_new = append(cands_new, cand)
		} else if ch == h {
			cands_new = append(cands_new, cand)
		}
	}
	return cands_new
}

// Function to read the question and return the problem data
func readQuestion() (int, [][]int) {
	// Read the first line to get the number of points
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	ws := strings.Split(line, " ")
	n, _ := strconv.Atoi(ws[0])

	// Read the second line to get the list of points
	ls_xyh := make([][]int, 0)
	for j := 0; j < n; j++ {
		line, _ := reader.ReadString('\n')
		ws := strings.Split(line, " ")
		x, _ := strconv.Atoi(ws[0])
		y, _ := strconv.Atoi(ws[1])
		h, _ := strconv.Atoi(ws[2])
		ls_xyh = append(ls_xyh, []int{x, y, h})
	}

	// Return the problem data as a tuple (number of points, list of points)
	return n, ls_xyh
}

// Main function to call the solve function and print the result
func main() {
	// Call the readQuestion function to get the problem data
	n, ls_xyh := readQuestion()

	// Call the solve function to get the solution
	solution := solve(n, ls_xyh)

	// Print the solution
	fmt.Println(solution)
}

// Call the main function to start the program
func main() {
	main()
}

