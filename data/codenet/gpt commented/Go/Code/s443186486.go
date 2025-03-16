package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Initialize a slice to hold the input integers
	a := make([]int, n)
	// Read n integers from input
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Create a prefix sum array to store cumulative sums
	s := make([]int, n+1)
	for i := 0; i < n; i++ {
		s[i+1] = s[i] + a[i] // Calculate cumulative sum
	}

	// Sort the prefix sum array
	sort.Sort(sort.IntSlice(s))

	// Initialize variables to count pairs of equal sums
	ans := 0
	count := 0
	// Iterate through the sorted prefix sums to find duplicates
	for i := 0; i < n; i++ {
		if s[i] == s[i+1] {
			count++ // Increment count if current and next sums are equal
		} else if count > 0 {
			// If we found duplicates, calculate combinations and reset count
			ans += combi(count+1, 2)
			count = 0 // Reset count for the next unique sum
		}
	}
	// Handle the case where the last sums were duplicates
	if count > 0 {
		ans += combi(count+1, 2)
	}

	// Output the total number of pairs of equal sums
	fmt.Println(ans)
}

// Function to calculate combinations C(n, r)
func combi(n, r int) int {
	c := 1
	// Calculate the combination using the formula C(n, r) = n! / (r! * (n - r)!)
	for i := 1; i <= r; i++ {
		c = c * (n - i + 1) / i
	}
	return c // Return the calculated combination
}
