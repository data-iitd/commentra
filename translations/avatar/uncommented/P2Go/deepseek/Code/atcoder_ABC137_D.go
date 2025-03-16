package main

import (
	"container/heap"
	"fmt"
)

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
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

	x := &IntHeap{}
	y := &IntHeap{}

	for i := 0; i < n; i++ {
		var day, salary int
		fmt.Scan(&day, &salary)
		heap.Push(x, -day)
		heap.Push(x, -salary)
	}

	for x.Len() > 0 {
		d := heap.Pop(x).(int)
		r := m - y.Len()
		if r >= -d {
			heap.Push(y, -d)
		} else {
			heap.Push(y, -d)
			heap.Pop(y)
		}
	}

	sum := 0
	for y.Len() > 0 {
		sum += heap.Pop(y).(int)
	}

	fmt.Println(sum)
}
