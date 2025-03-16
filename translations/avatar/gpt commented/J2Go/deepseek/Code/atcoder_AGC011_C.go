package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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

func (m *Main) Run() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	m.graph = make([][]int, n)
	for i := 0; i < n; i++ {
		m.graph[i] = []int{}
	}

	for i := 0; i < m; i++ {
		scanner.Scan()
		parts = strings.Split(scanner.Text(), " ")
		u, _ := strconv.Atoi(parts[0])
		v, _ := strconv.Atoi(parts[1])
		m.graph[u-1] = append(m.graph[u-1], v-1)
		m.graph[v-1] = append(m.graph[v-1], u-1)
	}

	m.visited = make([]bool, n)
	m.color = make([]int, n)
	for i := 0; i < n; i++ {
		m.color[i] = -1
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

	total := m.one*(2*int64(n)-m.one) + (m.count-m.one)*(m.count-m.one) + m.bipartite*m.bipartite
	fmt.Println(total)
}

func main() {
	mainInstance := &Main{}
	mainInstance.Run()
}

