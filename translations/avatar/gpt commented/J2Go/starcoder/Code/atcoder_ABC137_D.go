package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Job represents a job with two attributes 'a' and 'b'
type Job struct {
	a int
	b int
}

// JobQueue represents a priority queue of jobs
type JobQueue []*Job

// Len returns the length of the queue
func (jq JobQueue) Len() int {
	return len(jq)
}

// Less returns true if the job at index i has a lower priority than the job at index j
func (jq JobQueue) Less(i, j int) bool {
	return jq[i].a < jq[j].a
}

// Swap swaps the jobs at index i and j
func (jq JobQueue) Swap(i, j int) {
	jq[i], jq[j] = jq[j], jq[i]
}

// Push adds a job to the queue
func (jq *JobQueue) Push(x interface{}) {
	*jq = append(*jq, x.(*Job))
}

// Pop removes a job from the queue
func (jq *JobQueue) Pop() interface{} {
	old := *jq
	n := len(old)
	x := old[n-1]
	*jq = old[0 : n-1]
	return x
}

// NewJobQueue returns a new JobQueue
func NewJobQueue() JobQueue {
	return make(JobQueue, 0)
}

// ReadInput reads the input from stdin
func ReadInput() (int, int, JobQueue) {
	// Read the first line of input and split it to get N and M
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	line = strings.Replace(line, "\n", "", -1)
	line = strings.Replace(line, "\r", "", -1)
	line = strings.Replace(line, "\t", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", -1)
	line = strings.Replace(line, "  ", " ", 