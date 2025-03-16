
package main

import (
	"fmt"
	"sort"
)

func main() {
	// Declare and initialize variables
	var n int // Number of elements in the array
	fmt.Scan(&n) // Read the number of elements from the user
	var a int // Size of the subarray to be summed
	fmt.Scan(&a) // Read the size of the subarray from the user
	var sum int = 0 // Initialize the sum variable to zero
	s := make([]int, n) // Declare an array of size n to store the input elements

	// Read the elements of the array from the user
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i]) // Read the i-th element of the array
	}

	// Sort the array in ascending order
	sort.Ints(s) // Sort the array using the sort function from the sort library

	// Calculate the sum of the last 'a' elements of the sorted array
	for i := n - 1; i > n - a - 1; i-- {
		sum += s[i] // Add the current element to the sum
	}

	// Print the result
	fmt.Println(sum) // Print the sum of the last 'a' elements
}

