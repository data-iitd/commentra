package main

import (
	"bufio"
	"fmt"
	"os"
	"container/heap"
)

// An IntHeap is a type that implements heap.Interface and holds integers.
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] } // Max-heap
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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	fmt.Fscan(reader, &t)

	pqmax := &IntHeap{}
	heap.Init(pqmax)

	pqmin := &IntHeap{}
	heap.Init(pqmin)

	var sumMin, sumMax, sumb int64
	var min int

	for t > 0 {
		t--
		var command int
		fmt.Fscan(reader, &command)

		if command == 2 {
			ans := int64(min) * int64(len(*pqmin)) - sumMin
			ans1 := int64(min) * int64(len(*pqmax)) - sumMax
			fmt.Fprintln(writer, min, ans+ans1+sumb)
		} else {
			var in, value int
			fmt.Fscan(reader, &in, &value)
			sumb += int64(value)

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
