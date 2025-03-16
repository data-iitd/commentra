
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Node struct {
	x, y, id int
}

type Edge struct {
	u, v, val int
}

func (e Edge) Less(i, j int) bool {
	return e[i].val < e[j].val
}

func findpar(x int) int {
	if x == par[x] {
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
	var n int
	fmt.Scan(&n)

	par := make([]int, n+1)
	for i := 0; i <= n; i++ {
		par[i] = i
	}

	node := make([]Node, n+1)
	for i := 1; i <= n; i++ {
		fmt.Scan(&node[i].x, &node[i].y)
		node[i].id = i
	}

	sort.Slice(node[1:], func(i, j int) bool {
		return node[i].x < node[j].x
	})

	cnt := 0
	for i := 2; i <= n; i++ {
		e[cnt] = Edge{node[i-1].id, node[i].id, node[i].x - node[i-1].x}
		cnt++
	}

	sort.Slice(node[1:], func(i, j int) bool {
		return node[i].y < node[j].y
	})
	for i := 2; i <= n; i++ {
		e[cnt] = Edge{node[i-1].id, node[i].id, node[i].y - node[i-1].y}
		cnt++
	}

	sort.Slice(e, func(i, j int) bool {
		return e[i].val < e[j].val
	})

	ans := 0
	for i := 0; i < cnt; i++ {
		u, v, val := e[i].u, e[i].v, e[i].val
		if findpar(u) == findpar(v) {
			continue
		}
		unite(u, v)
		ans += val
	}

	fmt.Println(ans)
}

