package main

import (
	"container/heap"
	"fmt"
)

// Define a priority queue (max-heap) using a slice of int
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
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize slices to store job days and salaries
	x := &MaxHeap{}
	y := &MaxHeap{}

	// Read each job's day and salary, and push them into the heap x
	for i := 0; i < n; i++ {
		var day, salary int
		fmt.Scan(&day, &salary)
		// Push the day and salary as negative values to simulate a max-heap
		heap.Push(x, -day)
		heap.Push(x, -salary)
	}

	// Process the jobs in the order of their deadlines
	for x.Len() > 0 {
		// Pop the job with the largest deadline (negated values)
		d := heap.Pop(x).(int)
		s := heap.Pop(x).(int)

		// Calculate the remaining days available for new jobs
		r := m - y.Len()

		// If there are enough days to accommodate this job
		if r >= -d {
			// Add the salary to the list of chosen salaries
			heap.Push(y, -s)
		} else {
			// If not enough days, check if we need to remove the smallest salary
			heap.Push(y, -s)
			heap.Pop(y)
		}
	}

	// Output the sum of the chosen salaries
	sum := 0
	for y.Len() > 0 {
		sum += heap.Pop(y).(int)
	}
	fmt.Println(sum)
}

