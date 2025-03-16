package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Job represents a job with two attributes 'a' and 'b'
type Job struct {
	a int
	b int
}

// Implement the sort.Interface for []Job based on 'a'
type ByA []Job

func (a ByA) Len() int           { return len(a) }
func (a ByA) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByA) Less(i, j int) bool { return a[i].a < a[j].a }

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	lineSplit := bufSplit(line, " \u2581 ")
	N := toInt(lineSplit[0])
	M := toInt(lineSplit[1])

	// Read the job details and add them to the slice
	jobs := make([]Job, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		line = scanner.Text()
		lineSplit = bufSplit(line, " \u2581 ")
		jobs[i] = Job{toInt(lineSplit[0]), toInt(lineSplit[1])}
	}

	// Sort the jobs based on 'a'
	sort.Sort(ByA(jobs))

	cnt := 0
	jobQ := make([]int, 0)

	// Process jobs for each time unit from 1 to M
	for i := 1; i <= M; i++ {
		// While there are jobs that can be processed at time i
		for len(jobs) > 0 && jobs[0].a <= i {
			job := jobs[0]
			jobs = jobs[1:]
			jobQ = append(jobQ, job.b)
		}
		// If there are jobs available to process, add the highest value job to the counter
		if len(jobQ) > 0 {
			sort.Sort(sort.Reverse(sort.IntSlice(jobQ)))
			cnt += jobQ[0]
			jobQ = jobQ[1:]
		}
	}

	// Output the total value of jobs processed
	fmt.Println(cnt)
}

// Helper function to split a string by a delimiter
func bufSplit(s, delim string) []string {
	result := []string{}
	start := 0
	for i := 0; i < len(s); i++ {
		if s[i:i+len(delim)] == delim {
			result = append(result, s[start:i])
			start = i + len(delim)
		}
	}
	if start < len(s) {
		result = append(result, s[start:])
	}
	return result
}

// Helper function to convert a string to an integer
func toInt(s string) int {
	result := 0
	sign := 1
	for _, c := range s {
		if c == '-' {
			sign = -1
		} else {
			result = result*10 + int(c-'0')
		}
	}
	return result * sign
}

