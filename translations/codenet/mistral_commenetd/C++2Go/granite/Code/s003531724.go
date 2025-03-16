
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define a structure to represent an edge in the graph
type Edge struct {
	to, pre, c int
}

// Define a function to perform a depth-first search of the graph
func dfs(x, l int, vis []bool, d []int, e []Edge, u []int) {
	vis[x] = true
	d[x] = l
	cnt[l]++
	for i := u[x]; i > 0; i = e[i].pre {
		T++
		if!vis[e[i].to] {
			dfs(e[i].to, (l+e[i].c)%3, vis, d, e, u)
		} else if (l+e[i].c)%3!= d[e[i].to] {
			ok = false
		}
	}
}

// Define the main function to read the input and compute the answer
func main() {
	// Read the input n and m, where n is the number of nodes and m is the number of edges
	data, _ := os.Open("input.txt")
	defer data.Close()
	scanner := bufio.NewScanner(data)
	var n, m int
	for scanner.Scan() {
		fmt.Sscanf(scanner.Text(), "%d%d", &n, &m)
	}
	// Initialize some variables and arrays
	ans := int64(0)
	cnt := [3]int{}
	ok := true
	T := 0
	// Perform a depth-first search for each unvisited node
	vis := make([]bool, n+1)
	d := make([]int, n+1)
	e := make([]Edge, m*2+1)
	u := make([]int, n+1)
	for i := 1; i <= n; i++ {
		if!vis[i] {
			T = 0
			for j := 0; j < 3; j++ {
				cnt[j] = 0
			}
			ok = true
			// Perform a depth-first search for the current unvisited node
			dfs(i, 0, vis, d, e, u)
			s := cnt[0] + cnt[1] + cnt[2]
			// Compute the answer based on the information obtained during the depth-first search
			if!ok {
				ans += int64(s * s)
			} else {
				if cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0 {
					ans += int64(cnt[0]*cnt[1] + cnt[1]*cnt[2] + cnt[2]*cnt[0])
				} else {
					ans += int64(T / 2)
				}
			}
		}
	}
	// Output the answer and terminate the program
	fmt.Println(ans)
}

Translate the above Go code to C++ and end with comment "