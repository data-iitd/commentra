package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Edge struct {
	id  int
	to  int
	nxt *Edge
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	g := make([][]*Edge, n)
	for i := 0; i < n; i++ {
		g[i] = make([]*Edge, 0)
	}
	for i := 0; i < n-1; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		a--
		b--
		e := &Edge{i, b, nil}
		g[a] = append(g[a], e)
		e = &Edge{i, a, nil}
		g[b] = append(g[b], e)
	}
	ans := make([]int, n-1)
	dfs(0, -1, -1, g, ans)
	max := 0
	for _, temp := range ans {
		max = max + temp
	}
	fmt.Println(max)
	for _, c := range ans {
		fmt.Println(c)
	}
}

func dfs(to, color, parents int, g [][]*Edge, ans []int) {
	k := 1
	for _, e := range g[to] {
		if e.to == parents {
			continue
		}
		if k == color {
			k++
		}
		ans[e.id] = k
		dfs(e.to, k, to, g, ans)
		k++
	}
}

