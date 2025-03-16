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
	defer writer.Flush()

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	g = make([][]int, n)
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		ab := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(ab[0])
		b, _ := strconv.Atoi(ab[1])
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}
	m := maxMatching(0, -1) / 2
	if 2*m == n {
		fmt.Fprintln(writer, "Second")
	} else {
		fmt.Fprintln(writer, "First")
	}
}
