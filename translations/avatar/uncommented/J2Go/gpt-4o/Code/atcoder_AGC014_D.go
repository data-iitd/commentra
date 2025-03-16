package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	g = make([][]int, n)
	for i := range g {
		g[i] = []int{}
	}

	for i := 0; i < n-1; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}

	m := maxMatching(0, -1) / 2
	if 2*m == n {
		fmt.Println("Second")
	} else {
		fmt.Println("First")
	}
}

// <END-OF-CODE>
