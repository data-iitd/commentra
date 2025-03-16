
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Edge struct {
	id  int
	to  int
}

var n int
var g [][]Edge
var ans []int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
	}
	g = make([][]Edge, n)
	for i := 0; i < n; i++ {
		g[i] = make([]Edge, 0)
	}
	for i := 0; i < n-1; i++ {
		if scanner.Scan() {
			a, _ := strconv.Atoi(scanner.Text())
		}
		if scanner.Scan() {
			b, _ := strconv.Atoi(scanner.Text())
		}
		g[a-1] = append(g[a-1], Edge{i, b - 1})
		g[b-1] = append(g[b-1], Edge{i, a - 1})
	}
	ans = make([]int, n-1)
	dfs(0, -1, -1)
	max := 0
	for _, temp := range ans {
		if temp > max {
			max = temp
		}
	}
	fmt.Println(max)
	for _, c := range ans {
		fmt.Println(c)
	}
}

func dfs(to int, color int, parents int) {
	k := 1
	for _, e := range g[to] {
		if e.to == parents {
			continue
		}
		if k == color {
			k++
		}
		ans[e.id] = k
		dfs(e.to, k, to)
		k++
	}
}

