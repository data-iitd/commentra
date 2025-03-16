package main

import (
	"fmt"
)

var heap []int64
var sz int

// Function to insert a new element into the heap
func push(x int64) {
	i := sz
	sz++ // Increment the size of the heap
	heap = append(heap, 0) // Expand the slice to accommodate the new element
	// Bubble up the new element to its correct position
	for i > 0 {
		p := (i - 1) / 2 // Calculate the parent index
		if heap[p] >= x {
			break // If the parent is greater or equal, break the loop
		}
		heap[i] = heap[p] // Move the parent down
		i = p            // Move to the parent index
	}
	heap[i] = x // Insert the new element
}

// Function to remove and return the maximum element from the heap
func pop() int64 {
	ret := heap[0] // Store the root (maximum) element
	x := heap[sz-1] // Get the last element
	sz--           // Decrement the size of the heap
	heap[0] = x    // Move the last element to the root
	i := 0         // Start from the root
	// Bubble down the new root to its correct position
	for i*2+1 < sz {
		a := i*2 + 1
		b := i*2 + 2 // Calculate the children indices
		if b < sz && heap[b] > heap[a] {
			a = b // Choose the larger child
		}
		if heap[a] <= x {
			break // If the children are less than or equal to the element, break the loop
		}
		heap[i] = heap[a] // Move the child up
		i = a             // Move to the child index
	}
	heap[i] = x // Insert the element
	return ret  // Return the removed element
}

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Read the number of elements and the number of operations
	heap = make([]int64, 0, n) // Initialize the heap slice
	for i := 0; i < n; i++ {
		var val int64
		fmt.Scan(&val) // Read the elements into the array
		push(val)      // Push each element into the heap
	}
	for i := 0; i < m; i++ {
		tm := pop() // Pop the maximum element
		tm /= 2     // Halve the element
		push(tm)    // Push the halved element back into the heap
	}
	var ans int64 = 0
	for i := 0; i < sz; i++ {
		ans += heap[i] // Calculate the sum of the heap elements
	}
	fmt.Println(ans) // Print the result
}

// <END-OF-CODE>
