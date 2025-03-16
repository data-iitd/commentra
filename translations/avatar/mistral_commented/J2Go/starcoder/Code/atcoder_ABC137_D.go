package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Job is a struct that represents a job
type Job struct {
	a int
	b int
}

// JobQueue is a struct that represents a job queue
type JobQueue []Job

// Len returns the length of the job queue
func (jq JobQueue) Len() int {
	return len(jq)
}

// Less returns true if the job at index i is less than the job at index j
func (jq JobQueue) Less(i, j int) bool {
	return jq[i].a < jq[j].a
}

// Swap swaps the jobs at index i and j
func (jq JobQueue) Swap(i, j int) {
	jq[i], jq[j] = jq[j], jq[i]
}

// Push adds a new job to the job queue
func (jq *JobQueue) Push(x interface{}) {
	*jq = append(*jq, x.(Job))
}

// Pop removes the job at the head of the job queue
func (jq *JobQueue) Pop() interface{} {
	old := *jq
	n := len(old)
	x := old[n-1]
	*jq = old[0 : n-1]
	return x
}

// NewJobQueue returns a new job queue
func NewJobQueue() JobQueue {
	return make(JobQueue, 0)
}

// NewJob returns a new job
func NewJob(a, b int) Job {
	return Job{a, b}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanLines)

	var N, M int
	sc.Scan()
	line := strings.Split(sc.Text(), "\u2581")
	N, _ = strconv.Atoi(line[0])
	M, _ = strconv.Atoi(line[1])

	jq := NewJobQueue()
	for i := 0; i < N; i++ {
		sc.Scan()
		line := strings.Split(sc.Text(), "\u2581")
		jq = append(jq, NewJob(
			int(line[0]),
			int(line[1]),
		))
	}

	cnt := 0
	jobQ := make(JobQueue, 0)
	for i := 1; i <= M; i++ {
		for len(jq) > 0 {
			job := jq[0]
			if job.a <= i {
				jobQ = append(jobQ, job)
				jq = jq[1:]
			} else {
				break
			}
		}

		if len(jobQ) > 0 {
			cnt += jobQ[0].b
			jobQ = jobQ[1:]
		}
	}

	fmt.Println(cnt)
}

