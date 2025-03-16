package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Job struct {
	a int
	b int
}

func (j Job) Compare(other Job) int {
	if j.a == other.a {
		return j.b - other.b
	}
	return j.a - other.a
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	line := scanner.Text()
	parts := splitDelimiters(line, "\u2581")
	N := parseInt(parts[0])
	M := parseInt(parts[1])

	q := make([]Job, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		line = scanner.Text()
		parts = splitDelimiters(line, "\u2581")
		q[i] = Job{a: parseInt(parts[0]), b: parseInt(parts[1])}
	}

	sort.Slice(q, func(i, j int) bool {
		return q[i].Compare(q[j]) < 0
	})

	cnt := 0
	jobQ := make([]int, 0)

	for i := 1; i <= M; i++ {
		for len(q) > 0 {
			job := q[0]
			if job.a <= i {
				jobQ = append(jobQ, job.b)
				q = q[1:]
			} else {
				break
			}
		}

		if len(jobQ) > 0 {
			sort.Sort(sort.Reverse(sort.IntSlice(jobQ)))
			cnt += jobQ[0]
			jobQ = jobQ[1:]
		}
	}

	fmt.Println(cnt)
}

func splitDelimiters(s, delimiter string) []string {
	result := []string{}
	start := 0
	for i := 0; i < len(s); i++ {
		if string(s[i]) == delimiter {
			if i > start {
				result = append(result, s[start:i])
			}
			start = i + 1
		}
	}
	if start < len(s) {
		result = append(result, s[start:])
	}
	return result
}

func parseInt(s string) int {
	var result int
	fmt.Sscanf(s, "%d", &result)
	return result
}
