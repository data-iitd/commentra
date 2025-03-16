package main

import (
	"bufio"
	"fmt"
	"os"
)

var G [100000][]int
var used [100000]bool
var grundy [100000]int

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
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var N int
	fmt.Fscan(in, &N)
	for i := 0; i < N-1; i++ {
		var x, y int
		fmt.Fscan(in, &x, &y)
		x--
		y--
		G[x] = append(G[x], y)
		G[y] = append(G[y], x)
	}
	dfs(0)
	if grundy[0] != 0 {
		fmt.Fprintln(out, "Alice")
	} else {
		fmt.Fprintln(out, "Bob")
	}
}

