package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	
	var numNode, numEdge int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &numNode)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &numEdge)
	
	connect := make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = make([]int, 0)
	}
	
	for i := 0; i < numEdge; i++ {
		var a, b int
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a)
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &b)
		a--
		b--
		connect[a] = append(connect[a], b)
		connect[b] = append(connect[b], a)
	}
	
	if numEdge % 2 != 0 {
		fmt.Println(-1)
		return
	}
	
	visited := make([]int, numNode)
	odd := make([]bool, numNode)
	var print strings.Builder
	
	dfs(0, -1, connect, visited, odd, &print)
	
	fmt.Println(print.String())
}

func dfs(crt, parent int, connect [][]int, visited []int, odd []bool, print *strings.Builder) {
	visited[crt] = 1
	for _, child := range connect[crt] {
		if child == parent || visited[child] == 1 {
			continue
		} else if visited[child] == 2 {
			print.WriteString(fmt.Sprintf("%d %d\n", crt+1, child+1))
			odd[crt] = !odd[crt]
		} else {
			dfs(child, crt, connect, visited, odd, print)
			if odd[child] {
				print.WriteString(fmt.Sprintf("%d %d\n", child+1, crt+1))
				odd[child] = !odd[child]
			} else {
				print.WriteString(fmt.Sprintf("%d %d\n", crt+1, child+1))
				odd[crt] = !odd[crt]
			}
		}
	}
	visited[crt] = 2
}
