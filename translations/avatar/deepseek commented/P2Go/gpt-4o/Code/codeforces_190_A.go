package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	// Taking input for two integers, `n` and `m`

	if n < 1 {
		// Check if `n` is less than 1
		if m < 1 {
			// Check if `m` is also less than 1
			fmt.Println(n, m)
			return
			// Print `n` and `m` and then quit the program
		}
		fmt.Println("Impossible")
		return
		// Print "Impossible" and then quit the program
	}

	if m > n {
		// Check if `m` is greater than `n`
		min := m
		max := n + m - 1
		fmt.Println(min, max)
		// Calculate `min` as `m` and `max` as `n + m - 1`, then print `min` and `max`
	}

	if m <= n {
		// Check if `m` is less than or equal to `n`
		min := n
		max := n + m - 1
		if m == 0 {
			max = n
		}
		fmt.Println(min, max)
		// Calculate `min` as `n` and `max` as `n + m - 1`. If `m` is 0, set `max` to `n`. Finally, print `min` and `max`
	}
}
// <END-OF-CODE>
