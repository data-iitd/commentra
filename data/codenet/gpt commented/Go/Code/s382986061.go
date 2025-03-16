package main

import "fmt"

// Declare global variables for the number of elements (N), number of groups (K), 
// and temporary variables (d for group size, a for element).
var N, K int
var d, a int

func main() {
	// Read the total number of elements (N) and the number of groups (K) from input.
	fmt.Scan(&N, &K)

	// Initialize a map to count occurrences of each element, with keys from 1 to N.
	as := make(map[int]int)
	for i := 1; i <= N; i++ {
		as[i] = 0 // Set initial count of each element to 0.
	}

	// Process each group of elements.
	for i := 0; i < K; i++ {
		// Read the size of the current group (d).
		fmt.Scan(&d)
		// Read each element in the group and increment its count in the map.
		for j := 0; j < d; j++ {
			fmt.Scan(&a)
			as[a]++ // Increment the count for the element a.
		}
	}

	// Initialize a counter for elements that are not present in any group.
	ans := 0
	// Iterate through the counts of each element in the map.
	for _, v := range as {
		// If an element's count is 0, it means it was not present in any group.
		if v == 0 {
			ans++ // Increment the counter for missing elements.
		}
	}

	// Output the total count of elements that were not present in any group.
	fmt.Println(ans)
}
