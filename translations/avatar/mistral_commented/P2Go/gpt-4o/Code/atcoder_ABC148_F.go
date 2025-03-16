package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	n, ta, ao int
	g         [][]int
	taDist    []int
	aoDist    []int
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &ta, &ao)
	ta-- // Convert to 0-based index
	ao-- // Convert to 0-based index

	g = make([][]int, n)
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}

	taDist = make([]int, n)
	aoDist = make([]int, n)
	for i := range taDist {
		taDist[i] = -1 // Use -1 to indicate unvisited
		aoDist[i] = -1 // Use -1 to indicate unvisited
	}
	taDist[ta] = 0
	aoDist[ao] = 0

	taDFS(ta)
	aoDFS(ao)

	res := 0
	for i := 0; i < n; i++ {
		if taDist[i] == -1 || aoDist[i] == -1 || taDist[i] > aoDist[i] {
			continue
		}
		if aoDist[i] > res {
			res = aoDist[i]
		}
	}

	fmt.Println(res - 1)
}

func taDFS(node int) {
	for _, v := range g[node] {
		if taDist[v] != -1 {
			continue
		}
		taDist[v] = taDist[node] + 1
		taDFS(v)
	}
}

func aoDFS(node int) {
	for _, v := range g[node] {
		if aoDist[v] != -1 {
			continue
		}
		aoDist[v] = aoDist[node] + 1
		aoDFS(v)
	}
}

// <END-OF-CODE>
