package main

import (
	"fmt"
	"strings"
)

type CodeforcesTask397BSolution struct {
	result  string
	t       int
	queries [][]int
}

func (s *CodeforcesTask397BSolution) readInput() {
	// Read the number of queries from input
	fmt.Scan(&s.t)
	// Read each query and store it as a slice of integers in the queries slice
	s.queries = make([][]int, s.t)
	for i := 0; i < s.t; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		s.queries[i] = []int{a, b, c}
	}
}

func (s *CodeforcesTask397BSolution) processTask() {
	// Initialize a slice to hold the results for each query
	res := make([]string, 0, s.t)
	// Process each query to determine if the condition is met
	for _, query := range s.queries {
		// Calculate how many complete sets of query[1] fit into query[0]
		k := query[0] / query[1]
		// Check if k multiplied by query[2] is at least query[0]
		if k*query[2] >= query[0] {
			res = append(res, "Yes")
		} else {
			res = append(res, "No")
		}
	}
	// Join the results into a single string separated by newlines
	s.result = strings.Join(res, "\n")
}

func (s *CodeforcesTask397BSolution) getResult() string {
	// Return the final result string
	return s.result
}

func main() {
	// Create an instance of the solution struct
	solution := CodeforcesTask397BSolution{}
	// Read input data
	solution.readInput()
	// Process the task based on the input data
	solution.processTask()
	// Print the final results
	fmt.Println(solution.getResult())
}

// <END-OF-CODE>
