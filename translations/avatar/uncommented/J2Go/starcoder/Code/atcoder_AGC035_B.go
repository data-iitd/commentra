_
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	numNode, _ := strconv.Atoi(sc.Text())
	numEdge, _ := strconv.Atoi(sc.Text())
	connect := make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = make([]int, 0)
	}
	for i := 0; i < numEdge; i++ {
		a, _ := strconv.Atoi(sc.Text())
		b, _ := strconv.Atoi(sc.Text())
		connect[a-1] = append(connect[a-1], b-1)
		connect[b-1] = append(connect[b-1], a-1)
	}
	if numEdge%2!= 0 {
		fmt.Println(-1)
		return
	}
	visited := make([]int, numNode)
	odd := make([]bool, numNode)
	print := strings.Builder{}
	dfs(0, -1, connect, visited, odd, &print)
	fmt.Println(print.String())
}

func dfs(crt, parent int, connect [][]int, visited []int, odd []bool, print *strings.Builder) {
	visited[crt] = 1
	crtConnect := connect[crt]
	for _, child := range crtConnect {
		if child == parent || visited[child] == 1 {
			continue
		} else if visited[child] == 2 {
			print.WriteString(fmt.Sprintf("%d %d\n", crt+1, child+1))
			odd[crt] =!odd[crt]
		} else {
			dfs(child, crt, connect, visited, odd, print)
			if odd[child] {
				print.WriteString(fmt.Sprintf("%d %d\n", child+1, crt+1))
				odd[child] =!odd[child]
			} else {
				print.WriteString(fmt.Sprintf("%d %d\n", crt+1, child+1))
				odd[crt] =!odd[crt]
			}
		}
	}
	visited[crt] = 2
}

