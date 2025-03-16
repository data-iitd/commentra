package main

import (
	"fmt"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Read the list 't' and prepend a 0 for 1-based indexing
	t := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Scan(&t[i])
	}

	// Read the list 'a' and prepend a 0 for 1-based indexing
	a := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize the answer slice and a count slice to track occurrences
	var ans []int
	cnt := make([]int, n+1)

	// Count the occurrences of each element in list 'a'
	for i := 1; i <= n; i++ {
		cnt[a[i]]++
	}

	// Iterate through each index from 1 to n
	for i := 1; i <= n; i++ {
		// Check if the current element in 't' is 1
		if t[i] == 1 {
			// Initialize a current path slice starting with the current index
			crt := []int{i}
			// Set x to the corresponding value in 'a'
			x := a[i]

			// Continue to follow the chain while the count of x is 1
			for cnt[x] == 1 {
				crt = append(crt, x) // Add x to the current path
				x = a[x]            // Move to the next index in the chain
			}

			// Update the answer if the current path is longer than the previous answer
			if len(crt) > len(ans) {
				ans = make([]int, len(crt))
				copy(ans, crt) // Store a copy of the current path
			}
		}
	}

	// Reverse the answer slice to maintain the original order
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}

	// Print the length of the longest path found
	fmt.Println(len(ans))

	// Print the elements of the longest path as a space-separated string
	for i, v := range ans {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Println()
}

// <END-OF-CODE>
