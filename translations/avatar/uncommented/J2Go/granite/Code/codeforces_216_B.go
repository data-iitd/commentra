
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Graph struct {
	adjacencyList map[int][]int
	visited        map[int]bool
	count          int
	cycle          int
	path           int
}

func NewGraph(m int) *Graph {
	g := &Graph{
		adjacencyList: make(map[int][]int),
		visited:        make(map[int]bool),
	}
	for i := 0; i <= m; i++ {
		g.adjacencyList[i] = []int{}
	}
	return g
}

func (g *Graph) Dfs(child, par int) int {
	if g.visited[child] == true {
		return g.cycle
	}
	g.visited[child] = true
	for _, i := range g.adjacencyList[child] {
		if i!= par {
			g.count++
			if g.Dfs(i, child) == g.cycle {
				return g.cycle
			}
		}
	}
	return g.path
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	m, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	g := NewGraph(m)
	for i := 0; i < n; i++ {
		x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		g.adjacencyList[x] = append(g.adjacencyList[x], y)
		g.adjacencyList[y] = append(g.adjacencyList[y], x)
	}
	toremove := 0
	for i := 1; i <= m; i++ {
		if!g.visited[i] {
			g.count = 0
			if g.Dfs(i, 0) == g.cycle {
				if g.count%2 == 1 {
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

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}

