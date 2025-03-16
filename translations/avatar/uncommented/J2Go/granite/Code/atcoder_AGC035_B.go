
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	connect   [100000]map[int]bool
	visited   [100000]bool
	odd       [100000]bool
	print     strings.Builder
	numNode   int
	numEdge   int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		numNode, _ = strconv.Atoi(scanner.Text())
	}
	if scanner.Scan() {
		numEdge, _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < numNode; i++ {
		connect[i] = make(map[int]bool)
	}
	for i := 0; i < numEdge; i++ {
		if scanner.Scan() {
			a, _ := strconv.Atoi(scanner.Text())
		}
		if scanner.Scan() {
			b, _ := strconv.Atoi(scanner.Text())
		}
		connect[a-1][b-1] = true
		connect[b-1][a-1] = true
	}
	if numEdge%2!= 0 {
		fmt.Println(-1)
		return
	}
	dfs(0, -1)
	fmt.Println(print.String())
}

func dfs(crt, parent int) {
	visited[crt] = true
	for child := range connect[crt] {
		if child == parent || visited[child] {
			continue
		} else if visited[child] {
			print.WriteString(strconv.Itoa(crt+1) + " " + strconv.Itoa(child+1) + "\n")
			odd[crt] =!odd[crt]
		} else {
			dfs(child, crt)
			if odd[child] {
				print.WriteString(strconv.Itoa(child+1) + " " + strconv.Itoa(crt+1) + "\n")
				odd[child] =!odd[child]
			} else {
				print.WriteString(strconv.Itoa(crt+1) + " " + strconv.Itoa(child+1) + "\n")
				odd[crt] =!odd[crt]
			}
		}
	}
	visited[crt] = false
}

