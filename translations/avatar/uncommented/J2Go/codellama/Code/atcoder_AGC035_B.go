
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var numNode, numEdge int
	var connect [][]int
	var visited []int
	var odd []bool
	var print strings.Builder

	fmt.Scan(&numNode, &numEdge)
	connect = make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = make([]int, 0)
	}
	for i := 0; i < numEdge; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		connect[a-1] = append(connect[a-1], b-1)
		connect[b-1] = append(connect[b-1], a-1)
	}
	if numEdge%2 != 0 {
		fmt.Println(-1)
		os.Exit(0)
	}
	visited = make([]int, numNode)
	odd = make([]bool, numNode)
	dfs(0, -1)
	fmt.Println(print.String())
}

func dfs(crt, parent int) {
	visited[crt] = 1
	crtConnect := connect[crt]
	for _, child := range crtConnect {
		if child == parent || visited[child] == 1 {
			continue
		} else if visited[child] == 2 {
			print.WriteString(strconv.Itoa(crt+1) + " " + strconv.Itoa(child+1) + "\n")
			odd[crt] = !odd[crt]
		} else {
			dfs(child, crt)
			if odd[child] {
				print.WriteString(strconv.Itoa(child+1) + " " + strconv.Itoa(crt+1) + "\n")
				odd[child] = !odd[child]
			} else {
				print.WriteString(strconv.Itoa(crt+1) + " " + strconv.Itoa(child+1) + "\n")
				odd[crt] = !odd[crt]
			}
		}
	}
	visited[crt] = 2
}

