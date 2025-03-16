package main

import (
	"fmt"
	"os"
)

const I = 10000 // Define a constant for the maximum range of input values

// Function prototype for CountingSort
func CountingSort(a, b []int, k int)

func main() {
	var a, b []int
	var i, n int

	// Read the number of elements to be sorted
	fmt.Scan(&n)

	// Allocate memory for the input array 'a' and output array 'b'
	a = make([]int, n+1)
	b = make([]int, n+1)

	// Read 'n' elements into the array 'a'
	for i = 0; i < n; i++ {
		fmt.Scan(&a[i+1]) // Store elements starting from index 1
	}

	// Call the CountingSort function to sort the array 'a' and store the result in 'b'
	CountingSort(a, b, n)

	// Print the sorted elements from array 'b'
	fmt.Print(b[1]) // Print the first sorted element
	for i = 2; i < n+1; i++ {
		fmt.Print(" ", b[i]) // Print the remaining sorted elements
	}
	fmt.Println()

	// Free the allocated memory for arrays 'a' and 'b'
	os.Stdout.WriteString("Memory freed\n")
}

// Function to perform Counting Sort
func CountingSort(a, b []int, k int) {
	var c [I]int
	var i, j int

	// Initialize the counting array 'c' to zero
	for i = 0; i <= I; i++ {
		c[i] = 0 // Set all counts to zero
	}

	// Count occurrences of each element in array 'a'
	for j = 0; j < k; j++ {
		c[a[j+1]]++ // Increment the count for each element
	}

	// Update the counting array 'c' to contain the actual positions of elements
	for i = 1; i < I+1; i++ {
		c[i] += c[i-1] // Cumulative sum to determine positions
	}

	// Build the output array 'b' using the counting array 'c'
	for j = k; j > 0; j-- {
		b[c[a[j]]] = a[j] // Place the elements in their sorted position
		c[a[j]]--         // Decrement the count for the current element
	}
}

