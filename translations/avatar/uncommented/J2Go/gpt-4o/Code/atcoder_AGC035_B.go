package main

import (
	"fmt"
)

var (
	connect [][]int
	visited []int
	odd     []bool
	print   []string
)

func main() {
	var numNode, numEdge int
	fmt.Scan(&numNode, &numEdge)

	connect = make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = []int{}
	}

	for i := 0; i < numEdge; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Convert to 0-based index
		b-- // Convert to 0-based index
		connect[a] = append(connect[a], b)
		connect[b] = append(connect[b], a)
	}

	if numEdge%2 != 0 {
		fmt.Println(-1)
		return
	}

	visited = make([]int, numNode)
	odd = make([]bool, numNode)
	print = []string{}

	dfs(0, -1)

	for _, line := range print {
		fmt.Print(line)
	}
}

func dfs(crt, parent int) {
	visited[crt] = 1
	crtConnect := connect[crt]

	for _, child := range crtConnect {
		if child == parent || visited[child] == 1 {
			continue
		} else if visited[child] == 2 {
			print = append(print, fmt.Sprintf("%d %d\n", crt+1, child+1))
			odd[crt] = !odd[crt]
		} else {
			dfs(child, crt)
			if odd[child] {
				print = append(print, fmt.Sprintf("%d %d\n", child+1, crt+1))
				odd[child] = !odd[child]
			} else {
				print = append(print, fmt.Sprintf("%d %d\n", crt+1, child+1))
				odd[crt] = !odd[crt]
			}
		}
	}
	visited[crt] = 2
}

// <END-OF-CODE>
