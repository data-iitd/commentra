package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	var n, i, j, q, sum int
	var x, y []int

	// Read the number of elements in array x
	fmt.Scanf("%d", &n)

	// Read n elements into array x
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &x[i])
	}

	// Read the number of queries
	fmt.Scanf("%d", &q)

	// Read q elements into array y
	for i = 0; i < q; i++ {
		fmt.Scanf("%d", &y[i])
	}

	// Initialize sum to count how many elements in y are found in x
	for i = 0; i < q; i++ {
		// Check each element in y against all elements in x
		for j = 0; j < n; j++ {
			// If a match is found, increment sum and break the inner loop
			if y[i] == x[j] {
				sum = sum + 1
				break
			}
		}
	}

	// Output the total count of matches found
	fmt.Printf("%d\n", sum)
}

