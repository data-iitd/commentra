package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// g is a static array of slices that will store the graph's adjacency list representation.
var g [][]int

// maxMatching method calculates the maximum matching in a tree structure.
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
	return 2*a + min(1, o) + 1
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	n, _ := strconv.Atoi(sc.Text())
	g = make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, 0)
	}
	for i := 0; i < n-1; i++ {
		a, _ := strconv.Atoi(sc.Text())
		b, _ := strconv.Atoi(sc.Text())
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}
	m := maxMatching(0, -1) / 2
	if 2*m == n {
		fmt.Fprintln(out, "Second")
	} else {
		fmt.Fprintln(out, "First")
	}
}

