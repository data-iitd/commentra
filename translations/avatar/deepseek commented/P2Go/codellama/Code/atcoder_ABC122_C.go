
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the length of the string and the number of queries
	n, q := readInts()

	// Read the string
	s := readString()

	// Read the queries
	problems := readQueries(q)

	// Define a function to count occurrences of 'AC' in the string
	count := func(total int, i int) int {
		// Check if the current substring is 'AC'
		if s[i-1:i+1] == "AC" {
			// Increment the count if 'AC' is found
			return total + 1
		} else {
			// Return the total count if 'AC' is not found
			return total
		}
	}

	// Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
	cumsum := make([]int, n)
	cumsum[0] = 0
	for i := 1; i < n; i++ {
		cumsum[i] = cumsum[i-1] + count(0, i)
	}

	// Iterate over the queries and print the difference in cumulative sums
	for _, problem := range problems {
		l, r := problem[0], problem[1]
		fmt.Println(cumsum[r-1] - cumsum[l-1])
	}
}

func readInts() (int, int) {
	var n, q int
	fmt.Scan(&n, &q)
	return n, q
}

func readString() string {
	var s string
	fmt.Scan(&s)
	return s
}

func readQueries(q int) [][]int {
	problems := make([][]int, q)
	for i := 0; i < q; i++ {
		problems[i] = readInts()
	}
	return problems
}

// 