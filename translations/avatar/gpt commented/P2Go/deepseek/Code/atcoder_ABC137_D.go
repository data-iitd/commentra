package main

import (
	"container/heap"
	"fmt"
)

// Define a custom type for the job heap
type JobHeap [][2]int

func (h JobHeap) Len() int           { return len(h) }
func (h JobHeap) Less(i, j int) bool { return h[i][0] > h[j][0] || (h[i][0] == h[j][0] && h[i][1] > h[j][1]) }
func (h JobHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *JobHeap) Push(x interface{}) {
	*h = append(*h, x.([2]int))
}

func (h *JobHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// Define a custom type for the salary heap
type SalaryHeap []int

func (h SalaryHeap) Len() int           { return len(h) }
func (h SalaryHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h SalaryHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *SalaryHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *SalaryHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize two heaps: one for jobs (x) and one for selected salaries (y)
	x := &JobHeap{}
	y := &SalaryHeap{}
	heap.Init(x)
	heap.Init(y)

	// Read the job details for n days
	for i := 0; i < n; i++ {
		var day, salary int
		fmt.Scan(&day, &salary)
		// Push the negative of day and salary onto the heap to create a max-heap
		heap.Push(x, [2]int{-day, -salary})
	}

	// Process the jobs in the heap until it's empty
	for x.Len() > 0 {
		// Pop the job with the highest day and salary (due to negation)
		d, s := heap.Pop(x).([2]int)
		d, s = -d, -s

		// Calculate the remaining capacity for jobs
		r := m - len(*y)

		// If there is enough capacity to take the job
		if r >= d {
			// Add the salary to the selected salaries heap
			heap.Push(y, s)
		} else {
			// If capacity is full, replace the lowest salary if the new salary is higher
			heap.Push(y, s)
			heap.Remove(y, 0) // Remove the lowest salary from the heap
		}
	}

	// Output the total sum of selected salaries
	total := 0
	for _, salary := range *y {
		total += salary
	}
	fmt.Println(total)
}
