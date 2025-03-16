package main

import (
	"fmt"
)

var (
	// Arrays to store input values
	a, b, c, d []int

	// Variables to store input values
	n, m, q int

	// Variable to store the maximum score
	ans int64 = -100
)

func main() {
	// Read values of n, m, and q
	fmt.Scan(&n, &m, &q)

	// Initialize slices to store the conditions
	a = make([]int, q)
	b = make([]int, q)
	c = make([]int, q)
	d = make([]int, q)

	// Read the conditions into the slices
	for i := 0; i < q; i++ {
		fmt.Scan(&a[i], &b[i], &c[i], &d[i])
		a[i]-- // Adjusting for 0-based index
		b[i]-- // Adjusting for 0-based index
	}

	// Start the DFS with an empty slice
	dfs([]int{})

	// Print the maximum score found
	fmt.Println(ans)
}

// Depth-First Search (DFS) function to generate combinations
func dfs(list []int) {
	// If the list size equals n, calculate the score and update ans
	if len(list) == n {
		score := int64(0)
		for i := 0; i < q; i++ {
			if list[b[i]]-list[a[i]] == c[i] {
				score += d[i]
			}
		}
		if score > ans {
			ans = score
		}
		return
	}

	// If the list is not empty, continue adding numbers from the last number in the list
	if len(list) > 0 {
		for num := list[len(list)-1]; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1] // Remove the last element
		}
	} else {
		// If the list is empty, start with numbers from 1 to m
		for num := 1; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1] // Remove the last element
		}
	}
}

// <END-OF-CODE>
