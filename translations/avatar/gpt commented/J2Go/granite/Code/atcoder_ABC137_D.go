
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

// CompareTo method to define the ordering of Jobs
func (j *Job) CompareTo(otherJob *Job) int {
	// Compare based on 'a' first, and if equal, then by 'b'
	if otherJob.a == j.a {
		return j.b - otherJob.b
	} else {
		return j.a - otherJob.a
	}
}

func main() {
	// Create a Scanner object to read input
	sc := bufio.NewScanner(os.Stdin)

	// Read the first line of input and split it to get N and M
	sc.Scan()
	line := strings.Split(sc.Text(), " ")
	N, _ := strconv.Atoi(line[0]) // Number of jobs
	M, _ := strconv.Atoi(line[1]) // Maximum time or limit

	// Create a priority queue to hold the jobs
	q := make([]*Job, 0)

	// Read the job details and add them to the priority queue
	for i := 0; i < N; i++ {
		sc.Scan()
		line = strings.Split(sc.Text(), " ")
		a, _ := strconv.Atoi(line[0])
		b, _ := strconv.Atoi(line[1])
		q = append(q, &Job{a, b})
	}

	// Sort the jobs in descending order based on their values
	for i := 0; i < len(q); i++ {
		for j := 0; j < len(q)-1-i; j++ {
			if q[j].b < q[j+1].b {
				q[j], q[j+1] = q[j+1], q[j]
			}
		}
	}

	cnt := 0 // Counter to accumulate the total value of jobs processed
	jobQ := make([]int, 0) // Queue to hold job values in descending order

	// Process jobs for each time unit from 1 to M
	for i := 1; i <= M; i++ {
		// While there are jobs that can be processed at time i
		for len(q) > 0 && q[0].a <= i {
			jobQ = append(jobQ, q[0].b) // Add the value of the job to jobQ
			q = q[1:] // Remove the job from the queue
		}

		// If there are jobs available to process, add the highest value job to the counter
		if len(jobQ) > 0 {
			cnt += jobQ[len(jobQ)-1] // Add the highest value job to cnt
			jobQ = jobQ[:len(jobQ)-1] // Remove the highest value job from jobQ
		}
	}

	// Output the total value of jobs processed
	fmt.Println(cnt)
}

// END-OF-CODE