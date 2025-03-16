package main

import (
	"bufio"
	"fmt"
	"os"
)

type Queue struct {
	items []int
}

func (q *Queue) Enqueue(item int) {
	q.items = append(q.items, item)
}

func (q *Queue) Dequeue() int {
	item := q.items[0]
	q.items = q.items[1:]
	return item
}

func (q *Queue) IsEmpty() bool {
	return len(q.items) == 0
}

func bfs(v int, N int, G [][]int, E map[[2]int]int) int {
	visited := make([]int, N)
	queue := Queue{}
	K := -1
	node2color := make([]int, N)
	for i := range node2color {
		node2color[i] = -1
	}
	queue.Enqueue(v)
	visited[v] = 1

	for !queue.IsEmpty() {
		q := queue.Dequeue()
		color := 0
		for _, nex := range G[q] {
			if visited[nex] != 0 {
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
			queue.Enqueue(nex)
		}
		if color > K {
			K = color
		}
	}
	return K
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N int
	fmt.Fscan(reader, &N)

	G := make([][]int, N)
	E := make(map[[2]int]int)

	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		a-- // Convert to 0-based index
		b-- // Convert to 0-based index
		G[a] = append(G[a], b)
		G[b] = append(G[b], a)
		E[[2]int{a, b}] = 0
	}

	K := bfs(0, N, G, E)
	fmt.Println(K)
	for _, value := range E {
		fmt.Println(value)
	}
}

// <END-OF-CODE>
