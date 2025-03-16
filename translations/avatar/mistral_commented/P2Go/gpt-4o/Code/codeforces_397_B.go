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

// Method to read input
func (s *CodeforcesTask397BSolution) readInput() {
	fmt.Scan(&s.t) // Read the number of queries from the input
	s.queries = make([][]int, s.t) // Initialize the queries slice
	for i := 0; i < s.t; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c) // Read each query
		s.queries[i] = []int{a, b, c} // Store the query in the slice
	}
}

// Method to process the task
func (s *CodeforcesTask397BSolution) processTask() {
	res := make([]string, 0, s.t) // Initialize a slice to store the results
	for _, query := range s.queries {
		k := query[0] / query[1] // Calculate the value of k for the current query
		if k*query[2] >= query[0] {
			res = append(res, "Yes") // Append "Yes" if the condition is met
		} else {
			res = append(res, "No") // Append "No" otherwise
		}
	}
	s.result = strings.Join(res, "\n") // Join the results with newline character
}

// Method to get the result
func (s *CodeforcesTask397BSolution) getResult() string {
	return s.result // Return the result string
}

// Main method to run the code
func main() {
	solution := CodeforcesTask397BSolution{} // Create an instance of the CodeforcesTask397BSolution struct
	solution.readInput()                       // Read the input
	solution.processTask()                     // Process the task
	fmt.Println(solution.getResult())          // Print the result
}

// <END-OF-CODE>
