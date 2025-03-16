
package main

import (
	"container/heap"
	"fmt"
)

// Job represents a job with a day and salary
type Job struct {
	day, salary int
}

// JobHeap is a min-heap of Jobs
type JobHeap []*Job

// Len returns the length of the JobHeap
func (h JobHeap) Len() int {
	return len(h)
}

// Less returns true if the job at index i is less than the job at index j
func (h JobHeap) Less(i, j int) bool {
	return h[i].day < h[j].day || h[i].day == h[j].day && h[i].salary < h[j].salary
}

// Swap swaps the jobs at indices i and j
func (h JobHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

// Push pushes a job onto the JobHeap
func (h *JobHeap) Push(x interface{}) {
	*h = append(*h, x.(*Job))
}

// Pop pops a job from the JobHeap
func (h *JobHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// SalaryHeap is a max-heap of salaries
type SalaryHeap []int

// Len returns the length of the SalaryHeap
func (h SalaryHeap) Len() int {
	return len(h)
}

// Less returns true if the salary at index i is less than the salary at index j
func (h SalaryHeap) Less(i, j int) bool {
	return h[i] > h[j]
}

// Swap swaps the salaries at indices i and j
func (h SalaryHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

// Push pushes a salary onto the SalaryHeap
func (h *SalaryHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

// Pop pops a salary from the SalaryHeap
func (h *SalaryHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	// Read the number of days (n) and the maximum number of jobs (m) from input
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize two heaps: one for jobs (x) and one for selected salaries (y)
	x := make(JobHeap, 0)
	y := make(SalaryHeap, 0)

	// Read the job details for n days
	for i := 0; i < n; i++ {
		// For each day, read the day number and salary
		var day, salary int
		fmt.Scan(&day, &salary)
		// Push the negative of day and salary onto the heap to create a max-heap
		heap.Push(&x, &Job{day, salary})
	}

	// Process the jobs in the heap until it's empty
	for x.Len() > 0 {
		// Pop the job with the highest day and salary (due to negation)
		d, s := heap.Pop(&x).(*Job)

		// Calculate the remaining capacity for jobs
		r := m - len(y)

		// If there is enough capacity to take the job
		if r >= -d.day {
			// Add the salary to the selected salaries heap
			heap.Push(&y, -s.salary)
		} else {
			// If capacity is full, replace the lowest salary if the new salary is higher
			heap.Push(&y, -s.salary)
			heap.Pop(&y) // Remove the lowest salary from the heap
		}
	}

	// Output the total sum of selected salaries
	fmt.Println(sum(y))
}

func sum(h SalaryHeap) int {
	var total int
	for _, s := range h {
		total += s
	}
	return total
}

