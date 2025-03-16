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

func (ft *Main) dfs(child, par int) int {
	if ft.seen[child] {
		return ft.cycle
	}
	ft.seen[child] = true
	for _, i := range ft.graph[child] {
		if i != par {
			ft.count++
			if ft.dfs(i, child) == ft.cycle {
				return ft.cycle
			}
		}
	}
	return ft.path
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	m := toInt(scanner.Bytes())
	scanner.Scan()
	n := toInt(scanner.Bytes())
	ft := &Main{}
	ft.graph = make([][]int, m+1)
	for i := 0; i <= m; i++ {
		ft.graph[i] = []int{}
	}
	ft.seen = make([]bool, m+1)
	for i := 0; i < n; i++ {
		scanner.Scan()
		x := toInt(scanner.Bytes())
		scanner.Scan()
		y := toInt(scanner.Bytes())
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

func toInt(b []byte) int {
	var n int
	for _, v := range b {
		n = n*10 + int(v-'0')
	}
	return n
}

