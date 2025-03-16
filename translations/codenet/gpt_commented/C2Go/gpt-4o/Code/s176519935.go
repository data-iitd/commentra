package main

import (
	"fmt"
)

// Declare a max heap and a variable to track the size of the heap
var heap []int64
var sz int

// Function to insert an element into the max heap
func push(x int64) {
	i := sz
	sz++ // Increment size
	heap = append(heap, 0) // Expand the heap slice
	// Percolate up to maintain heap property
	for i > 0 {
		p := (i - 1) / 2 // Calculate parent index
		if heap[p] >= x {
			break // If parent is greater or equal, stop
		}
		heap[i] = heap[p] // Move parent down
		i = p // Move index to parent
	}
	heap[i] = x // Place the new element in its correct position
}

// Function to remove and return the maximum element from the max heap
func pop() int64 {
	ret := heap[0] // Store the maximum element
	x := heap[sz-1] // Remove the last element
	sz-- // Decrease size
	heap[0] = x // Move the last element to the root
	i := 0 // Start from the root of the heap
	// Percolate down to maintain heap property
	for i*2+1 < sz {
		a := i*2 + 1 // Left child index
		b := i*2 + 2 // Right child index
		// Choose the larger child
		if b < sz && heap[b] > heap[a] {
			a = b
		}
		if heap[a] <= x {
			break // If the larger child is less than or equal to x, stop
		}
		heap[i] = heap[a] // Move the larger child up
		i = a // Move index to the child
	}
	heap[i] = x // Place the removed element in its correct position
	return ret // Return the maximum element
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	heap = make([]int64, 0, n) // Initialize the heap slice
	var a []int64 = make([]int64, n) // Array to store input values
	// Read the elements into the array
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	// Insert all elements into the max heap
	for i := 0; i < n; i++ {
		push(a[i])
	}
	// Perform m operations of removing the max element and pushing back half of it
	for i := 0; i < m; i++ {
		tm := pop() // Get the maximum element
		tm /= 2 // Halve the maximum element
		push(tm) // Push the halved value back into the heap
	}
	ans := int64(0) // Variable to accumulate the sum of remaining elements
	// Calculate the sum of all elements remaining in the heap
	for i := 0; i < sz; i++ {
		ans += heap[i]
	}
	// Print the final result
	fmt.Println(ans)
}

// <END-OF-CODE>
