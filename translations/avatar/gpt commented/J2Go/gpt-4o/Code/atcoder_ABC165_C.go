package main

import (
	"fmt"
)

var (
	a   []int
	b   []int
	c   []int
	d   []int
	n   int
	m   int
	q   int
	ans int64 = -100 // Initialize answer to a very low value
)

func main() {
	// Read the values of n, m, and q from input
	fmt.Scan(&n, &m, &q)

	// Initialize slices based on the number of queries (q)
	a = make([]int, q)
	b = make([]int, q)
	c = make([]int, q)
	d = make([]int, q)

	// Read the query parameters into the slices
	for i := 0; i < q; i++ {
		fmt.Scan(&a[i], &b[i], &c[i], &d[i])
		a[i]-- // Store a[i] (0-indexed)
		b[i]-- // Store b[i] (0-indexed)
	}

	// Start the depth-first search (DFS) to find the maximum score
	dfs([]int{})

	// Output the maximum score found
	fmt.Println(ans)
}

func dfs(list []int) {
	// Check if the current list has reached the required size (n)
	if len(list) == n {
		score := int64(0) // Initialize score for the current configuration

		// Calculate the score based on the queries
		for i := 0; i < q; i++ {
			// If the condition is met, add the corresponding value to the score
			if list[b[i]]-list[a[i]] == c[i] {
				score += d[i]
			}
		}

		// Update the maximum score if the current score is higher
		if score > ans {
			ans = score
		}
		return
	}

	// If the list is not empty, continue adding numbers from the last added number to m
	if len(list) > 0 {
		for num := list[len(list)-1]; num <= m; num++ {
			list = append(list, num) // Add the current number to the list
			dfs(list)                // Recur with the updated list
			list = list[:len(list)-1] // Backtrack by removing the last number
		}
	} else {
		// If the list is empty, start adding numbers from 1 to m
		for num := 1; num <= m; num++ {
			list = append(list, num) // Add the current number to the list
			dfs(list)                // Recur with the updated list
			list = list[:len(list)-1] // Backtrack by removing the last number
		}
	}
}

// <END-OF-CODE>
