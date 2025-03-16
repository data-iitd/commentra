package main

import (
	"bufio"
	"fmt"
	"os"
)

type Main struct {
	count int
	seen  []bool
	path  int
	cycle int
	graph [][]int
}

func (m *Main) dfs(child, par int) int {
	if m.seen[child] {
		return m.cycle
	}
	m.seen[child] = true
	for _, i := range m.graph[child] {
		if i != par {
			m.count++
			if m.dfs(i, child) == m.cycle {
				return m.cycle
			}
		}
	}
	return m.path
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	m := parseInt(scanner.Text())
	scanner.Scan()
	n := parseInt(scanner.Text())
	ft := Main{
		graph: make([][]int, m+1),
		seen:  make([]bool, m+1),
		path:  0,
		cycle: 1,
	}
	for i := 0; i <= m; i++ {
		ft.graph[i] = []int{}
	}
	for i := 0; i < n; i++ {
		scanner.Scan()
		x := parseInt(scanner.Text())
		scanner.Scan()
		y := parseInt(scanner.Text())
		ft.graph[x] = append(ft.graph[x], y)
		ft.graph[y] = append(ft.graph[y], x)
	}
	toremove := 0
	for i := 1; i <= m; i++ {
		if !ft.seen[i] {
			ft.count = 0
			if ft.dfs(i, 0) == ft.cycle {
				if ft.count%2 == 1 {
					toremove++
				}
			}
		}
	}
	if (m-toremove)%2 == 1 {
		toremove++
	}
	fmt.Println(toremove)
}

func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}
