package main

import (
	"bufio"
	"fmt"
	"os"
)

// Macros for loop iterations and common operations
const (
	N = 1e5 + 10
)

// Type definitions for convenience
type LL int64

// Structure to represent an edge in the graph
type edge struct {
	to, pre, c int
}

// Array to store the head of each vertex's adjacency list
var u = make([]int, N)
var l int

// Function to insert an edge into the graph
func ins(a, b, c int) {
	e := edge{b, u[a], c}
	e[l] = e
	u[a] = l
	l++
}

// Macros for accessing edge properties
var v, ec, reg = make([]edge, N<<1), make([]int, N<<1), make([]int, N)

// Global variables
var (
	n, m           int
	vis            = make([]bool, N)
	ok             bool
	cnt            = [3]int{}
	d              = make([]int, N)
	T              int
)

// Depth-first search function to traverse the graph
func dfs(x, l int) {
	vis[x] = true
	cnt[l]++
	d[x] = l

	for i := u[x]; i != 0; i = e[i].pre {
		T++
		if !vis[v] {
			dfs(v, (l+ec[i])%3)
		} else if (l+ec[i])%3 != d[v] {
			ok = false
		}
	}
}

func main() {
	// Read the number of vertices and edges
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n = atoi(scanner.Text())
	scanner.Scan()
	m = atoi(scanner.Text())

	// Read edges and construct the graph
	for i := 1; i <= m; i++ {
		var a, b int
		scanner.Scan()
		a = atoi(scanner.Text())
		scanner.Scan()
		b = atoi(scanner.Text())
		ins(a, b, 1)
		ins(b, a, 2)
	}

	var ans LL

	// Iterate through all vertices
	for i := 1; i <= n; i++ {
		if !vis[i] {
			T = 0
			cnt = [3]int{}
			ok = true
			dfs(i, 0)

			s := LL(cnt[0] + cnt[1] + cnt[2])

			if !ok {
				ans += s * s
			} else {
				if cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0 {
					ans += LL(cnt[0])*LL(cnt[1]) + LL(cnt[1])*LL(cnt[2]) + LL(cnt[2])*LL(cnt[0])
				} else {
					ans += LL(T) / 2
				}
			}
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

func atoi(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}
