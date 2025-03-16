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
	fmt.Scan(&n)

	m := n - 1 // Number of edges for a tree
	colors = make([]int, n)
	for i := range colors {
		colors[i] = -1 // Initialize colors with -1 (uncolored)
	}

	points := make([]*Point, n)
	for i := 0; i < n; i++ {
		points[i] = &Point{name: i, friends: make(map[*Point]int)}
	}

	for m > 0 {
		m--
		var me, you, length int
		fmt.Scan(&me, &you, &length)
		me-- // Convert to 0-indexed
		you-- // Convert to 0-indexed

		points[me].becomeFriend(points[you], length)
		points[you].becomeFriend(points[me], length)
	}

	// Start DFS from the first point (index 0)
	dfs(points[0], 0)

	// Output the colors assigned to each point
	for _, c := range colors {
		fmt.Println(c)
	}
}

func dfs(p *Point, length int) {
	if colors[p.name] != -1 {
		return // Exit if already colored
	}

	if length%2 == 0 {
		colors[p.name] = 0 // Even length -> color 0
	} else {
		colors[p.name] = 1 // Odd length -> color 1
	}

	for friend, length2 := range p.friends {
		dfs(friend, length+length2) // Recursive DFS call
	}
}

func (p *Point) becomeFriend(friend *Point, length int) {
	p.friends[friend] = length // Add friend with the specified length
}

// <END-OF-CODE>
