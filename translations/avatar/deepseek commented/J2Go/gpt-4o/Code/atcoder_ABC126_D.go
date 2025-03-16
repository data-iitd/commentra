package main

import (
	"fmt"
)

type Point struct {
	name    int
	friends map[*Point]int
}

var colors []int

func main() {
	var n int
	fmt.Scan(&n) // Read the number of nodes
	m := n - 1   // Calculate the number of edges
	colors = make([]int, n) // Initialize the colors slice with size n
	for i := range colors {
		colors[i] = -1 // Set all colors to -1 initially
	}

	points := make([]*Point, n) // Create a slice to store the points (nodes)
	for i := 0; i < n; i++ {
		points[i] = &Point{name: i, friends: make(map[*Point]int)} // Initialize each point with its name
	}

	for m > 0 {
		m-- // Decrement the edge count
		var me, you, length int
		fmt.Scan(&me, &you, &length) // Read the edges and their lengths
		me-- // Adjust for 0-based index
		you-- // Adjust for 0-based index
		points[me].becomeFriend(points[you], length) // Update the friends list for the first node
		points[you].becomeFriend(points[me], length) // Update the friends list for the second node
	}

	dfs(points[0], 0) // Perform a DFS starting from the first point

	for _, c := range colors { // Output the color of each node
		fmt.Println(c)
	}
}

func dfs(p *Point, length int) {
	if colors[p.name] != -1 { // Check if the color of the current point is already known
		return // If the color is already known, return
	}

	if length%2 == 0 { // Check if the length of the path is even
		colors[p.name] = 0 // Color the current point as 0
	} else {
		colors[p.name] = 1 // Color the current point as 1
	}

	for friend, length2 := range p.friends { // Iterate through the friends of the current point
		dfs(friend, length+length2) // Recursively call DFS for the friend
	}
}

func (p *Point) becomeFriend(friend *Point, length int) {
	p.friends[friend] = length // Add the friend and the length of the edge
}

// <END-OF-CODE>
