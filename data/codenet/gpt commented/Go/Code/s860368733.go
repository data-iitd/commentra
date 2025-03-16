package main

import "fmt"

func main() {
	// Declare variables for the number of elements (n) and the number of comparisons (m)
	var n, m int
	
	// Read the values of n and m from standard input
	fmt.Scanf("%d %d", &n, &m)
	
	// Create a slice to hold the heights of n elements
	h := make([]int, n)
	
	// Read the heights of the n elements from standard input
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i])
	}
	
	// Declare variables for the two elements to compare (a and b)
	var a, b int
	
	// Create a map to keep track of unique elements that are involved in comparisons
	counter := make(map[int]struct{})
	
	// Loop through m comparisons
	for i := 0; i < m; i++ {
		// Read the indices of the two elements to compare
		fmt.Scanf("%d %d", &a, &b)
		
		// Compare the heights of the two elements
		if h[a-1] < h[b-1] {
			// If height of a is less than height of b, add a to the counter
			counter[a] = struct{}{}
		} else if h[a-1] > h[b-1] {
			// If height of a is greater than height of b, add b to the counter
			counter[b] = struct{}{}
		} else if h[a-1] == h[b-1] {
			// If heights are equal, add both a and b to the counter
			counter[a] = struct{}{}
			counter[b] = struct{}{}
		}
	}
	
	// Print the number of elements that were not involved in any comparisons
	fmt.Println(n - len(counter))
}
