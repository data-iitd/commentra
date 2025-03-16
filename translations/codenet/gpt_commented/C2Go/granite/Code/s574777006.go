
package main

import "fmt"

func main() {
	
	// Declare variables
	var n, i, j, q, x, y, sum int
	
	// Read the number of elements in array x
	fmt.Scan(&n)
	
	// Read n elements into array x
	for i = 0; i < n; i++ {
		fmt.Scan(&x)
	}
	
	// Read the number of queries
	fmt.Scan(&q)
	
	// Read q elements into array y
	for i = 0; i < q; i++ {
		fmt.Scan(&y)
	}
	
	// Initialize sum to count how many elements in y are found in x
	for i = 0; i < q; i++ {
		// Check each element in y against all elements in x
		for j = 0; j < n; j++ {
			// If a match is found, increment sum and break the inner loop
			if y == x[j] {
				sum = sum + 1
				break
			}
		}
	}
	
	// Output the total count of matches found
	fmt.Println(sum)
	
	// 