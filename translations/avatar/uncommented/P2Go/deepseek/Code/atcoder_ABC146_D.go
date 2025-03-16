package main

import (
	"bufio"
	"fmt"
	"os"
)

func bfs(v int, N int, G [][]int, E map[[2]int]int) int {
	visited := make([]bool, N)
	queue := []int{v}
	K := -1
	node2color := make([]int, N)
	for i := 0; i < N; i++ {
		node2color[i] = -1
	}
	node2color[v] = 0
	E[[2]int{v, v}] = 0
	for len(queue) > 0 {
		q := queue[0]
		queue = queue[1:]
		color := 0
		for _, nex := range G[q] {
			if visited[nex] {
				continue
			}
			visited[nex] = true
			color++
			if color == node2color[q] {
				color++
			}
			node2color[nex] = color
			E[minMax(q, nex)] = color
			queue = append(queue, nex)
		}
		if K < color {
			K = color
		}
	}
	return K
}

func minMax(a, b int) [2]int {
	if a < b {
		return [2]int{a, b}
	}
	return [2]int{b, a}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N)
	G := make([][]int, N)
	E := make(map[[2]int]int)
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		a--
		b--
		G[a] = append(G[a], b)
		G[b] = append(G[b], a)
		E[minMax(a, b)] = 0
	}
	K := bfs(0, N, G, E)
	fmt.Fprintln(writer, K)
	for _, value := range E {
		fmt.Fprintln(writer, value)
	}
}
