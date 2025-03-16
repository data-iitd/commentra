
package main

import (
	"fmt"
	"strconv"
	"strings"
)

// CodeforcesTask397BSolution struct
type CodeforcesTask397BSolution struct {
	result string
	t      int
	queries [][]int
}

// Constructor method with initializations
func (s *CodeforcesTask397BSolution) init() {
	s.result = ""
	s.t = 0
	s.queries = [][]int{}
}

// Method to read input
func (s *CodeforcesTask397BSolution) readInput() {
	var err error
	s.t, err = strconv.Atoi(strings.TrimSpace(fmt.Sscanf(input(), "%d", &s.t)))
	if err != nil {
		panic(err)
	}
	for i := 0; i < s.t; i++ {
		query := strings.Split(strings.TrimSpace(fmt.Sscanf(input(), "%s", &query)), " ")
		for j := 0; j < len(query); j++ {
			query[j], err = strconv.Atoi(query[j])
			if err != nil {
				panic(err)
			}
		}
		s.queries = append(s.queries, query)
	}
}

// Method to process the task
func (s *CodeforcesTask397BSolution) processTask() {
	res := []string{}
	for _, query := range s.queries {
		k := query[0] / query[1]
		res = append(res, "Yes" if k*query[2] >= query[0] else "No")
	}
	s.result = strings.Join(res, "\n")
}

// Method to get the result
func (s *CodeforcesTask397BSolution) getResult() string {
	return s.result
}

// Main method to run the code
func main() {
	Solution := &CodeforcesTask397BSolution{}
	Solution.init()
	Solution.readInput()
	Solution.processTask()
	fmt.Println(Solution.getResult())
}

