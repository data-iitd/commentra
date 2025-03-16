
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var m, n int
	var toremove int
	var seen [1000001]bool
	var graph [1000001][]int
	var count int
	var cycle int
	var path int

	fmt.Scan(&m)
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x)
		fmt.Scan(&y)
		graph[x] = append(graph[x], y)
		graph[y] = append(graph[y], x)
	}

	for i := 1; i <= m; i++ {
		if !seen[i] {
			count = 0
			if dfs(i, 0) == cycle {
				if count%2 == 1 {
					toremove++
				}
			}
		}
	}

	if (m - toremove)%2 == 1 {
		toremove++
	}

	fmt.Println(toremove)
}

func dfs(child, par int) int {
	if seen[child] {
		return cycle
	}
	seen[child] = true

	for _, i := range graph[child] {
		if i != par {
			count++
			if dfs(i, child) == cycle {
				return cycle
			}
		}
	}
	return path
}

