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
func (h MaxHeap) Less(i, j int) bool { return h[i].day > h[j].day }
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

	y := &MaxHeap{}
	heap.Init(y)

	for x.Len() > 0 {
		job := heap.Pop(x).(Job)
		r := m - y.Len()

		if r >= job.day {
			heap.Push(y, Job{day: job.day, salary: job.salary})
		} else {
			heap.Push(y, Job{day: job.day, salary: job.salary})
			heap.Pop(y)
		}
	}

	totalSalary := 0
	for y.Len() > 0 {
		job := heap.Pop(y).(Job)
		totalSalary += job.salary
	}

	fmt.Println(totalSalary)
}

// <END-OF-CODE>
