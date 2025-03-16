
package main

import (
	"fmt"
	"math"
	"sort"
)

// Function to partition the arrays based on the quicksort algorithm
func part(a, b []int, l, r int) int {
	i, j, x, t := l-1, r, b[r], 0

	// Partitioning process
	for {
		// Move the left pointer to the right until an element greater than or equal to the pivot is found
		for i++; b[i] < x; i++ {
		}
		// Move the right pointer to the left until an element less than or equal to the pivot is found
		for j--; i < j && x < b[j]; j-- {
		}

		// If the pointers have crossed, exit the loop
		if i >= j {
			break
		}

		// Swap elements in both arrays to ensure correct partitioning
		a[i], a[j] = a[j], a[i]
		b[i], b[j] = b[j], b[i]
	}

	// Place the pivot element in its correct position
	a[i], a[r] = a[r], a[i]
	b[i], b[r] = b[r], b[i]
	return i // Return the index of the pivot
}

// Function to perform quicksort on two arrays
func quicksort(a, b []int, n int) {
	l, r, v := 0, n-1, 0
	low, high := make([]int, 200000), make([]int, 200000)
	sp := 1

	// Initialize the stack for iterative quicksort
	low[0], high[0] = 0, n-1

	// Iterative quicksort using a stack
	for sp > 0 {
		sp-- // Decrement stack pointer
		l, r = low[sp], high[sp] // Get the current low and high indices

		// If the subarray has one or no elements, skip sorting
		if l >= r {
			continue
		}

		// Partition the array and get the pivot index
		v = part(a, b, l, r)

		// Decide which side to process next based on size
		if v-l < r-v {
			low[sp], high[sp] = v+1, r // Right side
			low[sp+1], high[sp+1] = l, v-1 // Left side
			sp++
		} else {
			low[sp], high[sp] = l, v-1 // Left side
			low[sp+1], high[sp+1] = v+1, r // Right side
			sp++
		}
	}
}

// Main function to execute the program
func main() {
	var n, m, i, t int // Number of intervals and the number of pairs
	a, b := make([]int, 100006), make([]int, 100006)
	cnt := 0 // Counter for non-overlapping intervals

	// Read the number of intervals and pairs
	fmt.Scan(&n, &m)

	// Read the intervals into arrays a and b
	for i = 0; i < m; i++ {
		fmt.Scan(&a[i], &b[i])
	}

	// Sort the intervals based on their end points using quicksort
	quicksort(a, b, m)

	// Initialize the end of the last added interval
	t = 0
	// Count the maximum number of non-overlapping intervals
	for i = 0; i < m; i++ {
		// If the start of the current interval is greater than or equal to the end of the last added interval
		if t <= a[i] {
			t = b[i] // Update the end to the current interval's end
			cnt++    // Increment the count of non-overlapping intervals
		}
	}

	// Output the count of non-overlapping intervals
	fmt.Println(cnt)
}

