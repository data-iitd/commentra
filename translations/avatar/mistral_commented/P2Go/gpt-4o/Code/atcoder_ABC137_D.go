package main

import (
	"container/heap"
	"fmt"
)

// An Item is something we manage in a priority queue.
type Item struct {
	day    int
	salary int
}

// A MinHeap is a min-heap of Items.
type MinHeap []Item

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].day > h[j].day } // Max-heap by day
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(Item))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	item := old[n-1]
	*h = old[0 : n-1]
	return item
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	x := &MinHeap{}
	heap.Init(x)

	for i := 0; i < n; i++ {
		var day, salary int
		fmt.Scan(&day, &salary)
		heap.Push(x, Item{day: -day, salary: -salary}) // Store negative values
	}

	y := &MinHeap{}
	heap.Init(y)

	for x.Len() > 0 {
		item := heap.Pop(x).(Item)
		d := item.day
		s := item.salary
		r := m - y.Len()

		if r >= d {
			heap.Push(y, Item{day: d, salary: s})
		} else {
			heap.Push(y, Item{day: d, salary: s})
			heap.Pop(y)
		}
	}

	totalSalary := 0
	for _, item := range *y {
		totalSalary += -item.salary // Convert back to positive salary
	}

	fmt.Println(totalSalary)
}

// <END-OF-CODE>
