package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Graph struct {
	adjList map[int][]int
}

func NewGraph() *Graph {
	return &Graph{
		adjList: make(map[int][]int),
	}
}

func (g *Graph) AddEdge(src, dest int) {
	g.adjList[src] = append(g.adjList[src], dest)
}

func (g *Graph) DFS(src int, visited map[int]bool) {
	visited[src] = true
	for _, v := range g.adjList[src] {
		if!visited[v] {
			g.DFS(v, visited)
		}
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	m := sc.Scan()
	m, _ = strconv.Atoi(m)
	n := sc.Scan()
	n, _ = strconv.Atoi(n)

	g := NewGraph()
	for i := 0; i <= m; i++ {
		g.adjList[i] = make([]int, 0)
	}

	for i := 0; i < n; i++ {
		x := sc.Scan()
		x, _ = strconv.Atoi(x)
		y := sc.Scan()
		y, _ = strconv.Atoi(y)
		g.AddEdge(x, y)
		g.AddEdge(y, x)
	}

	visited := make(map[int]bool)
	for i := 1; i <= m; i++ {
		if!visited[i] {
			g.DFS(i, visited)
		}
	}

	toRemove := 0
	for i := 1; i <= m; i++ {
		if!visited[i] {
			count := 0
			g.DFS(i, visited)
			for _, v := range g.adjList[i] {
				if!visited[v] {
					count++
				}
			}
			if count%2 == 1 {
				toRemove++
			}
		}
	}

	if (m-toRemove)%2 == 1 {
		toRemove++
	}

	fmt.Println(toRemove)
}

