package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Class representing a Job with two attributes 'a' and 'b'
type Job struct {
	a int // Represents the time or priority of the job
	b int // Represents the value or weight of the job
}

// Override compareTo method to define the ordering of Jobs
func (j Job) CompareTo(otherJob Job) int {
	// Compare based on 'a' first, and if equal, then by 'b'
	if otherJob.a == j.a {
		return j.b - otherJob.b
	}
	return j.a - otherJob.a
}

func main() {
	// Create a Scanner object to read input
	sc := bufio.NewScanner(os.Stdin)

	// Read the first line of input and split it to get N and M
	line := strings.Split(sc.Text(), " \u2581 ")
	N, _ := strconv.Atoi(line[0]) // Number of jobs
	M, _ := strconv.Atoi(line[1]) // Maximum time or limit

	// Create a priority queue to hold the jobs
	q := make([]Job, 0)

	// Read the job details and add them to the priority queue
	for i := 0; i < N; i++ {
		line = strings.Split(sc.Text(), " \u2581 ")
		a, _ := strconv.Atoi(line[0])
		b, _ := strconv.Atoi(line[1])
		q = append(q, Job{a, b})
	}

	cnt := 0 // Counter to accumulate the total value of jobs processed
	jobQ := make([]int, 0) // Queue to hold job values in descending order

	// Process jobs for each time unit from 1 to M
	for i := 1; i <= M; i++ {
		// While there are jobs that can be processed at time i
		for len(q) > 0 {
			job := q[0] // Peek at the job with the highest priority
			if job.a <= i { // If the job can be processed at time i
				jobQ = append(jobQ, q[0].b) // Remove the job from the queue and add its value to jobQ
				q = q[1:]
			} else {
				break // Break if the job cannot be processed yet
			}
		}
		// If there are jobs available to process, add the highest value job to the counter
		if len(jobQ) > 0 {
			cnt += jobQ[0] // Poll the highest value job from jobQ and add to cnt
			jobQ = jobQ[1:]
		}
	}

	// Output the total value of jobs processed
	fmt.Println(cnt)
}

