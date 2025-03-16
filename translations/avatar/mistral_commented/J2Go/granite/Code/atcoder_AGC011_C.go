

package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
	"strconv"
)

type Graph struct {
	adjacencyList map[int]*list.List
	visited        map[int]bool
	color          map[int]int
	one            int64
	bipartite     int64
	count          int64
	mujun          bool
}

func NewGraph(n int) *Graph {
	return &Graph{
		adjacencyList: make(map[int]*list.List),
		visited:        make(map[int]bool),
		color:          make(map[int]int),
		one:            0,
		bipartite:     0,
		count:          0,
		mujun:          false,
	}
}

func (g *Graph) AddEdge(u, v int) {
	if _, ok := g.adjacencyList[u];!ok {
		g.adjacencyList[u] = list.New()
	}
	if _, ok := g.adjacencyList[v];!ok {
		g.adjacencyList[v] = list.New()
	}
	g.adjacencyList[u].PushBack(v)
	g.adjacencyList[v].PushBack(u)
}

func (g *Graph) Dfs(a, c int) int {
	if g.visited[a] {
		if g.color[a] >= 0 && g.color[a]!= c {
			g.mujun = true
		}
		return 0
	}
	g.visited[a] = true
	g.color[a] = c
	total := 1
	for e := g.adjacencyList[a].Front(); e!= nil; e = e.Next() {
		b := e.Value.(int)
		total += g.Dfs(b, 1-c)
	}
	return total
}

func (g *Graph) Run() {
	scan := bufio.NewScanner(os.Stdin)
	fmt.Scan(&g.count)
	fmt.Scan(&g.count)
	for i := 0; i < int(g.count); i++ {
		var u, v int
		fmt.Scan(&u)
		fmt.Scan(&v)
		g.AddEdge(u, v)
	}
	g.visited = make(map[int]bool)
	g.color = make(map[int]int)
	for i := 0; i < int(g.count); i++ {
		if!g.visited[i] {
			g.count++
			g.mujun = false
			kind := g.Dfs(i, 0)
			if kind == 1 {
				g.one++
			} else if!g.mujun {
				g.bipartite++
			}
		}
	}
	total := g.one * (2*g.count - g.one)
	total += (g.count - g.one) * (g.count - g.one)
	total += g.bipartite * g.bipartite
	fmt.Println(total)
}

func main() {
	graph := NewGraph(100000)
	graph.Run()
}

Translate the above Go code to C++ and end with comment "