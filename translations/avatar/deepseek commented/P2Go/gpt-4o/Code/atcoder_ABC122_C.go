package main

import (
	"fmt"
)

func main() {
	var n, q int
	// Read the length of the string and the number of queries
	fmt.Scan(&n, &q)

	// Read the string
	var s string
	fmt.Scan(&s)

	// Read the queries
	problems := make([][2]int, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&problems[i][0], &problems[i][1])
	}

	// Define a function to count occurrences of 'AC' in the string
	count := func(total int, i int) int {
		if i > 0 && s[i-1:i+1] == "AC" {
			return total + 1
		}
		return total
	}

	// Compute the cumulative sum
	cumsum := make([]int, n)
	cumsum[0] = 0
	for i := 1; i < n; i++ {
		cumsum[i] = count(cumsum[i-1], i)
	}

	// Iterate over the queries and print the difference in cumulative sums
	for _, problem := range problems {
		l, r := problem[0], problem[1]
		fmt.Println(cumsum[r-1] - cumsum[l-1])
	}
}

// <END-OF-CODE>
