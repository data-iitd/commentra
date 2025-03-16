// Package main is the entry point of the program.
package main

// Importing the fmt package for printing the output
import "fmt"

// Function to solve the problem
func solve(n int, ls_xyh [][]int) string {
	// Initialize x0 as None
	x0 := -1

	// Iterate through the list ls_xyh to find the point with the highest height
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 { // Check if the height is positive
			x0 = ls_xyh[i][0]
			y0 := ls_xyh[i][1]
			h0 := ls_xyh[i][2]
			break
		}
	}

	// Generate a list of candidate points based on the given height and the position of x0, y0
	cands := make([][]int, 0)
	for cx := 0; cx < 101; cx++ {
		for cy := 0; cy < 101; cy++ {
			cands = append(cands, []int{cx, cy, h0 + abs(cx-x0) + abs(cy-y0)})
		}
	}

	// Filter out the invalid candidate points based on the given height
	for i := 0; i < n; i++ {
		[x, y, h] := ls_xyh[i]
		cands = filter(cands, func(cand []int) bool {
			return max(cand[2]-abs(cand[0]-x)-abs(cand[1]-y), 0) == h
		})
	}

	// Find the point with the minimum height among the valid candidates
	[xx, yy, hh] := cands[0]

	// Return the solution as a string
	return fmt.Sprintf("%d %d %d", xx, yy, hh)
}

// Function to read the question and return the problem data
func readQuestion() (int, [][]int) {
	// Read the first line to get the number of points
	ws := strings.Split(strings.TrimSpace(readLine()), " ")
	n, _ := strconv.Atoi(ws[0])

	// Read the second line to get the list of points
	ls_xyh := make([][]int, 0)
	for j := 0; j < n; j++ {
		xyh := strings.Split(strings.TrimSpace(readLine()), " ")
		ls_xyh = append(ls_xyh, []int{atoi(xyh[0]), atoi(xyh[1]), atoi(xyh[2])})
	}

	// Return the problem data as a tuple (number of points, list of points)
	return n, ls_xyh
}

// Function to read a line from standard input
func readLine() string {
	var line string
	fmt.Scanln(&line)
	return line
}

// Function to convert a string to an integer
func atoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

// Function to find the absolute value of a number
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Function to find the maximum of two numbers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// Function to filter a list based on a condition
func filter(ls [][]int, f func([]int) bool) [][]int {
	result := make([][]int, 0)
	for _, v := range ls {
		if f(v) {
			result = append(result, v)
		}
	}
	return result
}

// Main function to call the solve function and print the result
func main() {
	// Call the readQuestion function to get the problem data
	data := readQuestion()

	// Call the solve function to get the solution
	solution := solve(data[0], data[1])

	// Print the solution
	fmt.Println(solution)
}

// 