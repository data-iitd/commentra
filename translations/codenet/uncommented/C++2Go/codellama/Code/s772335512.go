package main

import (
	"fmt"
)

var G [100000][]int
var used [100000]bool
var grundy [100000]int

func dfs(v int) {
	used[v] = true
	grundy[v] = 0
	for i := 0; i < len(G[v]); i++ {
		if !used[G[v][i]] {
			dfs(G[v][i])
			grundy[v] ^= (grundy[G[v][i]] + 1)
		}
	}
}

func main() {
	var N int
	fmt.Scan(&N)
	for i := 0; i < N-1; i++ {
		var x, y int
		fmt.Scan(&x, &y)
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

