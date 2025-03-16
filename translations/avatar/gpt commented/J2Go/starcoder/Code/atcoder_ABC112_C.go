package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant for the maximum coordinate value
const MAX = 100

func main() {
	// Create a buffered reader to read input from the user
	reader := bufio.NewReader(os.Stdin)

	// Read the number of points
	n, _ := strconv.Atoi(readLine(reader))

	// Initialize arrays to store x, y coordinates and heights
	x := make([]int, n)
	y := make([]int, n)
	h := make([]int, n)

	// Read the x, y coordinates and heights for each point
	for i := 0; i < n; i++ {
		line := readLine(reader)
		x[i], y[i], h[i] = parseLine(line)
	}

	// Iterate through all possible coordinates (i, j) within the defined range
	for i := 0; i <= MAX; i++ {
		for j := 0; j <= MAX; j++ {
			// Check the height at the current coordinate (i, j)
			ch := check(n, x, y, h, i, j)
			// If the height is valid (greater than 0), print the coordinates and height
			if ch > 0 {
				fmt.Println(i, j, ch)
			}
		}
	}
}

// Method to check the height at a given coordinate (cx, cy)
func check(n int, x []int, y []int, h []int, cx int, cy int) int {
	ch := -1

	// Calculate the initial height based on the first point with a positive height
	for i := 0; i < n; i++ {
		if h[i] > 0 {
			ch = abs(x[i]-cx) + abs(y[i]-cy) + h[i]
			break
		}
	}

	// Validate the height against all points
	for i := 0; i < n; i++ {
		// If the calculated height does not match the expected height, return -1
		if h[i]!= max(ch-abs(x[i]-cx)-abs(y[i]-cy), 0) {
			return -1
		}
	}

	// Return the calculated height if all checks pass
	return ch
}

// Method to read a line of input from the user
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Method to parse a line of input from the user
func parseLine(line string) (int, int, int) {
	tokens := strings.Split(line, " ")
	x, _ := strconv.Atoi(tokens[0])
	y, _ := strconv.Atoi(tokens[1])
	h, _ := strconv.Atoi(tokens[2])
	return x, y, h
}

// Method to calculate the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Method to return the maximum of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

