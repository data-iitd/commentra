package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	g := make([][]int, n)
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}
	var m int
	m = maxMatching(0, -1) / 2
	if 2*m == n {
		fmt.Println("Second")
	} else {
		fmt.Println("First")
	}
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
	return 2*a + min(1, o) + 1
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 