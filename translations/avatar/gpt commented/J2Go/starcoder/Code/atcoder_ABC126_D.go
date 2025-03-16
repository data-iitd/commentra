package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Array to store colors assigned to each point
var colors []int

// Class representing a point in the graph
type Point struct {
	name   int
	friends map[int]int
}

// Method to establish friendship with another point
func (p *Point) becomeFriend(p2 *Point, length int) {
	p.friends[p2.name] = length
}

// Depth-First Search (DFS) to assign colors based on friendship lengths
func dfs(p *Point, length int) {
	// Check if the point has already been colored
	alreadyKnown := colors[p.name]!= -1
	if alreadyKnown {
		return
	}

	// Assign color based on the length (even or odd)
	if length%2 == 0 {
		colors[p.name] = 0
	} else {
		colors[p.name] = 1
	}

	// Recursively visit all friends of the current point
	for p2, length2 := range p.friends {
		dfs(&Point{name: p2, friends: make(map[int]int)}, length+length2)
	}
}

func main() {
	// Create a scanner to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of points (nodes)
	n, _ := strconv.Atoi(scanner.Text())

	// Calculate the number of edges (m = n - 1 for a tree)
	m := n - 1

	// Initialize colors array with -1 (indicating uncolored)
	colors = make([]int, n)
	for i := 0; i < n; i++ {
		colors[i] = -1
	}

	// Create an array of Point objects
	points := make([]*Point, n)

	// Initialize each Point object with its index
	for i := 0; i < n; i++ {
		points[i] = &Point{name: i, friends: make(map[int]int)}
	}

	// Read edges and establish friendships between points
	for m > 0 {
		me, _ := strconv.Atoi(scanner.Text())
		you, _ := strconv.Atoi(scanner.Text())
		length, _ := strconv.Atoi(scanner.Text())

		// Establish friendship in both directions
		points[me-1].becomeFriend(points[you-1], length)
		points[you-1].becomeFriend(points[me-1], length)

		m--
	}

	// Start DFS from the first point (index 0)
	dfs(points[0], 0)

	// Output the colors assigned to each point
	for _, c := range colors {
		fmt.Println(c)
	}
}

