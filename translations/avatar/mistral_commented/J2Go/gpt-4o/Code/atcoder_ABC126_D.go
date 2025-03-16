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
	fmt.Scan(&n) // Reading the number of points 'n' from the console
	m := n - 1   // Calculating the number of friendships 'm'
	colors = make([]int, n) // Initializing the 'colors' slice with default values (0)

	points := make([]*Point, n) // Creating a slice of 'Point' pointers with size 'n'
	for i := 0; i < n; i++ { // Initializing the 'points' slice with 'Point' objects
		points[i] = &Point{name: i, friends: make(map[*Point]int)}
	}

	for m > 0 { // Reading and processing friendships between points
		m--
		var me, you, length int
		fmt.Scan(&me, &you, &length) // Reading the indices and length of the friendship
		me-- // Adjusting for 0-based index
		you-- // Adjusting for 0-based index
		points[me].becomeFriend(points[you], length) // Establishing friendship
		points[you].becomeFriend(points[me], length) // Establishing friendship
	}

	dfs(points[0], 0) // Starting Depth-First Search from the first point

	for _, c := range colors { // Printing the colors of all points
		fmt.Println(c)
	}
}

func dfs(p *Point, length int) { // Depth-First Search function
	if colors[p.name] != 0 { // Checking if the current point is already visited
		return
	}

	if length%2 == 0 { // Assigning color '0' to even-length friendships
		colors[p.name] = 1 // Using 1 to represent color '0'
	} else { // Assigning color '1' to odd-length friendships
		colors[p.name] = 2 // Using 2 to represent color '1'
	}

	for friend, length2 := range p.friends { // Iterating through the friends of the current point
		dfs(friend, length+length2) // Recursively calling DFS on the friend point
	}
}

func (p *Point) becomeFriend(friend *Point, length int) { // Function to establish a friendship
	p.friends[friend] = length // Adding the friend and their friendship length to the 'friends' map
}
