package main

import (
	"container/heap"
	"fmt"
)

type Item struct {
	degree int
	index  int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].degree < pq[j].degree
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	edges := make([]map[int]struct{}, N)
	for i := range edges {
		edges[i] = make(map[int]struct{})
	}
	degs := make([]int, N)
	parity := make([]int, N)
	flag := make([]bool, N)

	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a--
		b--
		edges[a][b] = struct{}{}
		edges[b][a] = struct{}{}
		degs[a]++
		degs[b]++
	}

	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	Q := &PriorityQueue{}
	for i, d := range degs {
		heap.Push(Q, &Item{degree: d, index: i})
	}

	for Q.Len() > 0 {
		item := heap.Pop(Q).(*Item)
		u := item.index

		if flag[u] {
			continue
		}
		flag[u] = true

		i := 0
		for v := range edges[u] {
			delete(edges[v], u)
			if parity[u] != 0 && i == 0 {
				fmt.Println(u+1, v+1)
				parity[u] = 1 - parity[u]
			} else {
				fmt.Println(v+1, u+1)
				parity[v] = 1 - parity[v]
			}
			degs[v]--
			heap.Push(Q, &Item{degree: degs[v], index: v})
			i++
		}
	}
}

// <END-OF-CODE>
