package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Initializing scanner for reading input from standard input
func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	// Scanning the next word as a string
	t, _ := strconv.Atoi(sc.Text())
	// Converting the string to integer and returning it
	return t
}

// Defining a custom type 'point' for storing x-coordinate, left-endpoint, and right-endpoint of a segment
type point struct {
	x, l, r int
}

// Defining a slice 'ps' of type 'point' for storing all segments in sorted order based on their right-endpoints
type ps []point

// Implementing Len method for slice 'ps' to get its length
func (p ps) Len() int {
	return len(p)
}

// Implementing Swap method for slice 'ps' to swap two elements
func (p ps) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

// Implementing Less method for slice 'ps' to compare two elements based on their right-endpoints
func (p ps) Less(i, j int) bool {
	return p[i].r < p[j].r
}

// Main function starts here
func main() {
	// Initializing scanner for reading input from standard input
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	// Reading the number of segments N from the input
	N := nextInt(sc)
	// Creating a slice 'points' of type 'point' to store all segments
	points := make([]point, N)
	// Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input and storing it in 'points' slice
	for i := 0; i < N; i++ {
		points[i].x = nextInt(sc)
		// Reading left-endpoint L of the segment
		L := nextInt(sc)
		// Calculating left and right endpoints of the segment based on x-coordinate and left-endpoint
		points[i].l = points[i].x - L
		points[i].r = points[i].x + L
	}
	// Sorting 'points' slice based on their right-endpoints
	sort.Sort(ps(points))
	// Initializing variables for result calculation
	start := points[0].r
	ans := 1
	// Iterating through all segments in sorted order and updating result accordingly
	for i := 0; i < len(points); i++ {
		// If the start of current segment is less than the end of previous segment, then skip it
		if points[i].l < start {
			continue
		}
		// Updating start to the end of current segment
		start = points[i].r
		// Incrementing answer by 1
		ans++
	}
	// Printing the final answer
	fmt.Println(ans)
}

// Adding a comment at the end of the code
