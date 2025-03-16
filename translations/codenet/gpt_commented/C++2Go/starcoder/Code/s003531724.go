package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Constants
const N = 1e5 + 10

// Type definitions
type edge struct {
	to, pre, c int
}

// Global variables
var (
	n, m int
	u    [N]int
	e    [N << 1]edge
	vis  [N]bool
	cnt  [3]int
	d    [N]int
	T    int
	ok   bool
)

// Function to insert an edge into the graph
func ins(a, b, c int) {
	e[l] = edge{b, u[a], c}
	u[a] = l
	l++
}

// Function to traverse the graph
func dfs(x, l int) {
	vis[x] = true
	cnt[l]++
	d[x] = l

	reg(i, x) {
		T++
		if!vis[v] {
			dfs(v, (l+ec)%3)
		} else if (l+ec)%3!= d[v] {
			ok = false
		}
	}
}

func main() {
	// Read the number of vertices and edges
	fmt.Scanf("%d%d", &n, &m)

	// Read edges and construct the graph
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scanf("%d%d", &a, &b)
		ins(a, b, 1)
		ins(b, a, 2)
	}

	ans := 0

	// Iterate through all vertices
	for i := 1; i <= n; i++ {
		if!vis[i] {
			T = 0
			for j := 0; j < 3; j++ {
				cnt[j] = 0
			}
			ok = true
			dfs(i, 0)

			s := cnt[0] + cnt[1] + cnt[2]

			if!ok {
				ans += s * s
			} else {
				if cnt[0] && cnt[1] && cnt[2] {
					ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
				} else {
					ans += T / 2
				}
			}
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

