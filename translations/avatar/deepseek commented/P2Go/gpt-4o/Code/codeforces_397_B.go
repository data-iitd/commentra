package main

import (
	"fmt"
	"strings"
)

type CodeforcesTask397BSolution struct {
	result   string
	t        int
	queries  [][]int
}

// Reads the number of test cases and the queries from input
func (s *CodeforcesTask397BSolution) readInput() {
	fmt.Scan(&s.t) // Read the number of test cases
	s.queries = make([][]int, s.t)
	for i := 0; i < s.t; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c) // Read each query
		s.queries[i] = []int{a, b, c}
	}
}

// Processes each query to determine if the condition is met
func (s *CodeforcesTask397BSolution) processTask() {
	res := []string{}
	for _, query := range s.queries {
		k := query[0] / query[1] // Calculate k as the integer division of query[0] by query[1]
		if k*query[2] >= query[0] {
			res = append(res, "Yes") // Append "Yes" if the condition is met
		} else {
			res = append(res, "No") // Append "No" otherwise
		}
	}
	s.result = strings.Join(res, "\n") // Join the results into a single string with newline characters
}

// Returns the final result
func (s *CodeforcesTask397BSolution) getResult() string {
	return s.result
}

func main() {
	solution := CodeforcesTask397BSolution{}
	solution.readInput()
	solution.processTask()
	fmt.Println(solution.getResult()) // Print the final result
}

// <END-OF-CODE>
