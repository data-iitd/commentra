
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to take input as an integer
func inp() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Function to take input as a list
func inpl() []int {
	var a []int
	a = make([]int, inp())
	for i := 0; i < len(a); i++ {
		fmt.Scanf("%d", &a[i])
	}
	return a
}

func main() {
	n, ta, ao := inpl()
	ta--
	ao--
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, 0)
	}
	for i := 0; i < n-1; i++ {
		a, b := inpl()
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}
	ta_dist := make([]int, n)
	ao_dist := make([]int, n)
	ta_dist[ta] = 0
	ao_dist[ao] = 0
	var dfs func(int)
	dfs = func(node int) {
		for _, v := range g[node] {
			if ta_dist[v]!= 0 {
				continue
			}
			ta_dist[v] = ta_dist[node] + 1
			dfs(v)
	}
	}
	dfs(ao)
	dfs(ta)
	res := 0
	for i := 0; i < n; i++ {
		if ta_dist[i] == 0 || ao_dist[i] == 0 || ta_dist[i] > ao_dist[i] {
			continue
		}
		res = max(res, ao_dist[i])
	}
	fmt.Println(res - 1)
}

// Function to print the answer
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

