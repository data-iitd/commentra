package main

import (
	"fmt"
	"sort"
)

const maxn = 200000 + 10 // Maximum number of elements

func main() {
	var n int
	for {
		_, err := fmt.Scan(&n) // Read the number of elements
		if err != nil {
			break // Exit the loop if there's an error (EOF)
		}

		maps := make([]int, n+1)
		num := make([]int, n+1)

		// Read the elements into maps slice and copy them to num slice
		for i := 1; i <= n; i++ {
			fmt.Scan(&maps[i])
			num[i] = maps[i]
		}

		// Sort the maps slice to find the median easily
		sort.Ints(maps[1:n+1])

		// Calculate the median index
		m := n / 2

		// Iterate through the num slice and print the appropriate median value
		for i := 1; i <= n; i++ {
			if num[i] <= maps[m] {
				fmt.Println(maps[m+1]) // Print the element after the median if num[i] is less than or equal to the median
			} else {
				fmt.Println(maps[m]) // Print the median if num[i] is greater than the median
			}
		}
	}
}

// <END-OF-CODE>
