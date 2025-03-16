package main

import (
	"container/heap"
	"fmt"
)

type Item struct {
	day     int
	salary  int
}

type MaxHeap []Item

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i].day > h[j].day }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(Item))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	item := old[n-1]
	*h = old[0 : n-1]
	return item
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	x := &MaxHeap{}
	heap.Init(x)

	for i := 0; i < n; i++ {
		var day, salary int
		fmt.Scan(&day, &salary)
		heap.Push(x, Item{day: day, salary: salary})
	}

	y := &MaxHeap{}
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
		totalSalary += item.salary
	}

	fmt.Println(totalSalary)
}

// <END-OF-CODE>
