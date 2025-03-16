package main

import (
	"container/heap"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Job struct to hold job parameters
type Job struct {
	a int
	b int
}

// JobHeap is a min-heap of Jobs
type JobHeap []Job

func (h JobHeap) Len() int           { return len(h) }
func (h JobHeap) Less(i, j int) bool { 
	if h[i].a == h[j].a {
		return h[i].b < h[j].b
	}
	return h[i].a < h[j].a 
}
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
	var N, M int
	fmt.Scanln(&N, &M)

	// Create a priority queue for jobs
	jobQueue := &JobHeap{}
	heap.Init(jobQueue)

	// Read job details and add to the priority queue
	for i := 0; i < N; i++ {
		var a, b int
		line := ""
		fmt.Scanln(&line)
		parts := strings.Split(line, " ░ ")
		a, _ = strconv.Atoi(parts[0])
		b, _ = strconv.Atoi(parts[1])
		heap.Push(jobQueue, Job{a: a, b: b})
	}

	// Initialize counters and another priority queue for job rewards
	cnt := 0
	rewardQueue := &JobHeap{}
	heap.Init(rewardQueue)

	// Process each day from 1 to M
	for i := 1; i <= M; i++ {
		for jobQueue.Len() > 0 {
			job := (*jobQueue)[0]
			if job.a <= i {
				heap.Pop(jobQueue)
				heap.Push(rewardQueue, Job{b: job.b})
			} else {
				break
			}
		}
		if rewardQueue.Len() > 0 {
			reward := heap.Pop(rewardQueue).(Job).b
			cnt += reward
		}
	}

	// Print the total reward
	fmt.Println(cnt)
}

// <END-OF-CODE>
