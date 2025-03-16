package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Job struct {
	a, b int
}

func (j Job) Compare(other Job) int {
	if j.a == other.a {
		return j.b - other.b
	}
	return j.a - other.a
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, "\u2581")
	N := parseInt(parts[0])
	M := parseInt(parts[1])

	jobs := make([]Job, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		line := scanner.Text()
		parts := strings.Split(line, "\u2581")
		jobs[i] = Job{parseInt(parts[0]), parseInt(parts[1])}
	}

	sort.Slice(jobs, func(i, j int) bool {
		if jobs[i].a == jobs[j].a {
			return jobs[i].b < jobs[j].b
		}
		return jobs[i].a < jobs[j].a
	})

	cnt := 0
	jobQueue := &PriorityQueue{}
	heap.Init(jobQueue)

	for i := 1; i <= M; i++ {
		for len(jobs) > 0 && jobs[0].a <= i {
			job := jobs[0]
			jobs = jobs[1:]
			heap.Push(jobQueue, job.b)
		}
		if jobQueue.Len() > 0 {
			cnt += heap.Pop(jobQueue).(int)
		}
	}

	fmt.Println(cnt)
}

func parseInt(s string) int {
	var result int
	fmt.Sscanf(s, "%d", &result)
	return result
}

type PriorityQueue []int

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] > pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}
