package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of queries from input
	var t int
	fmt.Scanln(&t)
	// Read each query and store it as a list of integers in the queries list
	var queries [][]int
	for i := 0; i < t; i++ {
		var query []int
		fmt.Scanln(&query[0], &query[1], &query[2])
		queries = append(queries, query)
	}
	// Initialize a list to hold the results for each query
	var res []string
	// Process each query to determine if the condition is met
	for _, query := range queries {
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
	fmt.Println(strings.Join(res, "\n"))
}

