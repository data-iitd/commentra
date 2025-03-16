package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type EdgeSet []int

func (es EdgeSet) Len() int {
	return len(es)
}

func (es EdgeSet) Less(i, j int) bool {
	return es[i] < es[j]
}

func (es EdgeSet) Swap(i, j int) {
	es[i], es[j] = es[j], es[i]
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	edges := make([]EdgeSet, N)
	degs := make([]int, N)
	parity := make([]int, N)
	flag := make([]bool, N)

	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a--
		b--
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
		degs[a]++
		degs[b]++
	}

	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	Q := &EdgeHeap{}
	heap.Init(Q)

	for i := 0; i < N; i++ {
		heap.Push(Q, i)
	}

	for Q.Len() > 0 {
		u := heap.Pop(Q).(int)
		if flag[u] {
			continue
		}
		flag[u] = true

		for _, v := range edges[u] {
			edges[v] = remove(edges[v], u)
			if parity[u] != 0 {
				fmt.Println(u+1, v+1)
				parity[u] = 1 - parity[u]
			} else {
				fmt.Println(v+1, u+1)
				parity[v] = 1 - parity[v]
			}
			degs[v]--
			heap.Push(Q, v)
		}
	}
}

type EdgeHeap []int

func (h EdgeHeap) Len() int {
	return len(h)
}

func (h EdgeHeap) Less(i, j int) bool {
	return h[i] < h[j]
}

func (h EdgeHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *EdgeHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *EdgeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func remove(slice []int, s int) []int {
	return append(slice[:s], slice[s+1:]...)
}

