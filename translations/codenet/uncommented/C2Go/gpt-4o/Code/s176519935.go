package main

import (
	"container/heap"
	"fmt"
)

type IntHeap []int64

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] } // Max-heap
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int64))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	h := &IntHeap{}
	heap.Init(h)

	for i := 0; i < n; i++ {
		heap.Push(h, a[i])
	}

	for i := 0; i < m; i++ {
		tm := heap.Pop(h).(int64)
		tm /= 2
		heap.Push(h, tm)
	}

	var ans int64 = 0
	for h.Len() > 0 {
		ans += heap.Pop(h).(int64)
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
