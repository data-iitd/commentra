package main

import (
	"fmt"
	"math"
)

// Define a structure to represent an edge in the graph
type edge struct {
	to   int
	pre  int
	c    int
}

// Define some variables and arrays for storing information about the graph
var (
	n, m          int
	vis           [100010]bool
	ok            bool
	cnt           [3]int
	d             [100010]int
	T             int
	e             [200010]edge
	u             [100010]int
	l             int
)

// Define a function to perform a depth-first search of the graph
func dfs(x, l int) {
	vis[x] = true
	cnt[l]++
	d[x] = l
	for i := u[x]; i != 0; i = e[i].pre {
		T++
		if !vis[e[i].to] {
			dfs(e[i].to, (l+e[i].c)%3)
		} else if (l+e[i].c)%3 != d[e[i].to] {
			ok = false
		}
	}
}

// Define the main function to read the input and compute the answer
func main() {
	// Read the input n and m, where n is the number of nodes and m is the number of edges
	fmt.Scan(&n, &m)
	// Initialize some variables and arrays
	ans := 0
	for i := 1; i <= n; i++ {
		if !vis[i] {
			T = 0
			for j := 0; j < 3; j++ {
				cnt[j] = 0
			}
			ok = true
			// Perform a depth-first search for the current unvisited node
			dfs(i, 0)
			s := cnt[0] + cnt[1] + cnt[2]
			// Compute the answer based on the information obtained during the depth-first search
			if !ok {
				ans += s * s
			} else {
				if cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0 {
					ans += cnt[0]*cnt[1] + cnt[1]*cnt[2] + cnt[2]*cnt[0]
				} else {
					ans += T / 2
				}
			}
		}
	}
	// Output the answer and terminate the program
	fmt.Println(ans)
}

