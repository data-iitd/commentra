package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Step 2: Define Job struct
type Job struct {
	a int
	b int
}

// Step 2: Implement compare method to compare jobs based on parameters a and b
func (j Job) compare(otherJob Job) int {
	if otherJob.a == j.a {
		return j.b - otherJob.b
	}
	return j.a - otherJob.a
}

func main() {
	// Step 4: Read input and initialize variables
	scanner := bufio.NewScanner(os.Stdin)
	line := strings.Split(scanner.Text(), " \u2581 ")
	N, _ := strconv.Atoi(line[0])
	M, _ := strconv.Atoi(line[1])

	// Step 5: Create a priority queue to store jobs
	q := make([]Job, 0)

	// Step 6: Read job details and add to the priority queue
	for i := 0; i < N; i++ {
		line = strings.Split(scanner.Text(), " \u2581 ")
		a, _ := strconv.Atoi(line[0])
		b, _ := strconv.Atoi(line[1])
		q = append(q, Job{a, b})
	}

	// Step 7: Initialize counters and another priority queue
	cnt := 0
	jobQ := make([]int, 0)

	// Step 8: Process each day from 1 to M
	for i := 1; i <= M; i++ {
		for len(q) > 0 {
			job := q[0]
			if job.a <= i {
				jobQ = append(jobQ, q[0].b)
				q = q[1:]
			} else {
				break
			}
		}
		if len(jobQ) > 0 {
			cnt += jobQ[0]
			jobQ = jobQ[1:]
		}
	}

	// Step 10: Print the total reward
	fmt.Println(cnt)
}

// 