
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

func main() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, 0)
	}
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscanf(r, "%d %d\n", &a, &b)
		a--
		b--
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var m int
	m = maxMatching(0, -1) / 2
	if 2*m == n {
		fmt.Fprintln(w, "Second")
	} else {
		fmt.Fprintln(w, "First")
	}
	w.Flush()
}

func maxMatching(v, p int) int {
	a := 0
	o := 0
	for _, w := range g[v] {
		if w == p {
			continue
		}
		r := maxMatching(w, v)
		a += r / 2
		o += r % 2
	}
	return 2*a + int(math.Min(1, float64(o))) + 1
}

func main() {
	main1()
}

