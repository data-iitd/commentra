package main

import (
	"fmt"
)

// Declare a max heap and a variable to track the size of the heap
var heap []int
var sz int

// Function to insert an element into the max heap
func push(x int) {
	sz++ // Increment size
	i := sz - 1 // Set current index
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
func pop() int {
	ret := heap[0] // Store the maximum element
	x := heap[sz-1] // Remove the last element and decrease size
	sz-- // Decrease size
	i := 0 // Start from the root of the heap
	// Percolate down to maintain heap property
	for i*2+1 < sz {
		a := i*2 + 1
		b := i*2 + 2
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
	var a []int
	// Read the number of elements and the number of operations
	fmt.Scan(&n, &m)
	// Read the elements into the array
	a = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	// Initialize the heap
	heap = make([]int, 100000)
	sz = 0
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
	var ans int
	// Calculate the sum of all elements remaining in the heap
	for i := 0; i < n; i++ {
		ans += heap[i]
	}
	// Print the final result
	fmt.Println(ans)
}

