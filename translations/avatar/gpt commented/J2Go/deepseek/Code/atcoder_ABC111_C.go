package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a scanner object to read input from the user
	var n int
	fmt.Scan(&n)
	
	// Initialize an array to store the input values
	v := make([]int, 100010)
	
	// Read n integers from input and store them in the array v
	for i := 0; i < n; i++ {
		fmt.Scan(&v[i])
	}
	
	// Initialize arrays to count occurrences of values at different positions
	vo := make([]int, 100010) // Odd indexed counts
	ve := make([]int, 100010) // Even indexed counts
	vt := make([]int, 100010) // Total counts
	
	// Fill the count arrays with zeros
	for i := 0; i < 100010; i++ {
		vo[i] = 0
		ve[i] = 0
		vt[i] = 0
	}
	
	// Count occurrences of each number in odd and even indexed positions
	for i := 0; i < n; i++ {
		vt[v[i]]++ // Increment total count for the value
		if i % 2 == 0 {
			ve[v[i]]++ // Increment even indexed count
		} else {
			vo[v[i]]++ // Increment odd indexed count
		}
	}
	
	// Sort the count arrays in descending order
	sort.Slice(vo, func(i, j int) bool {
		return vo[i] > vo[j]
	})
	sort.Slice(ve, func(i, j int) bool {
		return ve[i] > ve[j]
	})
	sort.Slice(vt, func(i, j int) bool {
		return vt[i] > vt[j]
	})
	
	// Initialize the answer variable
	ans := 0
	
	// Determine the answer based on the counts of the most frequent elements
	if vo[0] + ve[0] == vt[0] {
		// If the most frequent odd and even counts sum to the total count
		ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0])
	} else {
		// Otherwise, calculate the answer based on the most frequent counts
		ans = n - vo[0] - ve[0]
	}
	
	// Output the final answer
	fmt.Println(ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
