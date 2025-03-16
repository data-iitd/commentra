package main

import (
	"fmt"
)

type Edge struct {
	id int
	to int
}

var n int
var g [][]Edge
var ans []int

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of vertices from the input
	g = make([][]Edge, n) // Creating a slice to store the graph

	for i := 0; i < n-1; i++ { // Looping through each edge to add it to the graph
		var a, b int
		fmt.Scan(&a, &b) // Reading the vertices of the edge
		a-- // Adjusting for 0-based index
		b-- // Adjusting for 0-based index
		g[a] = append(g[a], Edge{id: i, to: b}) // Adding the edge from vertex 'a' to 'b'
		g[b] = append(g[b], Edge{id: i, to: a}) // Adding the edge from vertex 'b' to 'a'
	}

	ans = make([]int, n-1) // Creating a slice of size 'n-1' to store the answer
	dfs(0, -1, -1) // Calling the DFS function to find the answer

	max := 0 // Initializing the maximum answer to 0
	for _, temp := range ans { // Looping through the slice to find the maximum answer
		if temp > max {
			max = temp
		}
	}

	fmt.Println(max) // Printing the maximum answer
	for _, c := range ans { // Printing all the answers
		fmt.Println(c)
	}
}

func dfs(to, color, parents int) { // Function to perform Depth First Search
	k := 1 // Initializing the color to 1
	for _, e := range g[to] { // Looping through each edge adjacent to the current vertex
		if e.to == parents {
			continue // Skipping the edge if it is already colored with the current color
		}
		if k == color {
			k++ // Incrementing the color if the current vertex is already colored with the same color
		}
		ans[e.id] = k // Storing the answer in the slice
		dfs(e.to, k, to) // Recursively calling the DFS function for the adjacent vertex
		k++ // Incrementing the color for the next vertex
	}
}

// <END-OF-CODE>
