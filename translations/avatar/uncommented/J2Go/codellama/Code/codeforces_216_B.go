
package main

import (
	"fmt"
)

func main() {
	var m, n int
	fmt.Scan(&m, &n)
	graph := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		graph[i] = make([]int, 0)
	}
	seen := make([]bool, m+1)
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		graph[x] = append(graph[x], y)
		graph[y] = append(graph[y], x)
	}
	toremove := 0
	for i := 1; i <= m; i++ {
		if !seen[i] {
			count := 0
			if dfs(i, 0, graph, seen) == 1 {
				if count%2 == 1 {
					toremove++
				}
			}
		}
	}
	if (m-toremove)%2 == 1 {
		toremove++
	}
	fmt.Println(toremove)
}

func dfs(child int, par int, graph [][]int, seen []bool) int {
	if seen[child] == true {
		return 1
	}
	seen[child] = true
	for _, i := range graph[child] {
		if i != par {
			count++
			if dfs(i, child, graph, seen) == 1 {
				return 1
			}
		}
	}
	return 0
}

