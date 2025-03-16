
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	G      [100000][]int
	used   [100000]bool
	grundy [100000]int
)

func dfs(v int) {
	used[v] = true
	grundy[v] = 0
	for _, u := range G[v] {
		if!used[u] {
			dfs(u)
			grundy[v] ^= (grundy[u] + 1)
		}
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())
		x--
		y--
		G[x] = append(G[x], y)
		G[y] = append(G[y], x)
	}
	dfs(0)
	if grundy[0]!= 0 {
		fmt.Println("Alice")
	} else {
		fmt.Println("Bob")
	}
}

