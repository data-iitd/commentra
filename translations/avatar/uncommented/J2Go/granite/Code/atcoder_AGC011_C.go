
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

type Graph struct {
	adjacencyList []int
}

func (g *Graph) addEdge(u, v int) {
	g.adjacencyList[u] = append(g.adjacencyList[u], v)
	g.adjacencyList[v] = append(g.adjacencyList[v], u)
}

func (g *Graph) dfs(node, color int) (int, bool) {
	if g.visited[node] {
		if g.color[node]!= color {
			return 0, true
		}
		return 0, false
	}
	g.visited[node] = true
	g.color[node] = color
	total := 1
	for _, neighbor := range g.adjacencyList[node] {
		total += g.dfs(neighbor, 1-color)
	}
	return total, false
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Fscanf(reader, "%d %d\n", &n, &m)
	graph := Graph{make([]int, n)}
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscanf(reader, "%d %d\n", &u, &v)
		graph.addEdge(u-1, v-1)
	}
	graph.visited = make([]bool, n)
	graph.color = make([]int, n)
	one := int64(0)
	bipartite := int64(0)
	count := int64(0)
	for i := 0; i < n; i++ {
		if graph.visited[i] {
			continue
		}
		count++
		mujun := false
		kind, m := graph.dfs(i, 0)
		if kind == 1 {
			one++
		} else if!m {
			bipartite++
		}
	}
	total := one * (2*n - one)
	total += (count - one) * (count - one)
	total += bipartite * bipartite
	fmt.Println(total)
}

