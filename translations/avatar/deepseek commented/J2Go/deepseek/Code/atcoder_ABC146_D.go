package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Edge struct {
	id int
	to int
}

var (
	n    int
	g    [][]Edge
	ans  []int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	g = make([][]Edge, n)
	for i := 0; i < n; i++ {
		g[i] = []Edge{}
	}
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		a--
		b--
		g[a] = append(g[a], Edge{i, b})
		g[b] = append(g[b], Edge{i, a})
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

func dfs(to, color, parent int) {
	k := 1
	for _, e := range g[to] {
		if e.to == parent {
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

