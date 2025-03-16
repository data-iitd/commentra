
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

	numNode, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	numEdge, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	connect := make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = make([]int, 0)
	}

	for i := 0; i < numEdge; i++ {
		parts := strings.Split(strings.TrimSpace(readLine(reader)), " ")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		connect[a-1] = append(connect[a-1], b-1)
		connect[b-1] = append(connect[b-1], a-1)
	}

	if numEdge%2!= 0 {
		fmt.Println(-1)
		return
	}

	visited := make([]int, numNode)
	odd := make([]bool, numNode)
	print := &strings.Builder{}

	dfs(0, -1, connect, visited, odd, print)

	fmt.Println(print.String())
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

func dfs(crt int, parent int, connect [][]int, visited []int, odd []bool, print *strings.Builder) {
	visited[crt] = 1
	crtConnect := connect[crt]

	for _, child := range crtConnect {
		if child == parent || visited[child] == 1 {
			continue
		} else if visited[child] == 2 {
			print.WriteString(strconv.Itoa(crt+1) + " " + strconv.Itoa(child+1) + "\n")
			odd[crt] =!odd[crt]
		} else {
			dfs(child, crt, connect, visited, odd, print)
			if odd[child] {
				print.WriteString(strconv.Itoa(child+1) + " " + strconv.Itoa(crt+1) + "\n")
				odd[child] =!odd[child]
			} else {
				print.WriteString(strconv.Itoa(crt+1) + " " + strconv.Itoa(child+1) + "\n")
				odd[crt] =!odd[crt]
			}
		}
	}

	visited[crt] = 2
}

