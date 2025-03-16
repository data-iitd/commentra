package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var g [][]int

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
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	g = make([][]int, n)
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		edges := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(edges[0]) - 1
		b, _ := strconv.Atoi(edges[1]) - 1
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	m := maxMatching(0, -1) / 2
	if 2*m == n {
		fmt.Fprintln(writer, "Second")
	} else {
		fmt.Fprintln(writer, "First")
	}
	writer.Flush()
}
