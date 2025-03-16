package main

import (
	"fmt"
)

// Define the heap array and its size
var heap = make([]int, 100000)
var sz = 0

// Function to insert a new element into the heap
func push(x int) {
	i := sz // Increment the size of the heap and store the current index
	sz++
	// Bubble up the new element to its correct position
	for i > 0 {
		p := (i - 1) / 2 // Calculate the parent index
		if heap[p] >= x {
			break
		}
		heap[i] = heap[p] // Move the parent down
		i = p
	}
	heap[i] = x // Insert the new element
}

// Function to remove and return the maximum element from the heap
func pop() int {
	ret := heap[0] // Store the root (maximum) element
	x := heap[sz-1] // Get the last element and decrement the size of the heap
	sz--
	i := 0 // Start from the root
	// Bubble down the new root to its correct position
	for i*2+1 < sz {
		a := i*2 + 1
		b := i*2 + 2
		// Calculate the children indices
		if b < sz && heap[b] > heap[a] {
			a = b
		}
		if heap[a] <= x {
			break
		}
		heap[i] = heap[a] // Move the child up
		i = a
	}
	heap[i] = x // Insert the element
	return ret // Return the removed element
}

func main() {
	var n, m, i, j int
	a := make([]int, 100000)
	fmt.Scan(&n, &m) // Read the number of elements and the number of operations
	for i = 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read the elements into the array
	}
	for i = 0; i < n; i++ {
		push(a[i]) // Push each element into the heap
	}
	for i = 0; i < m; i++ {
		tm := pop() // Pop the maximum element
		tm /= 2 // Halve the element
		push(tm) // Push the halved element back into the heap
	}
	ans := 0
	for i = 0; i < n; i++ {
		ans += heap[i] // Calculate the sum of the heap elements
	}
	fmt.Println(ans) // Print the result
}

