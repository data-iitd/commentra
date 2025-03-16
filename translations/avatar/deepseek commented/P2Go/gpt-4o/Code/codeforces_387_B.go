package main

import (
	"fmt"
)

func main() {
	// Read the number of elements in round_complexity and george_complexity
	var n, m int
	fmt.Scan(&n, &m)

	// Read the complexities of the rounds
	roundComplexity := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&roundComplexity[i])
	}

	// Read the complexities of George's challenges
	georgeComplexity := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&georgeComplexity[i])
	}

	// Initialize counters for both lists
	i, j := 0, 0

	// Loop through both lists to compare complexities
	for i < n && j < m {
		// Increment i if the current round complexity is less than or equal to George's complexity
		if roundComplexity[i] <= georgeComplexity[j] {
			i++
		}
		// Increment j to move to the next element in george_complexity
		j++
	}

	// Print the number of rounds George can solve
	fmt.Println(n - i)
}

// <END-OF-CODE>
