
package main

import "fmt"

// main function is the entry point of the program
func main() {
	// Initialize variables
	var n, m int
	// Read input from standard input
	fmt.Scanf("%d %d", &n, &m)
	// Allocate memory for h array
	h := make([]int, n)
	// Read h array elements from standard input
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i])
		// Comment for the loop that reads h array elements
		// from standard input
		// and stores them in the h array
	}
	// Initialize counter map
	counter := make(map[int]struct{})
	// Read m query pairs from standard input
	for i := 0; i < m; i++ {
		fmt.Scanf("%d %d", &a, &b)
		// Check the condition for a and b
		if h[a-1] < h[b-1] {
			// Add a to the counter map if h[a-1] is smaller than h[b-1]
			counter[a] = struct{}{}
		} else if h[a-1] > h[b-1] {
			// Add b to the counter map if h[a-1] is greater than h[b-1]
			counter[b] = struct{}{}
		} else if h[a-1] == h[b-1] {
			// Add both a and b to the counter map if h[a-1] is equal to h[b-1]
			counter[a] = struct{}{}
			counter[b] = struct{}{}
		}
		// Comment for the loop that processes m query pairs
	}
	// Print the result
	fmt.Println(n - len(counter))
	// Comment for the final print statement
}

