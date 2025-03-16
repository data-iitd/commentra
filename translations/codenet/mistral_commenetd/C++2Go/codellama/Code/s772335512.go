
package main

import (
	"fmt"
	"os"
)

func main() {
	var N int
	fmt.Scan(&N)
	G := make([][]int, N)
	used := make([]bool, N)
	grundy := make([]int, N)
	for i := 0; i < N-1; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		x--
		y--
		G[x] = append(G[x], y)
		G[y] = append(G[y], x)
	}
	dfs(0, G, used, grundy)
	if grundy[0] != 0 {
		fmt.Println("Alice")
	} else {
		fmt.Println("Bob")
	}
}

func dfs(v int, G [][]int, used []bool, grundy []int) {
	used[v] = true
	grundy[v] = 0
	for i := 0; i < len(G[v]); i++ {
		w := G[v][i]
		if !used[w] {
			dfs(w, G, used, grundy)
			grundy[v] ^= (grundy[w] + 1)
		}
	}
}

