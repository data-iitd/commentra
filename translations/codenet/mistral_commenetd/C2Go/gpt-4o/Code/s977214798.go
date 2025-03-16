package main

import (
	"fmt"
	"math"
)

var (
	n   int
	a   [1000][999]int
	e1  [1000000]int
	e2  [1000000]int
	d   [1000000]int
	b   [1000000]bool
)

// Function to read an integer from standard input
func nextInt() int {
	var x int
	_, err := fmt.Scan(&x)
	if err != nil {
		panic(err)
	}
	return x
}

// Function to calculate the result of the given expression p(a, b)
func p(a, b int) int {
	if a < b {
		return a + b*n
	}
	return b + a*n
}

// Function to perform Depth First Search (DFS) from a given vertex 'from'
func f(from int) int {
	// Check if vertex 'from' has already been visited
	if b[from] {
		return -1
	}
	// If vertex 'from' has already been processed, return its depth
	if d[from] != 0 {
		return d[from]
	}
	// Mark vertex 'from' as visited
	b[from] = true
	// Initialize maximum depth as 0
	max := 0
	// Traverse to the adjacent vertices of 'from'
	to := e1[from]
	// If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
	if to != 0 {
		now := f(to)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	// Traverse to the next adjacent vertex of 'from'
	to = e2[from]
	// If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
	if to != 0 {
		now := f(to)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	// Mark vertex 'from' as not visited
	b[from] = false
	// Update the depth of vertex 'from' with the maximum depth found during DFS
	d[from] = max + 1
	return d[from]
}

func main() {
	// Read the number of vertices n from standard input
	n = nextInt()
	// Initialize 2D array a of size n x (n-1)
	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			// Read an edge weight from standard input and store it in the corresponding position of array a
			a[i][j] = nextInt() - 1
		}
	}
	// Initialize arrays e1, e2 and d with zeros
	for i := 0; i < n; i++ {
		for j := 0; j < n-2; j++ {
			// Read an edge from standard input and store it in the corresponding position of arrays e1 or e2 based on its direction
			from := p(i, a[i][j])
			to := p(i, a[i][j+1])
			if e1[from] == 0 {
				e1[from] = to
			} else if e2[from] == 0 {
				e2[from] = to
			} else {
				// If there is a cycle in the graph, print '-1' and exit the program
				fmt.Println("-1")
				return
			}
		}
	}
	// Initialize an empty stack or array to store the vertices in Depth First Search order
	ans := 0
	// Perform Depth First Search from each vertex and update the answer with the maximum depth found
	for i := 0; i < n; i++ {
		from := p(i, a[i][0])
		now := f(from)
		if now < 0 {
			ans = -1
			break
		}
		if now > ans {
			ans = now
		}
	}
	// Print the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
