
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Job struct {
	Day    int
	Salary int
}

type JobHeap []Job

func (h JobHeap) Len() int           { return len(h) }
func (h JobHeap) Less(i, j int) bool { return h[i].Day < h[j].Day }
func (h JobHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *JobHeap) Push(x interface{}) {
	*h = append(*h, x.(Job))
}

func (h *JobHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	// Read the number of days (n) and the maximum number of jobs (m) from input
	data, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	data = strings.TrimSpace(string(data))
	parts := strings.Split(data, " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	// Initialize two heaps: one for jobs (x) and one for selected salaries (y)
	x := &JobHeap{}
	y := &JobHeap{}

	// Read the job details for n days
	for i := 0; i < n; i++ {
		data, _ := bufio.NewReader(os.Stdin).ReadString('\n')
		data = strings.TrimSpace(string(data))
		parts := strings.Split(data, " ")
		day, _ := strconv.Atoi(parts[0])
		salary, _ := strconv.Atoi(parts[1])
		// Push the job onto the heap
		heap.Push(x, Job{Day: day, Salary: salary})
	}

	// Process the jobs in the heap until it's empty
	for x.Len() > 0 {
		// Pop the job with the highest day and salary
		job := heap.Pop(x).(Job)

		// Calculate the remaining capacity for jobs
		r := m - y.Len()

		// If there is enough capacity to take the job
		if r >= job.Day {
			// Add the job to the selected salaries heap
			heap.Push(y, job)
		} else {
			// If capacity is full, replace the lowest salary if the new salary is higher
			if y.Len() > 0 && y.Less(0, &job) {
				heap.Push(y, job)
				heap.Pop(y) // Remove the lowest salary from the heap
			}
		}
	}

	// Output the total sum of selected salaries
	sum := 0
	for y.Len() > 0 {
		sum += y.Pop().Salary
	}
	fmt.Println(sum)
}
