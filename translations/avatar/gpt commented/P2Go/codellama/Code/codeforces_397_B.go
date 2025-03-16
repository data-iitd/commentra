package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Initialize the result string, number of queries, and a list to hold the queries
	result := ""
	t := 0
	queries := [][]int{}

	// Read the number of queries from input
	fmt.Scan(&t)
	// Read each query and store it as a list of integers in the queries list
	for i := 0; i < t; i++ {
		query := []int{}
		fmt.Scan(&query[0], &query[1], &query[2])
		queries = append(queries, query)
	}

	// Initialize a list to hold the results for each query
	res := []string{}
	// Process each query to determine if the condition is met
	for _, query := range queries {
		// Calculate how many complete sets of query[1] fit into query[0]
		k := query[0] / query[1]
		// Check if k multiplied by query[2] is at least query[0]
		res = append(res, "Yes" if k * query[2] >= query[0] else "No")
	}
	// Join the results into a single string separated by newlines
	result = strings.Join(res, "\n")

	// Print the final results
	fmt.Println(result)
}

// 