package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the console
	var n int
	fmt.Scan(&n)
	
	// Create an array to store the input integers
	a := make([]int, n)
	
	// Read n integers from the input and store them in the array
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	
	// Initialize a flag to indicate if a valid triplet is found
	f := 0
	
	// Initialize variables for indexing
	var k, j, i int
	
	// Iterate through each element in the array
	for k = 0; k < n; k++ {
		// Store the current element to check against pairs
		t := a[k]
		
		// Check for pairs in the array that sum up to the current element
		for i = 0; i < n; i++ {
			for j = 0; j < n - 1; j++ {
				// Ensure we are not using the same element twice
				if i != j && t == (a[i] + a[j]) {
					// Set the flag to indicate a valid triplet is found
					f = 1
					break
				}
			}
			// Break out of the loop if a valid pair is found
			if f == 1 {
				break
			}
		}
		// Break out of the outer loop if a valid triplet is found
		if f == 1 {
			break
		}
	}
	
	// Output the result: indices of the triplet or -1 if not found
	if f == 1 {
		fmt.Println(k + 1, j + 1, i + 1)
	} else {
		fmt.Println("-1")
	}
}
