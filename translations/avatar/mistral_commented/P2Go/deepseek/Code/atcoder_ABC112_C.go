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
	// Initialize x0 as -1
	var x0 int = -1

	// Iterate through the list ls_xyh to find the point with the highest height
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 { // Check if the height is positive
			x0 = ls_xyh[i][0] // Assign x0
			break
		}
	}

	// Generate a list of candidate points based on the given height and the position of x0, y0
	var cands [][]int
	for cx := 0; cx <= 100; cx++ {
		for cy := 0; cy <= 100; cy++ {
			ch := ls_xyh[0][2] + abs(cx - x0) + abs(cy - ls_xyh[0][1])
			cands = append(cands, []int{cx, cy, ch})
		}
	}

	// Filter out the invalid candidate points based on the given height
	for _, point := range ls_xyh {
		var newCands [][]int
		for _, cand := range cands {
			if max(cand[2]-abs(cand[0]-point[0])-abs(cand[1]-point[1]), 0) == point[2] {
				newCands = append(newCands, cand)
			}
		}
		cands = newCands
	}

	// Find the point with the minimum height among the valid candidates
	xx, yy, hh := cands[0][0], cands[0][1], cands[0][2]

	// Return the solution as a string
	return fmt.Sprintf("%d %d %d", xx, yy, hh)
}

// Function to read the question and return the problem data
func readQuestion() (int, [][]int) {
	// Read the first line to get the number of points
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	ws := strings.Split(line, " ")
	n, _ := strconv.Atoi(ws[0])

	// Read the second line to get the list of points
	ls_xyh := make([][]int, n)
	for j := 0; j < n; j++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		nums := strings.Split(line, " ")
		ls_xyh[j] = []int{mustInt(nums[0]), mustInt(nums[1]), mustInt(nums[2])}
	}

	// Return the problem data as a tuple (number of points, list of points)
	return n, ls_xyh
}

// Helper function to convert string to int
func mustInt(s string) int {
	num, _ := strconv.Atoi(s)
	return num
}

// Helper function to calculate absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Helper function to calculate maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
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

