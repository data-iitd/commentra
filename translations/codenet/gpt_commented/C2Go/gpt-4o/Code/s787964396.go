package main

import (
	"fmt"
	"os"
)

const I = 10000 // Define a constant for the maximum range of input values

// CountingSort function to perform Counting Sort
func CountingSort(a []int, b []int, k int) {
	c := make([]int, I+1)

	// Initialize the counting array 'c' to zero
	for i := range c {
		c[i] = 0 // Set all counts to zero
	}

	// Count occurrences of each element in array 'a'
	for j := 0; j < k; j++ {
		c[a[j+1]]++ // Increment the count for each element
	}

	// Update the counting array 'c' to contain the actual positions of elements
	for i := 1; i < I+1; i++ {
		c[i] += c[i-1] // Cumulative sum to determine positions
	}

	// Build the output array 'b' using the counting array 'c'
	for j := k; j > 0; j-- {
		b[c[a[j]]] = a[j] // Place the elements in their sorted position
		c[a[j]]--         // Decrement the count for the current element
	}
}

func main() {
	var n int

	// Read the number of elements to be sorted
	fmt.Scan(&n)

	// Allocate memory for the input array 'a' and output array 'b'
	a := make([]int, n+1)
	b := make([]int, n+1)

	// Read 'n' elements into the array 'a'
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i+1]) // Store elements starting from index 1
	}

	// Call the CountingSort function to sort the array 'a' and store the result in 'b'
	CountingSort(a, b, n)

	// Print the sorted elements from array 'b'
	fmt.Print(b[1]) // Print the first sorted element
	for i := 2; i < n+1; i++ {
		fmt.Printf(" %d", b[i]) // Print the remaining sorted elements
	}
	fmt.Println()

	// No need to free memory in Go, as it has garbage collection
}

// <END-OF-CODE>
