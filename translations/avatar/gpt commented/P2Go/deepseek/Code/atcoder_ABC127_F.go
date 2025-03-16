package main

import (
	"container/heap"
	"fmt"
	"os"
)

// MinHeap is a min-heap of integers.
type MinHeap []int

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// MaxHeap is a max-heap of integers (using negation).
type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	var q int
	fmt.Scan(&q)

	p1 := &MinHeap{}
	heap.Init(p1)
	p2 := &MinHeap{}
	heap.Init(p2)

	var sum_b, sum_p1, sum_p2 int

	for i := 0; i < q; i++ {
		var query []int
		fmt.Scan(&query)

		if query[0] == 2 {
			if p1.Len() == p2.Len() {
				fmt.Println(-(*p2)[0], sum_p1-p1.Len()*(*p2)[0]+p2.Len()*(*p2)[0]-sum_p2+sum_b)
			} else {
				fmt.Println((*p1)[0], sum_p1-p1.Len()*(*p1)[0]+p2.Len()*(*p1)[0]-sum_p2+sum_b)
			}
		} else {
			sum_b += query[2]

			if p1.Len() == 0 {
				heap.Push(p1, query[1])
				sum_p1 += query[1]
			} else if (*p1)[0] <= query[1] {
				heap.Push(p1, query[1])
				sum_p1 += query[1]
			} else {
				heap.Push(p2, -query[1])
				sum_p2 += query[1]
			}

			if p1.Len() < p2.Len() {
				heap.Push(p1, -heap.Pop(p2).(int))
				sum_p2 += (*p2)[0]
				sum_p1 -= (*p2)[0]
			}

			if p1.Len() > p2.Len()+1 {
				heap.Push(p2, -heap.Pop(p1).(int))
				sum_p1 -= (*p1)[0]
				sum_p2 += (*p1)[0]
			}
		}
	}
}
