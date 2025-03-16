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
	t      int
	queries [][]int
}

func (c *CodeforcesTask397BSolution) readInput() {
	// Read the number of queries from input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	c.t, _ = strconv.Atoi(scanner.Text())
	// Read each query and store it as a list of integers in the queries list
	for i := 0; i < c.t; i++ {
		scanner.Scan()
		query := strings.Split(scanner.Text(), " ")
		queryInt := []int{}
		for _, q := range query {
			num, _ := strconv.Atoi(q)
			queryInt = append(queryInt, num)
		}
		c.queries = append(c.queries, queryInt)
	}
}

func (c *CodeforcesTask397BSolution) processTask() {
	// Initialize a list to hold the results for each query
	res := []string{}
	// Process each query to determine if the condition is met
	for _, query := range c.queries {
		// Calculate how many complete sets of query[1] fit into query[0]
		k := query[0] / query[1]
		// Check if k multiplied by query[2] is at least query[0]
		if k * query[2] >= query[0] {
			res = append(res, "Yes")
		} else {
			res = append(res, "No")
		}
	}
	// Join the results into a single string separated by newlines
	c.result = strings.Join(res, "\n")
}

func (c *CodeforcesTask397BSolution) getResult() string {
	// Return the final result string
	return c.result
}

func main() {
	// Create an instance of the solution class
	Solution := CodeforcesTask397BSolution{}
	// Read input data
	Solution.readInput()
	// Process the task based on the input data
	Solution.processTask()
	// Print the final results
	fmt.Println(Solution.getResult())
}
