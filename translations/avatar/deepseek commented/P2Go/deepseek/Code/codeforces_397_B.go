package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type CodeforcesTask397BSolution struct {
	result string
	t        int
	queries  [][]int
}

// Reads the number of test cases and the queries from input
func (c *CodeforcesTask397BSolution) readInput() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	c.t, _ = strconv.Atoi(scanner.Text()) // Read the number of test cases
	for i := 0; i < c.t; i++ {
		scanner.Scan()
		query := strings.Split(scanner.Text(), " ")
		queryInt := []int{}
		for _, q := range query {
			qInt, _ := strconv.Atoi(q)
			queryInt = append(queryInt, qInt)
		}
		c.queries = append(c.queries, queryInt)
	}
}

// Processes each query to determine if the condition is met
func (c *CodeforcesTask397BSolution) processTask() {
	res := []string{}
	for _, query := range c.queries {
		k := query[0] / query[1] // Calculate k as the integer division of query[0] by query[1]
		if k*query[2] >= query[0] {
			res = append(res, "Yes")
		} else {
			res = append(res, "No")
		}
	}
	c.result = strings.Join(res, "\n") // Join the results into a single string with newline characters
}

// Returns the final result
func (c *CodeforcesTask397BSolution) getResult() string {
	return c.result
}

func main() {
	Solution := CodeforcesTask397BSolution{}
	Solution.readInput()
	Solution.processTask()
	fmt.Println(Solution.getResult()) // Print the final result
}

