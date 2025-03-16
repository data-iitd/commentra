package main

import (
	"fmt"
)

func main() {
	var n, q int
	fmt.Scan(&n, &q)

	var s string
	fmt.Scan(&s)

	problems := make([][2]int, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&problems[i][0], &problems[i][1])
	}

	// Create a cumulative sum slice to keep track of 'AC' occurrences
	cumsum := make([]int, n)
	for i := 1; i < n; i++ {
		cumsum[i] = cumsum[i-1]
		if s[i-1:i+1] == "AC" {
			cumsum[i]++
		}
	}

	// Process each query to find the number of 'AC' occurrences in the specified range
	for _, problem := range problems {
		l, r := problem[0], problem[1]
		// Output the difference in cumulative sums to get the count in the range [l, r]
		fmt.Println(cumsum[r-1] - cumsum[l-1])
	}
}

// <END-OF-CODE>
