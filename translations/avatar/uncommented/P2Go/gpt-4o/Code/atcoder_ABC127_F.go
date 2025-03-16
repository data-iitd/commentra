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
	var q int
	fmt.Scan(&q)

	ans := []int{0, 0}
	p1 := &IntHeap{}
	p2 := &IntHeap{}
	heap.Init(p1)
	heap.Init(p2)

	sumB := 0
	sumP1 := 0
	sumP2 := 0

	for i := 0; i < q; i++ {
		var ql [3]int
		for j := 0; j < 3; j++ {
			fmt.Scan(&ql[j])
		}

		if ql[0] == 2 {
			if p1.Len() == p2.Len() {
				fmt.Println(-(*p2)[0], sumP1-len(*p1)*-(*p2)[0]+len(*p2)*-(*p2)[0]-sumP2+sumB)
			} else {
				fmt.Println((*p1)[0], sumP1-len(*p1)*(*p1)[0]+len(*p2)*(*p1)[0]-sumP2+sumB)
			}
		} else {
			sumB += ql[2]
			if p1.Len() == 0 {
				heap.Push(p1, ql[1])
				sumP1 += ql[1]
			} else if (*p1)[0] <= ql[1] {
				heap.Push(p1, ql[1])
				sumP1 += ql[1]
			} else {
				heap.Push(p2, -ql[1])
				sumP2 += ql[1]
			}

			if p1.Len() < p2.Len() {
				k := heap.Pop(p2).(int)
				heap.Push(p1, -k)
				sumP2 += k
				sumP1 -= k
			}
			if p1.Len()-1 > p2.Len() {
				k := heap.Pop(p1).(int)
				heap.Push(p2, -k)
				sumP1 -= k
				sumP2 += k
			}
		}
	}
}

// <END-OF-CODE>
