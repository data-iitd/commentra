package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type MinHeap []int
type MaxHeap []int

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
	p2 := &MaxHeap{}
	heap.Init(p1)
	heap.Init(p2)

	sum_b := 0
	sum_p1 := 0
	sum_p2 := 0

	for i := 0; i < q; i++ {
		var ql []int
		fmt.Scan(&ql)
		if ql[0] == 2 {
			if len(*p1) == len(*p2) {
				fmt.Println(-(*p2)[0], sum_p1-len(*p1)*(-(*p2)[0])+len(*p2)*(-(*p2)[0])-sum_p2+sum_b)
			} else {
				fmt.Println((*p1)[0], sum_p1-len(*p1)*(*p1)[0]+len(*p2)*(*p1)[0]-sum_p2+sum_b)
			}
		} else {
			sum_b += ql[2]
			if len(*p1) == 0 {
				heap.Push(p1, ql[1])
				sum_p1 += ql[1]
			} else if (*p1)[0] <= ql[1] {
				heap.Push(p1, ql[1])
				sum_p1 += ql[1]
			} else {
				heap.Push(p2, -ql[1])
				sum_p2 += ql[1]
			}
			if len(*p1) < len(*p2) {
				k := heap.Pop(p2).(int)
				heap.Push(p1, -k)
				sum_p2 += k
				sum_p1 -= k
			}
			if len(*p1) > len(*p2)+1 {
				k := heap.Pop(p1).(int)
				heap.Push(p2, -k)
				sum_p1 -= k
				sum_p2 += k
			}
		}
	}
}
