
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const I = 10000 // Define a constant I with the value 10000

// Function to perform Counting Sort
func CountingSort(a, b []int, k int) {
	c := make([]int, I+1) // Initialize array c to store the count of each element

	// Count the occurrences of each element in array a
	for j := 0; j < k; j++ {
		c[a[j]]++
	}

	// Compute the cumulative count to determine the positions of elements in the sorted array
	for i := 1; i < I+1; i++ {
		c[i] += c[i-1]
	}

	// Place elements into array b in sorted order
	for j := k - 1; j >= 0; j-- {
		b[c[a[j]]-1] = a[j]
		c[a[j]]--
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n+1) // Dynamically allocate memory for arrays a and b
	b := make([]int, n+1)

	// Read elements into array a starting from index 1 to n
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i+1])
	}

	// Call CountingSort function to sort the array
	CountingSort(a, b, n)

	// Print the sorted elements starting from index 1 to n
	fmt.Print(b[1])
	for i := 2; i < n+1; i++ {
		fmt.Printf(" %d", b[i])
	}
	fmt.Println()
}

// Translate the above Go code to C and end with comment "