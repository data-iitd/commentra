package main

import (
	"fmt"
)

func main() {
	// Taking input for number of strings 'n' and number of problems 'q'
	var n, q int
	fmt.Scan(&n, &q)

	// Taking input for the string 's'
	var s string
	fmt.Scan(&s)

	// Creating a slice to hold the problems
	problems := make([][2]int, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&problems[i][0], &problems[i][1])
	}

	// Function to count 'AC' substrings
	count := func(total int, i int) int {
		if i > 0 && s[i-1:i+1] == "AC" {
			return total + 1
		}
		return total
	}

	// Creating a cumulative sum slice
	cumsum := make([]int, n)
	cumsum[0] = 0 // Initial value for cumulative sum
	for i := 1; i < n; i++ {
		cumsum[i] = count(cumsum[i-1], i)
	}

	// Iterating through each problem and printing the result
	for _, problem := range problems {
		l, r := problem[0], problem[1]
		// Print the difference between the cumulative sum at the end and start of the problem
		fmt.Println(cumsum[r-1] - cumsum[l-1])
	}
}

// <END-OF-CODE>
