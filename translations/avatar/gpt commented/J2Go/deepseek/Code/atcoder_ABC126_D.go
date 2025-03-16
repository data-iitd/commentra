package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Array to store colors assigned to each point
var colors []int

// Depth-First Search (DFS) to assign colors based on friendship lengths
func dfs(p *Point, length int) {
	// Check if the point has already been colored
	if colors[p.name] != -1 {
		return // Exit if already colored
	}

	// Assign color based on the length (even or odd)
	if length%2 == 0 {
		colors[p.name] = 0 // Even length -> color 0
	} else {
		colors[p.name] = 1 // Odd length -> color 1
	}

	// Recursively visit all friends of the current point
	for friend, length2 := range p.friends {
		dfs(friend, length+length2) // Recursive DFS call
	}
}

// Class representing a point in the graph
type Point struct {
	name   int
	friends map[*Point]int
}

// Method to establish friendship with another point
func (p *Point) becomeFriend(friend *Point, length int) {
	p.friends[friend] = length
}

func main() {
	// Create a scanner to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of points (nodes)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Calculate the number of edges (m = n - 1 for a tree)
	m := n - 1

	// Initialize colors array with -1 (indicating uncolored)
	colors = make([]int, n)
	for i := 0; i < n; i++ {
		colors[i] = -1
	}

	// Create a slice of Point objects
	points := make([]*Point, n)

	// Initialize each Point object with its index
	for i := 0; i < n; i++ {
		points[i] = &Point{name: i, friends: make(map[*Point]int)}
	}

	// Read edges and establish friendships between points
	for i := 0; i < m; i++ {
		scanner.Scan()
		me, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		you, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		length, _ := strconv.Atoi(scanner.Text())

		// Establish friendship in both directions
		points[me-1].becomeFriend(points[you-1], length)
		points[you-1].becomeFriend(points[me-1], length)
	}

	// Start DFS from the first point (index 0)
	dfs(points[0], 0)

	// Output the colors assigned to each point
	for _, c := range colors {
		fmt.Println(c)
	}
}

