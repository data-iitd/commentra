
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
	} else {
		return j.a - otherJob.a
	}
}

func main() {
	// Step 4: Read input and initialize variables
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	line = strings.Replace(line, "\u2581", " ", -1)
	parts := strings.Split(line, " ")
	N, _ := strconv.Atoi(parts[0])
	M, _ := strconv.Atoi(parts[1])

	// Step 5: Create a slice to store jobs
	jobs := make([]Job, N)

	// Step 6: Read job details and add to the slice
	for i := 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		line = strings.Replace(line, "\u2581", " ", -1)
		parts = strings.Split(line, " ")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		jobs[i] = Job{a, b}
	}

	// Step 7: Initialize counters and another slice
	cnt := 0
	jobQ := make([]int, 0)

	// Step 8: Process each day from 1 to M
	for i := 1; i <= M; i++ {
		for _, job := range jobs {
			if job.a <= i {
				jobQ = append(jobQ, job.b)
			}
		}
		if len(jobQ) > 0 {
			sort.Ints(jobQ)
			cnt += jobQ[len(jobQ)-1]
			jobQ = jobQ[:len(jobQ)-1]
		}
	}

	// Step 10: Print the total reward
	fmt.Println(cnt)
}

