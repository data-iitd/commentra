package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read the number of characters in the string and the number of queries
	var n, q int
	fmt.Scan(&n, &q)

	// Read the input string
	var s string
	fmt.Scan(&s)

	// Read the queries, each containing two integers l and r
	problems := make([][]int, q)
	for i := range problems {
		problems[i] = make([]int, 2)
		fmt.Scan(&problems[i][0], &problems[i][1])
	}

	// Define a function to count occurrences of 'AC' in the string
	count := func(total int, i int) int {
		// Increment total if the substring from index i-1 to i is 'AC'
		if s[i-1:i+1] == "AC" {
			return total + 1
		}
		return total
	}

	// Create a cumulative sum list to keep track of 'AC' occurrences
	cumsum := make([]int, n)
	cumsum[0] = 0
	for i := 1; i < n; i++ {
		cumsum[i] = cumsum[i-1] + count(0, i)
	}

	// Process each query to find the number of 'AC' occurrences in the specified range
	for _, problem := range problems {
		// Output the difference in cumulative sums to get the count in the range [l, r]
		fmt.Println(cumsum[problem[1]-1] - cumsum[problem[0]-1])
	}
}

