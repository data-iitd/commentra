package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Step 2: Define Job struct
type Job struct {
	a, b int
}

// Step 2: Implement compare method for Job
type ByA []Job

func (a ByA) Len() int           { return len(a) }
func (a ByA) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByA) Less(i, j int) bool { return a[i].a < a[j].a }

// Step 2: Implement compare method for Job
type ByB []Job

func (b ByB) Len() int           { return len(b) }
func (b ByB) Swap(i, j int)      { b[i], b[j] = b[j], b[i] }
func (b ByB) Less(i, j int) bool { return b[i].b > b[j].b }

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	lineParts := strings.Split(line, " \u2581 ")
	N := parseInt(lineParts[0])
	M := parseInt(lineParts[1])
	
	// Step 5: Create a slice to store jobs
	jobs := make([]Job, N)
	
	// Step 6: Read job details and add to the slice
	for i := 0; i < N; i++ {
		scanner.Scan()
		line = scanner.Text()
		lineParts = strings.Split(line, " \u2581 ")
		jobs[i] = Job{a: parseInt(lineParts[0]), b: parseInt(lineParts[1])}
	}
	
	// Step 7: Sort jobs based on parameter a
	sort.Sort(ByA(jobs))
	
	// Step 7: Initialize counters and another slice
	cnt := 0
	jobQ := []int{}
	
	// Step 8: Process each day from 1 to M
	for i := 1; i <= M; i++ {
		for len(jobs) > 0 && jobs[0].a <= i {
			job := jobs[0]
			jobs = jobs[1:]
			jobQ = append(jobQ, job.b)
		}
		if len(jobQ) > 0 {
			sort.Sort(sort.Reverse(ByB(jobQ)))
			cnt += jobQ[0]
			jobQ = jobQ[:len(jobQ)-1]
		}
	}
	
	// Step 10: Print the total reward
	fmt.Println(cnt)
}

// Helper function to parse string to int
func parseInt(s string) int {
	var num int
	fmt.Sscanf(s, "%d", &num)
	return num
}

