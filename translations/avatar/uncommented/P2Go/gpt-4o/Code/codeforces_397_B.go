package main

import (
	"fmt"
)

type CodeforcesTask397BSolution struct {
	result   string
	t        int
	queries  [][]int
}

func (s *CodeforcesTask397BSolution) readInput() {
	fmt.Scan(&s.t)
	s.queries = make([][]int, s.t)
	for i := 0; i < s.t; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		s.queries[i] = []int{a, b, c}
	}
}

func (s *CodeforcesTask397BSolution) processTask() {
	res := make([]string, 0, s.t)
	for _, query := range s.queries {
		k := query[0] / query[1]
		if k*query[2] >= query[0] {
			res = append(res, "Yes")
		} else {
			res = append(res, "No")
		}
	}
	s.result = join(res, "\n")
}

func (s *CodeforcesTask397BSolution) getResult() string {
	return s.result
}

func join(arr []string, sep string) string {
	result := ""
	for i, str := range arr {
		if i > 0 {
			result += sep
		}
		result += str
	}
	return result
}

func main() {
	solution := CodeforcesTask397BSolution{}
	solution.readInput()
	solution.processTask()
	fmt.Println(solution.getResult())
}

// <END-OF-CODE>
