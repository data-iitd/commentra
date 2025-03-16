
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main structure
type Main struct {
	count  int
	seen   []bool
	path   int
	cycle  int
	graph  [][]int
	toremove int
}

// NewMain creates a new Main structure
func NewMain() *Main {
	return &Main{
		count:   0,
		seen:    make([]bool, 0),
		path:    0,
		cycle:   1,
		graph:   make([][]int, 0),
		toremove: 0,
	}
}

// DFS method to detect cycles
func (m *Main) dfs(child, par int) int {
	if m.seen[child] {
		return m.cycle
	}
	m.seen[child] = true
	for _, i := range m.graph[child] {
		if i!= par {
			m.count++
			if m.dfs(i, child) == m.cycle {
				return m.cycle
			}
		}
	}
	return m.path
}

// Main method to handle input and output
func main() {
	sc := bufio.NewScanner(os.Stdin)
	m, _ := strconv.Atoi(sc.Text())
	n, _ := strconv.Atoi(sc.Text())
	ft := NewMain()
	ft.graph = make([][]int, m+1)
	for i := 0; i <= m; i++ {
		ft.graph[i] = make([]int, 0)
	}
	ft.seen = make([]bool, m+1)
	for i := 0; i < n; i++ {
		x, _ := strconv.Atoi(sc.Text())
		y, _ := strconv.Atoi(sc.Text())
		ft.graph[x] = append(ft.graph[x], y)
		ft.graph[y] = append(ft.graph[y], x)
	}
	for i := 1; i <= m; i++ {
		if!ft.seen[i] {
			ft.count = 0
			if ft.dfs(i, 0) == ft.cycle {
				if ft.count%2 == 1 {
					ft.toremove++
				}
			}
		}
	}
	if (m-ft.toremove)%2 == 1 {
		ft.toremove++
	}
	fmt.Println(ft.toremove)
}

// 