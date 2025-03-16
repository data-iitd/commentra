

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to read an integer from standard input
func nextint() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func main() {
	// Read the number of vertices n from standard input
	n := nextint()
	// Initialize 2D array a of size n x (n-1)
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, n-1)
		for j := 0; j < n-1; j++ {
			// Read an edge weight from standard input and store it in the corresponding position of array a
			a[i][j] = nextint() - 1
		}
	}
	// Initialize arrays e1, e2 and d with zeros
	e1 := make([]int, n)
	e2 := make([]int, n)
	d := make([]int, n)
	// Initialize boolean array b of size n
	b := make([]bool, n)
	// Function to perform Depth First Search (DFS) from a given vertex 'from'
	var f func(from int) int
	f = func(from int) int {
		// Check if vertex 'from' has already been visited
		if b[from] {
			return -1
		}
		// If vertex 'from' has already been processed, return its depth
		if d[from]!= 0 {
			return d[from]
		}
		// Mark vertex 'from' as visited
		b[from] = true
		// Initialize maximum depth as 0
		max := 0
		// Traverse to the adjacent vertices of 'from'
		to := e1[from]
		// If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
		if to!= 0 {
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
		if to!= 0 {
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
		return d[from] = max + 1
	}
	// Read the number of vertices n from standard input
	n = nextint()
	// Initialize 2D array a of size n x (n-1)
	a = make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, n-1)
		for j := 0; j < n-1; j++ {
			// Read an edge weight from standard input and store it in the corresponding position of array a
			a[i][j] = nextint() - 1
		}
	}
	// Initialize arrays e1, e2 and d with zeros
	e1 = make([]int, n)
	e2 = make([]int, n)
	d = make([]int, n)
	// Initialize boolean array b of size n
	b = make([]bool, n)
	// Perform Depth First Search from each vertex and update the answer with the maximum depth found
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

