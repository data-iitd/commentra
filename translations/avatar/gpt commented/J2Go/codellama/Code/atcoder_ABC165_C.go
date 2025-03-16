package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare arrays to hold input values and variables for dimensions and result
	var a []int
	var b []int
	var c []int
	var d []int
	var n int
	var m int
	var q int
	var ans int64 = -100

	// Read the values of n, m, and q from input
	fmt.Scan(&n, &m, &q)

	// Initialize arrays based on the number of queries (q)
	a = make([]int, q)
	b = make([]int, q)
	c = make([]int, q)
	d = make([]int, q)

	// Read the query parameters into the arrays
	for i := 0; i < q; i++ {
		fmt.Scan(&a[i], &b[i], &c[i], &d[i])
		a[i]--
		b[i]--
	}

	// Start the depth-first search (DFS) to find the maximum score
	dfs([]int{}, 0)

	// Output the maximum score found
	fmt.Println(ans)
}

func dfs(list []int, i int) {
	// Check if the current list has reached the required size (n)
	if len(list) == n {
		score := int64(0) // Initialize score for the current configuration

		// Calculate the score based on the queries
		for j := 0; j < q; j++ {
			// If the condition is met, add the corresponding value to the score
			if list[b[j]]-list[a[j]] == c[j] {
				score += int64(d[j])
			}
		}

		// Update the maximum score if the current score is higher
		if score > ans {
			ans = score
		}
		return
	}

	// If the list is not empty, continue adding numbers from the last added number to m
	if len(list) != 0 {
		for num := list[len(list)-1] + 1; num <= m; num++ {
			list = append(list, num) // Add the current number to the list
			dfs(list, i+1)            // Recur with the updated list
			list = list[:len(list)-1] // Backtrack by removing the last number
		}
	} else {
		// If the list is empty, start adding numbers from 1 to m
		for num := 1; num <= m; num++ {
			list = append(list, num) // Add the current number to the list
			dfs(list, i+1)            // Recur with the updated list
			list = list[:len(list)-1] // Backtrack by removing the last number
		}
	}
}

