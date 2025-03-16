package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const maxn = 1e5 + 5

type Node struct {
	x, y, id int
}

type Edge struct {
	u, v, val int
}

var (
	node  [maxn]Node
	e     [maxn << 1]Edge
	par   [maxn]int
	n     int
)

func cmp1(a, b Node) bool {
	return a.x < b.x
}

func cmp2(a, b Node) bool {
	return a.y < b.y
}

func init() {
	for i := 0; i <= n; i++ {
		par[i] = i
	}
}

func findpar(x int) int {
	if par[x] == x {
		return x
	}
	return findpar(par[x])
}

func unite(x, y int) {
	x = findpar(x)
	y = findpar(y)
	if x == y {
		return
	}
	par[x] = y
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)

	init()

	for i := 1; i <= n; i++ {
		fmt.Fscan(reader, &node[i].x, &node[i].y)
		node[i].id = i
	}

	sort.Slice(node[1:n+1], func(i, j int) bool {
		return cmp1(node[i], node[j])
	})

	cnt := 0
	for i := 2; i <= n; i++ {
		e[cnt] = Edge{node[i-1].id, node[i].id, node[i].x - node[i-1].x}
		cnt++
	}

	sort.Slice(node[1:n+1], func(i, j int) bool {
		return cmp2(node[i], node[j])
	})

	for i := 2; i <= n; i++ {
		e[cnt] = Edge{node[i-1].id, node[i].id, node[i].y - node[i-1].y}
		cnt++
	}

	sort.Slice(e[:cnt], func(i, j int) bool {
		return e[i].val < e[j].val
	})

	ans := 0
	for i := 0; i < cnt; i++ {
		u := e[i].u
		v := e[i].v
		val := e[i].val
		if findpar(u) == findpar(v) {
			continue
		}
		unite(u, v)
		ans += val
	}

	fmt.Println(ans)
}

