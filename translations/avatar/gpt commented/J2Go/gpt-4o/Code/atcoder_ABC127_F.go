package main

import (
	"bufio"
	"fmt"
	"os"
	"container/heap"
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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	fmt.Fscan(reader, &t)

	pqmin := &IntHeap{}
	pqmax := &MaxHeap{}
	heap.Init(pqmin)
	heap.Init(pqmax)

	var sumMin, sumMax, sumb int64
	var min int

	for t > 0 {
		t--
		var op int
		var in int
		var add int64
		fmt.Fscan(reader, &op)

		if op == 2 {
			ans := int64(min) * int64(pqmin.Len()) - sumMin
			ans1 := int64(min) * int64(pqmax.Len())
			ans1 = sumMax - ans1
			fmt.Fprintln(writer, min, ans+ans1+sumb)
		} else {
			fmt.Fscan(reader, &in, &add)
			sumb += add

			if in > min {
				heap.Push(pqmax, in)
				sumMax += int64(in)
			} else {
				heap.Push(pqmin, in)
				sumMin += int64(in)
			}

			if pqmin.Len() > pqmax.Len() {
				sumMax += int64((*pqmin)[0])
				sumMin -= int64((*pqmin)[0])
				heap.Push(pqmax, heap.Pop(pqmin))
			}
			if pqmin.Len() < pqmax.Len() {
				sumMax -= int64((*pqmax)[0])
				sumMin += int64((*pqmax)[0])
				heap.Push(pqmin, heap.Pop(pqmax))
			}

			if pqmin.Len() > 0 {
				min = (*pqmin)[0]
			}
		}
	}
}

// <END-OF-CODE>
