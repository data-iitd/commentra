package main

import (
	"fmt"
)

var low [200000]int
var high [200000]int
var a [200000]int

// Function to partition the arrays based on the quicksort algorithm
func part(a []int, b []int, l int, r int) int {
	i, j := l-1, r
	x := b[r]

	// Partitioning process
	for {
		// Move the left pointer to the right until an element greater than or equal to the pivot is found
		for b[i+1] < x {
			i++
		}
		// Move the right pointer to the left until an element less than or equal to the pivot is found
		for i < j && x < b[j-1] {
			j--
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
func quicksort(a []int, b []int, n int) {
	var l, r, v int
	sp := 0

	// Initialize the stack for iterative quicksort
	low[sp] = 0
	high[sp] = n - 1
	sp++

	// Iterative quicksort using a stack
	for sp > 0 {
		sp-- // Decrement stack pointer
		l = low[sp] // Get the current low index
		r = high[sp] // Get the current high index

		// If the subarray has one or no elements, skip sorting
		if l >= r {
			continue
		}

		// Partition the array and get the pivot index
		v = part(a, b, l, r)

		// Decide which side to process next based on size
		if v-l < r-v {
			low[sp] = v + 1 // Right side
			high[sp] = r
			sp++
			low[sp] = l // Left side
			high[sp] = v - 1
			sp++
		} else {
			low[sp] = l // Left side
			high[sp] = v - 1
			sp++
			low[sp] = v + 1 // Right side
			high[sp] = r
			sp++
		}
	}
}

// Main function to execute the program
func main() {
	var n, m int // Number of intervals and the number of pairs
	var cnt int // Counter for non-overlapping intervals
	var t int // Variable to track the end of the last added interval

	// Read the number of intervals and pairs
	fmt.Scan(&n, &m)

	// Create slices to hold start and end points of intervals
	a := make([]int, m)
	b := make([]int, m)

	// Read the intervals into slices a and b
	for i := 0; i < m; i++ {
		fmt.Scan(&a[i], &b[i])
	}

	// Sort the intervals based on their end points using quicksort
	quicksort(a, b, m)

	// Initialize the end of the last added interval
	t = 0
	// Count the maximum number of non-overlapping intervals
	for i := 0; i < m; i++ {
		// If the start of the current interval is greater than or equal to the end of the last added interval
		if t <= a[i] {
			t = b[i] // Update the end to the current interval's end
			cnt++ // Increment the count of non-overlapping intervals
		}
	}

	// Output the count of non-overlapping intervals
	fmt.Println(cnt)
}

// <END-OF-CODE>
