package main

import (
	"container/heap"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Job represents a job with two attributes 'a' and 'b'
type Job struct {
	a int // Represents the time or priority of the job
	b int // Represents the value or weight of the job
}

// A PriorityQueue implements heap.Interface and holds Jobs
type PriorityQueue []*Job

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	if pq[i].a == pq[j].a {
		return pq[i].b > pq[j].b // Max-heap based on 'b' if 'a' is equal
	}
	return pq[i].a < pq[j].a // Min-heap based on 'a'
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(*Job))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	job := old[n-1]
	*pq = old[0 : n-1]
	return job
}

func main() {
	// Create a scanner to read input
	var N, M int
	fmt.Scanln(&N, &M)

	// Create a priority queue to hold the jobs
	jobQueue := &PriorityQueue{}
	heap.Init(jobQueue)

	// Read the job details and add them to the priority queue
	for i := 0; i < N; i++ {
		var a, b int
		fmt.Scanln(&a, &b)
		heap.Push(jobQueue, &Job{a: a, b: b})
	}

	cnt := 0 // Counter to accumulate the total value of jobs processed
	valueQueue := &PriorityQueue{} // Queue to hold job values in descending order
	heap.Init(valueQueue)

	// Process jobs for each time unit from 1 to M
	for i := 1; i <= M; i++ {
		// While there are jobs that can be processed at time i
		for jobQueue.Len() > 0 {
			job := (*jobQueue)[0] // Peek at the job with the highest priority
			if job.a <= i {       // If the job can be processed at time i
				heap.Pop(jobQueue) // Remove the job from the queue
				heap.Push(valueQueue, job.b) // Add its value to valueQueue
			} else {
				break // Break if the job cannot be processed yet
			}
		}
		// If there are jobs available to process, add the highest value job to the counter
		if valueQueue.Len() > 0 {
			cnt += heap.Pop(valueQueue).(int) // Poll the highest value job from valueQueue and add to cnt
		}
	}

	// Output the total value of jobs processed
	fmt.Println(cnt)
}

// <END-OF-CODE>
