

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	G        [100000][]int
	used     [100000]bool
	grundy  [100000]int
	reader   = bufio.NewReader(os.Stdin)
	writer   = bufio.NewWriter(os.Stdout)
	N        int
	x, y    int
)

func dfs(v int) {
	used[v] = true
	grundy[v] = 0
	for _, w := range G[v] {
		if!used[w] {
			dfs(w)
			grundy[v] ^= (grundy[w] + 1)
		}
	}
}

func main() {
	fmt.Fscanf(reader, "%d\n", &N)
	for i := 0; i < N-1; i++ {
		fmt.Fscanf(reader, "%d %d\n", &x, &y)
		x--
		y--
		G[x] = append(G[x], y)
		G[y] = append(G[y], x)
	}
	dfs(0)
	if grundy[0]!= 0 {
		fmt.Fprintln(writer, "Alice")
	} else {
		fmt.Fprintln(writer, "Bob")
	}
	writer.Flush()
}

