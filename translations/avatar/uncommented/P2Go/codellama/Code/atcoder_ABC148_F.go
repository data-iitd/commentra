package main

import (
	"fmt"
	"math"
)

func main() {
	var n, ta, ao int
	fmt.Scan(&n, &ta, &ao)
	ta--; ao--
	g := make([][]int, n)
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a--; b--
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ta_dist := make([]int, n)
	ta_dist[ta] = 0
	ao_dist := make([]int, n)
	ao_dist[ao] = 0
	ta_dfs(ta, ta_dist)
	ao_dfs(ao, ao_dist)
	res := 0
	for i := 0; i < n; i++ {
		if ta_dist[i] > ao_dist[i] {
			continue
		}
		res = int(math.Max(float64(res), float64(ao_dist[i])))
	}
	fmt.Println(res - 1)
}

func ta_dfs(node int, dist []int) {
	for _, v := range g[node] {
		if dist[v] != 0 {
			continue
		}
		dist[v] = dist[node] + 1
		ta_dfs(v, dist)
	}
}

func ao_dfs(node int, dist []int) {
	for _, v := range g[node] {
		if dist[v] != 0 {
			continue
		}
		dist[v] = dist[node] + 1
		ao_dfs(v, dist)
	}
}

