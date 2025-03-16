package main

import (
	"container/heap"
	"fmt"
)

type Job struct {
	day    int
	salary int
}

type MaxHeap []Job

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i].day > h[j].day || (h[i].day == h[j].day && h[i].salary > h[j].salary) }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(Job))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

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

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	x := &MaxHeap{}
	heap.Init(x)

	for i := 0; i < n; i++ {
		var day, salary int
		fmt.Scan(&day, &salary)
		heap.Push(x, Job{day: day, salary: salary})
	}

	y := &MinHeap{}
	heap.Init(y)

	for x.Len() > 0 {
		job := heap.Pop(x).(Job)

		r := m - y.Len()

		if r >= job.day {
			heap.Push(y, job.salary)
		} else {
			heap.Push(y, job.salary)
			heap.Pop(y) // Remove the lowest salary from the heap
		}
	}

	total := 0
	for y.Len() > 0 {
		total += heap.Pop(y).(int)
	}

	fmt.Println(total)
}

// <END-OF-CODE>
