package main

import (
	"fmt"
	"sort"
)

const maxn = 200000 + 10

func main() {
	var n int
	maps := make([]int, maxn)
	num := make([]int, maxn)

	// Continuously read input until EOF
	for {
		_, err := fmt.Scan(&n)
		if err != nil {
			break // Exit on EOF or error
		}

		// Read n integers into the maps array and copy to num array
		for i := 1; i <= n; i++ {
			fmt.Scan(&maps[i])
			num[i] = maps[i]
		}

		// Sort the maps array to find the median
		sort.Ints(maps[1 : n+1])

		// Calculate the index for the median element
		m := n / 2

		// For each element in the original array, determine and print the appropriate value
		for i := 1; i <= n; i++ {
			// If the current number is less than or equal to the median
			if num[i] <= maps[m] {
				// Print the next higher number (the one after the median)
				fmt.Println(maps[m+1])
			} else {
				// Print the median value
				fmt.Println(maps[m])
			}
		}
	}
}

// <END-OF-CODE>
