package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Fscan(reader, &n, &m)
	graph := make([][]int, n)
	for i := 0; i < n; i++ {
		graph[i] = make([]int, 0)
	}
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscan(reader, &u, &v)
		graph[u-1] = append(graph[u-1], v-1)
		graph[v-1] = append(graph[v-1], u-1)
	}
	visited := make([]bool, n)
	color := make([]int, n)
	for i := 0; i < n; i++ {
		color[i] = -1
	}
	one := 0
	bipartite := 0
	count := 0
	for i := 0; i < n; i++ {
		if visited[i] {
			continue
		}
		count++
		mujun := false
		kind := dfs(graph, visited, color, i, 0)
		if kind == 1 {
			one++
		} else if!mujun {
			bipartite++
		}
	}
	total := one * (2*n - one)
	total += (count - one) * (count - one)
	total += bipartite * bipartite
	fmt.Println(total)
}

func dfs(graph [][]int, visited []bool, color []int, a, c int) int {
	if visited[a] {
		if color[a] >= 0 && color[a]!= c {
			return 0
		}
		return 0
	}
	visited[a] = true
	color[a] = c
	total := 1
	for _, b := range graph[a] {
		total += dfs(graph, visited, color, b, 1-c)
	}
	return total
}

