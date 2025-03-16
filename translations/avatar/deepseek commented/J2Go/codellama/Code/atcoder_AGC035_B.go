package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var numNode, numEdge int
	sc.Scan()
	numNode, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	numEdge, _ = strconv.Atoi(sc.Text())
	connect := make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = make([]int, 0)
	}
	for i := 0; i < numEdge; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		connect[a-1] = append(connect[a-1], b-1)
		connect[b-1] = append(connect[b-1], a-1)
	}
	if numEdge%2 != 0 {
		fmt.Println(-1)
		return
	}
	visited := make([]int, numNode)
	odd := make([]bool, numNode)
	print := strings.Builder{}
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

