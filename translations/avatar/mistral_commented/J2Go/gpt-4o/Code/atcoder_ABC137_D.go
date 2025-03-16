package main

import (
	"container/heap"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Job struct to hold the job details
type Job struct {
	a int // Job's a value
	b int // Job's b value
}

// A PriorityQueue implements heap.Interface and holds Jobs.
type PriorityQueue []*Job

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	if pq[i].a == pq[j].a {
		return pq[i].b > pq[j].b // Max-heap based on b value
	}
	return pq[i].a < pq[j].a // Min-heap based on a value
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
	var N, M int
	var line string

	// Reading the first line of input
	fmt.Scanln(&line)
	parts := strings.Split(line, "\u2581")
	N, _ = strconv.Atoi(parts[0])
	M, _ = strconv.Atoi(parts[1])

	q := &PriorityQueue{} // Creating a new priority queue
	heap.Init(q)

	for i := 0; i < N; i++ {
		fmt.Scanln(&line)
		parts = strings.Split(line, "\u2581")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		heap.Push(q, &Job{a: a, b: b}) // Adding a new Job object to the priority queue
	}

	cnt := 0
	jobQ := &PriorityQueue{} // Creating a new priority queue for job benefits
	heap.Init(jobQ)

	for i := 1; i <= M; i++ {
		for q.Len() > 0 {
			job := (*q)[0] // Peek at the Job object at the head of the priority queue
			if job.a <= i {
				heap.Push(jobQ, job.b) // Adding the benefit of the job to the jobQ
				heap.Pop(q)            // Removing the Job object from the priority queue
			} else {
				break // Exiting the while loop
			}
		}

		if jobQ.Len() > 0 {
			cnt += heap.Pop(jobQ).(int) // Adding the benefit of the job to the counter variable and removing it from the jobQ
		}
	}

	fmt.Println(cnt) // Printing the value of the counter variable
}

// <END-OF-CODE>
