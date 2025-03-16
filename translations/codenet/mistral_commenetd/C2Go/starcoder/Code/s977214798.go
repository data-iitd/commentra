
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
	e1 := make([]int, n*n)
	e2 := make([]int, n*n)
	d := make([]int, n*n)
	for i := 0; i < n; i++ {
		for j := 0; j < n-2; j++ {
			// Read an edge from standard input and store it in the corresponding position of arrays e1 or e2 based on its direction
<<<<<<< HEAD
			from := i*n + a[i][j]
			to := i*n + a[i][j+1]
=======
			from := p(i, a[i][j])
			to := p(i, a[i][j+1])
>>>>>>> 98c87cb78a (data updated)
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
<<<<<<< HEAD
		from := i*n + a[i][0]
		now := dfs(from, e1, e2, d)
		if now < 0 {
			fmt.Println("-1")
			return
=======
		from := p(i, a[i][0])
		now := f(from)
		if now < 0 {
			ans = -1
			break
>>>>>>> 98c87cb78a (data updated)
		}
		if now > ans {
			ans = now
		}
	}
	// Print the answer
	fmt.Println(ans)
}

<<<<<<< HEAD
// Function to perform Depth First Search (DFS) from a given vertex 'from'
func dfs(from int, e1, e2, d []int) int {
	// Check if vertex 'from' has already been visited
	if d[from]!= 0 {
		return d[from]
	}
	// If vertex 'from' has already been processed, return its depth
	if e1[from] == 0 && e2[from] == 0 {
		return 0
	}
	// Mark vertex 'from' as visited
	d[from] = 1
=======
// Function to calculate the result of the given expression p(a, b)
func p(a, b int) int {
	// Check if a is smaller than b
	if a < b {
		return a + b*n
	} else {
		return b + a*n
	}
}

// Function to perform Depth First Search (DFS) from a given vertex 'from'
func f(from int) int {
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
>>>>>>> 98c87cb78a (data updated)
	// Initialize maximum depth as 0
	max := 0
	// Traverse to the adjacent vertices of 'from'
	to := e1[from]
	// If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
	if to!= 0 {
<<<<<<< HEAD
		now := dfs(to, e1, e2, d)
=======
		now := f(to)
>>>>>>> 98c87cb78a (data updated)
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
<<<<<<< HEAD
		now := dfs(to, e1, e2, d)
=======
		now := f(to)
>>>>>>> 98c87cb78a (data updated)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	// Mark vertex 'from' as not visited
<<<<<<< HEAD
	d[from] = 0
=======
	b[from] = false
>>>>>>> 98c87cb78a (data updated)
	// Update the depth of vertex 'from' with the maximum depth found during DFS
	return d[from] = max + 1
}

