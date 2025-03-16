
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const I = 10000 // Define a constant for the maximum range of input values

// Function to perform Counting Sort
func CountingSort(a, b []int, k int) {
	c := make([]int, I+1) // Initialize the counting array 'c' to zero

	// Count occurrences of each element in array 'a'
	for j := 0; j < k; j++ {
		c[a[j]]++ // Increment the count for each element
	}

	// Update the counting array 'c' to contain the actual positions of elements
	for i := 1; i < I+1; i++ {
		c[i] += c[i-1] // Cumulative sum to determine positions
	}

	// Build the output array 'b' using the counting array 'c'
	for j := k - 1; 0 <= j; j-- {
		b[c[a[j]]-1] = a[j] // Place the elements in their sorted position
		c[a[j]]-- // Decrement the count for the current element
	}
}

func main() {
	var n int // Number of elements to be sorted
	var err error // Error variable

	// Read the number of elements to be sorted
	fmt.Scan(&n)

	// Create input and output arrays
	a := make([]int, n+1) // Input array 'a'
	b := make([]int, n+1) // Output array 'b'

	// Read 'n' elements into the array 'a'
	scanner := bufio.NewScanner(os.Stdin)
	for i := 1; i <= n; i++ {
		scanner.Scan()
		a[i], err = strconv.Atoi(scanner.Text()) // Store elements starting from index 1
		if err!= nil {
			fmt.Println("Error:", err)
			return
		}
	}

	// Call the CountingSort function to sort the array 'a' and store the result in 'b'
	CountingSort(a, b, n)

	// Print the sorted elements from array 'b'
	for i := 1; i <= n; i++ {
		fmt.Printf("%d ", b[i]) // Print the sorted elements
	}
	fmt.Println()
}

// Translate the above Go code to C and end with comment "