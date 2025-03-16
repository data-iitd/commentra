
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const N = 100010

type Node struct {
	x, y, id int
}

type Edge struct {
	u, v, val int
}

var (
	n int
	par [N]int
	node [N]Node
	e [N << 1]Edge
)

func init() {
	for i := 0; i <= n; i ++ {
		par[i] = i
	}
}

func findpar(x int) int {
	if par[x] == x {
		return x
	}
	par[x] = findpar(par[x])
	return par[x]
}

func unite(x, y int) {
	rx, ry := findpar(x), findpar(y)
	if rx == ry {
		return
	}
	par[rx] = ry
}

func cmp1(a, b Node) bool {
	return a.x < b.x
}

func cmp2(a, b Node) bool {
	return a.y < b.y
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &n)

	for i := 1; i <= n; i ++ {
		fmt.Fscanf(reader, "%d%d\n", &node[i].x, &node[i].y)
		node[i].id = i
	}

	sort.Sort(node[1:n+1 : n+1])
	cnt := 0
	for i := 2; i <= n; i ++ {
		e[cnt] = Edge{node[i-1].id, node[i].id, node[i].x - node[i-1].x}
		cnt ++
	}

	sort.Sort(node[1:n+1 : n+1], cmp2)
	for i := 2; i <= n; i ++ {
		e[cnt] = Edge{node[i-1].id, node[i].id, node[i].y - node[i-1].y}
		cnt ++
	}

	sort.Sort(e[0:cnt : cnt])

	ans := int64(0)
	for i := 0; i < cnt; i ++ {
		u, v, val := e[i].u, e[i].v, e[i].val
		if findpar(u) == findpar(v) {
			continue
		}
		unite(u, v)
		ans += int64(val)
	}

	fmt.Println(ans)
}

