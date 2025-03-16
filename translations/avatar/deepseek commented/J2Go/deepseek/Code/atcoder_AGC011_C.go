package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Main struct {
	graph    [][]int
	visited  []bool
	color    []int
	one      int64
	bipartite int64
	count    int64
	mujun    bool
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())
	m.graph = make([][]int, n)
	for i := 0; i < n; i++ {
		m.graph[i] = []int{}
	}
	for i := 0; i < m; i++ {
		scanner.Scan()
		u, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		v, _ := strconv.Atoi(scanner.Text())
		u--
		v--
		m.graph[u] = append(m.graph[u], v)
		m.graph[v] = append(m.graph[v], u)
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
	m := &Main{}
	m.run()
}

