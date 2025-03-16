package main

import (
	"fmt"
)

// Function to perform linear search on an array
func linearSearch(S []int, key int) int {
	for i := 0; i < len(S); i++ {
		if S[i] == key {
			return 0 // Key found
		}
	}
	return 1 // Key not found
}

func main() {
	var n, q int
	count := 0

	// Read the size of the array S from the user
	fmt.Print("Enter the size of the array S: ")
	fmt.Scan(&n)

	S := make([]int, n) // Declare and initialize array S

	// Read the elements of array S from the user
	fmt.Printf("Enter %d integers for array S:\n", n)
	for i := 0; i < n; i++ {
		fmt.Printf("Enter integer S[%d]: ", i)
		fmt.Scan(&S[i])
	}

	// Read the number of queries from the user
	fmt.Print("Enter the number of queries: ")
	fmt.Scan(&q)

	T := make([]int, q) // Declare and initialize array T

	// Read the elements of array T from the user
	fmt.Printf("Enter %d integers for array T:\n", q)
	for j := 0; j < q; j++ {
		fmt.Printf("Enter integer T[%d]: ", j)
		fmt.Scan(&T[j])
	}

	// Call linearSearch function for each element of array T and increment count if key is not found
	for j := 0; j < q; j++ {
		key := T[j] // Assign the current element of array T to key variable
		if linearSearch(S, key) == 1 { // Call linearSearch function and check if count is 1 (key not found)
			count++ // Increment count if key is not found
		}
	}

	// Print the final count to the user
	fmt.Printf("Number of integers in array S that are not present in array T: %d\n", count)
}

// <END-OF-CODE>
