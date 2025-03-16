package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	numNode := parseInt(scanner.Bytes())
	scanner.Scan()
	numEdge := parseInt(scanner.Bytes())

	connect := make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = make([]int, 0)
	}

	for i := 0; i < numEdge; i++ {
		scanner.Scan()
		a := parseInt(scanner.Bytes()) - 1
		scanner.Scan()
		b := parseInt(scanner.Bytes()) - 1
		connect[a] = append(connect[a], b)
		connect[b] = append(connect[b], a)
	}

	if numEdge%2 != 0 {
		fmt.Println(-1)
		return
	}

	visited := make([]int, numNode)
	odd := make([]bool, numNode)
	var print strings.Builder

	dfs(0, -1, connect, visited, odd, &print)

	fmt.Print(print.String())
}

func parseInt(b []byte) int {
	var num int
	for _, v := range b {
		num = num*10 + int(v-'0')
	}
	return num
}

func dfs(crt, parent int, connect [][]int, visited []int, odd []bool, print *strings.Builder) {
	visited[crt] = 1

	crtConnect := connect[crt]
	for _, child := range crtConnect {
		if child == parent || visited[child] == 1 {
			continue
		}

		if visited[child] == 2 {
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

