package main

import (
	"fmt"
)

func main() {
	// Create a scanner to read input from the console
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize a slice to store the input values
	arr := make([]int, n)

	// Initialize a frequency array to count occurrences of each number from 1 to 10
	gen := make([]int, 11) // gen[0] will remain unused

	// Read n integers from input and populate the arr and gen slices
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i]) // Store the input value in arr
		gen[arr[i]]++     // Increment the count of the corresponding number in gen
	}

	// Initialize a variable to hold the final answer
	var ans int64 = 0

	// Calculate the number of valid pairs (i, k) where i != k
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			if i != k {
				// Add the product of the counts of i and k to the answer
				ans += int64(gen[i]) * int64(gen[k])
			}
		}
	}

	// Since each pair (i, k) is counted twice, divide the result by 2
	fmt.Println(ans / 2)
}

// <END-OF-CODE>
