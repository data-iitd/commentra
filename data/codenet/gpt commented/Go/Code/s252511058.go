package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// nextInt reads the next integer from the scanner and returns it.
func nextInt(sc *bufio.Scanner) int {
	sc.Scan() // Read the next token
	t, _ := strconv.Atoi(sc.Text()) // Convert the token to an integer
	return t // Return the integer value
}

// point struct represents a point with its position and its left and right bounds.
type point struct {
	x, l, r int // x is the position, l is the left bound, r is the right bound
}

// ps is a slice of point, implementing sort.Interface.
type ps []point

// Len returns the number of points in the slice.
func (p ps) Len() int {
	return len(p)
}

// Swap exchanges the points at indices i and j.
func (p ps) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

// Less reports whether the point at index i should sort before the point at index j.
func (p ps) Less(i, j int) bool {
	return p[i].r < p[j].r // Sort by the right bound
}

func main() {
	sc := bufio.NewScanner(os.Stdin) // Create a new scanner for standard input
	sc.Split(bufio.ScanWords) // Split input by whitespace
	N := nextInt(sc) // Read the number of points
	points := make([]point, N) // Create a slice to hold the points

	// Read each point's position and calculate its left and right bounds
	for i := 0; i < N; i++ {
		points[i].x = nextInt(sc) // Read the position of the point
		L := nextInt(sc) // Read the length to calculate bounds
		points[i].l = points[i].x - L // Calculate the left bound
		points[i].r = points[i].x + L // Calculate the right bound
	}

	// Sort the points based on their right bounds
	sort.Sort(ps(points))

	// Initialize the scheduling process for the interval scheduling problem
	start := points[0].r // Start with the right bound of the first point
	ans := 1 // Initialize the count of non-overlapping intervals

	// Iterate through the sorted points to count non-overlapping intervals
	for i := 0; i < len(points); i++ {
		if points[i].l < start { // If the left bound overlaps with the current start
			continue // Skip to the next point
		}
		start = points[i].r // Update the start to the right bound of the current point
		ans++ // Increment the count of non-overlapping intervals
	}

	// Output the total number of non-overlapping intervals
	fmt.Println(ans)
}
