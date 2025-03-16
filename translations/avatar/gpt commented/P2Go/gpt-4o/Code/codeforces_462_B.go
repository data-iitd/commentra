package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read two integers n and k from input
	var n, k int
	fmt.Scan(&n, &k)

	// Read the string s from input
	var s string
	fmt.Scan(&s)

	// Initialize a slice to count occurrences of each letter (A-Z)
	count := make([]int, 26)

	// Count the occurrences of each character in the string
	for _, c := range s {
		count[c-'A']++
	}

	// Sort the count slice in descending order to prioritize higher counts
	sort.Slice(count, func(i, j int) bool {
		return count[i] > count[j]
	})

	// Initialize the result variable to accumulate the final score
	res := 0

	// Iterate through the sorted count slice
	for i := 0; i < 26; i++ {
		// If the current count is greater than or equal to k
		if count[i] >= k {
			// Add k squared to the result and print it
			res += k * k
			fmt.Println(res)
			return // Exit the program since we have found the result
		}

		// Decrease k by the current count
		k -= count[i]

		// Add the square of the current count to the result
		res += count[i] * count[i]
	}

	// Print the final result after processing all counts
	fmt.Println(res)
}

// <END-OF-CODE>
