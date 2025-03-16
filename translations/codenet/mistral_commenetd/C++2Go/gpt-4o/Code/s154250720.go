package main

import (
	"fmt"
	"sort"
)

const maxn = 200000 + 10 // maximum size of the input array 'n'

func main() {
	var n int
	maps := make([]int, maxn)
	num := make([]int, maxn)

	// Start an infinite loop to read multiple test cases
	for {
		_, err := fmt.Scan(&n)
		if err != nil {
			break // Exit the loop if there's an error (e.g., EOF)
		}

		// Initialize 'maps' and 'num' arrays with input values
		for i := 1; i <= n; i++ {
			fmt.Scan(&maps[i])
			num[i] = maps[i] // copy input values to 'num' array
		}

		// Sort 'maps' array in ascending order
		sort.Ints(maps[1 : n+1])

		// Calculate the middle index 'm' of sorted 'maps' array
		m := n / 2

		// Process each element in 'num' array based on the middle index 'm'
		for i := 1; i <= n; i++ {
			// If current element 'num[i]' is smaller than or equal to middle element 'maps[m]'
			if num[i] <= maps[m] {
				// Print the next element in sorted 'maps' array
				fmt.Println(maps[m+1])
			} else {
				// Otherwise print the current middle element 'maps[m]'
				fmt.Println(maps[m])
			}
		}
	}
}

// <END-OF-CODE>
