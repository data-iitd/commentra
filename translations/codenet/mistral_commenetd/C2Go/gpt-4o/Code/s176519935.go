package main

import (
	"fmt"
)

var heap []int64
var sz int

func push(x int64) {
	i := sz
	sz++
	heap = append(heap, 0) // Increase the size of the heap

	for i > 0 {
		p := (i - 1) / 2 // Parent index
		if heap[p] >= x {
			break
		}
		heap[i] = heap[p] // Swap parent with current node
		i = p            // Move to parent
	}
	heap[i] = x // Assign value x to the current node
}

func pop() int64 {
	ret := heap[0] // Store the root value
	x := heap[sz-1] // Last element in the heap
	sz--            // Decrease size of the heap

	i := 0
	for i*2+1 < sz {
		a := i*2 + 1 // Left child index
		b := i*2 + 2 // Right child index

		if b < sz && heap[b] > heap[a] {
			a = b // Choose the larger child
		}
		if heap[a] <= x {
			break
		}
		heap[i] = heap[a] // Swap current node with the larger child
		i = a             // Move to the child
	}
	heap[i] = x // Assign the value of the current node to the swapped position

	return ret // Return the root value
}

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Read number of elements n and number of queries m

	a := make([]int64, n) // Declare an array of size n
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read elements into the array
	}

	for i := 0; i < n; i++ {
		push(a[i]) // Add each element to the heap
	}

	for i := 0; i < m; i++ {
		tm := pop() // Pop an element from the heap
		tm /= 2    // Divide the popped element by 2
		push(tm)   // Add the divided element back to the heap
	}

	var ans int64 = 0 // Initialize the sum variable
	for i := 0; i < sz; i++ {
		ans += heap[i] // Calculate the sum of the elements in the heap
	}

	fmt.Println(ans) // Print the sum of the elements in the heap
}

// <END-OF-CODE>
