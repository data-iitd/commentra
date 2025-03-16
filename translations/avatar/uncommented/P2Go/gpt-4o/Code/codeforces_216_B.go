package main

import (
	"fmt"
	"os"
)

func readInts() ([]int, error) {
	var n int
	var err error
	var nums []int
	for {
		_, err = fmt.Scan(&n)
		if err != nil {
			break
		}
		nums = append(nums, n)
	}
	return nums, err
}

func dfs(g map[int]map[int]struct{}, seen map[int]struct{}, i int) (int, int) {
	if _, ok := seen[i]; ok {
		return 0, 0
	}
	seen[i] = struct{}{}
	nodes := 1
	edges := len(g[i])
	for j := range g[i] {
		x, y := dfs(g, seen, j)
		nodes += x
		edges += y
	}
	return nodes, edges
}

func solve() bool {
	line0, err := readInts()
	if err != nil {
		return false
	}
	n, m := line0[0], line0[1]
	g := make(map[int]map[int]struct{})
	seen := make(map[int]struct{})

	for i := 1; i <= n; i++ {
		g[i] = make(map[int]struct{})
	}
	for j := 0; j < m; j++ {
		line, _ := readInts()
		a, b := line[0], line[1]
		g[a][b] = struct{}{}
		g[b][a] = struct{}{}
	}
	ans := 0
	for i := 1; i <= n; i++ {
		if _, ok := seen[i]; !ok {
			nodes, edges := dfs(g, seen, i)
			if nodes > 1 && nodes%2 == 1 && 2*nodes == edges {
				ans++
			}
		}
	}
	if (n - ans)%2 == 1 {
		ans++
	}
	fmt.Println(ans)
	return true
}

func main() {
	for solve() {
	}
}

// <END-OF-CODE>
