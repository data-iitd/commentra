
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

var g [][]int

func maxMatching(v, p int) int {
	a, o := 0, 0
	for _, w := range g[v] {
		if w == p {
			continue
		}
		r := maxMatching(w, v)
		a += r / 2
		o += r % 2
	}
	return 2*a + min(1, o) + 1
}

func main() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	g = make([][]int, n)
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscanf(r, "%d%d\n", &a, &b)
		a--
		b--
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	m := maxMatching(0, -1) / 2
	fmt.Fprintf(w, "%s\n", "Second")
	w.Flush()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

