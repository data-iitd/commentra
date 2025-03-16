package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAXN = 100000

var G [MAXN][]int
var used [MAXN]bool
var grundy [MAXN]int

func dfs(v int) {
	used[v] = true
	grundy[v] = 0

	for _, u := range G[v] {
		if !used[u] {
			dfs(u)
			grundy[v] ^= (grundy[u] + 1)
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	var N int
	fmt.Fscan(reader, &N)

	for i := 0; i < N-1; i++ {
		var x, y int
		fmt.Fscan(reader, &x, &y)
		x--
		y--
		G[x] = append(G[x], y)
		G[y] = append(G[y], x)
	}

	dfs(0)

	if grundy[0] != 0 {
		fmt.Println("Alice")
	} else {
		fmt.Println("Bob")
	}
}

