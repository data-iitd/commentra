package main

import (
	"fmt"
)

type Main struct {
	graph     [][]int
	visited   []bool
	color     []int
	one       int64
	bipartite int64
	count     int64
	mujun     bool
}

func (m *Main) dfs(a, c int) int {
	if m.visited[a] {
		if m.color[a] >= 0 && m.color[a] != c {
			m.mujun = true
		}
		return 0
	}
	m.visited[a] = true
	m.color[a] = c
	total := 1

	for _, b := range m.graph[a] {
		total += m.dfs(b, 1-c)
	}
	return total
}

func (m *Main) run() {
	var n, m int
	fmt.Scan(&n, &m)

	m.graph = make([][]int, n)
	for i := range m.graph {
		m.graph[i] = []int{}
	}

	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u-- // Convert to zero-based index
		v-- // Convert to zero-based index
		m.graph[u] = append(m.graph[u], v)
		m.graph[v] = append(m.graph[v], u)
	}

	m.visited = make([]bool, n)
	m.color = make([]int, n)
	for i := range m.color {
		m.color[i] = -1 // Set all colors to -1 (uncolored)
	}

	m.one = 0
	m.bipartite = 0
	m.count = 0

	for i := 0; i < n; i++ {
		if m.visited[i] {
			continue
		}
		m.count++
		m.mujun = false
		kind := m.dfs(i, 0)

		if kind == 1 {
			m.one++
		} else if !m.mujun {
			m.bipartite++
		}
	}

	total := m.one * (2*n - m.one)
	total += (m.count - m.one) * (m.count - m.one)
	total += m.bipartite * m.bipartite

	fmt.Println(total)
}

func main() {
	m := &Main{}
	m.run()
}

// <END-OF-CODE>
