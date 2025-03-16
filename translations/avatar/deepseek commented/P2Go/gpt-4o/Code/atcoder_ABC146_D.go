package main

import (
	"bufio"
	"fmt"
	"os"
)

type Graph struct {
	adjacencyList [][]int
}

func bfs(v int, N int, G *Graph, E map[[2]int]int) int {
	visited := make([]int, N)
	queue := []int{v}
	visited[v] = 1
	K := -1
	node2color := make([]int, N)
	for i := range node2color {
		node2color[i] = -1
	}

	for len(queue) > 0 {
		q := queue[0]
		queue = queue[1:]
		color := 0

		for _, nex := range G.adjacencyList[q] {
			if visited[nex] == 1 {
				continue
			}
			visited[nex] = 1
			color++
			if color == node2color[q] {
				color++
			}
			node2color[nex] = color
			if q < nex {
				E[[2]int{q, nex}] = color
			} else {
				E[[2]int{nex, q}] = color
			}
			queue = append(queue, nex)
		}
		if color > K {
			K = color
		}
	}
	return K
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	N := 0
	fmt.Fscan(reader, &N)

	G := &Graph{adjacencyList: make([][]int, N)}
	E := make(map[[2]int]int)

	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		a-- // Convert to 0-based index
		b-- // Convert to 0-based index
		G.adjacencyList[a] = append(G.adjacencyList[a], b)
		G.adjacencyList[b] = append(G.adjacencyList[b], a)
		E[[2]int{a, b}] = 0
	}

	K := bfs(0, N, G, E)
	fmt.Println(K)
	for _, value := range E {
		fmt.Println(value)
	}
}

// <END-OF-CODE>
