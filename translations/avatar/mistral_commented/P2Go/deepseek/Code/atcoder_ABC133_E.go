package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 1000000007

var graph [][]int
var N, K int

func dfs(fro, to, f int) int {
	caseNum := 1
	colorNum := K - 1
	if f == K {
		colorNum = K - 1
	} else {
		colorNum = K - 2
	}

	for _, u := range graph[fro] {
		if u == to {
			continue
		}
		pat := dfs(u, fro, colorNum)
		if pat == 0 {
			caseNum = 0
			break
		}
		caseNum = caseNum * pat % mod
		colorNum--
	}
	return caseNum
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	K, _ = strconv.Atoi(scanner.Text())

	graph = make([][]int, N)
	for i := 0; i < N-1; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		graph[a-1] = append(graph[a-1], b-1)
		graph[b-1] = append(graph[b-1], a-1)
	}

	ans := dfs(0, -1, K)
	fmt.Println(ans)
}
