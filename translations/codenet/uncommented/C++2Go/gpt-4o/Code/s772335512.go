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
	for _, neighbor := range G[v] {
		if !used[neighbor] {
			dfs(neighbor)
			grundy[v] ^= (grundy[neighbor] + 1)
		}
	}
}

func main() {
	var N int
	fmt.Scan(&N)
	for i := 0; i < N-1; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		x-- // Convert to 0-based index
		y-- // Convert to 0-based index
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

// <END-OF-CODE>
