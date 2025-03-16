
package main

import (
	"fmt"
	"os"
	"strconv"
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
			seen[i] = true
			if dfs(i, 0, graph, seen, &count) == 1 {
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

func dfs(node, parent int, graph [][]int, seen []bool, count *int) int {
	for _, neighbor := range graph[node] {
		if neighbor != parent {
			*count++
			if dfs(neighbor, node, graph, seen, count) == 1 {
				return 1
			}
		}
	}
	return 0
}

// 