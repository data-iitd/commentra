
package main

import "fmt"

// Include the standard input/output library

var heap [100000]int
// Declare a long long array 'heap' of size 100000 and initialize its size to zero

var sz int
// Declare a variable 'sz' for storing the size of the heap

func push(x int) {
	i := sz
	// i is the index of the newly added element in the heap

	for i > 0 {
		// Perform the heapify operation from the bottom to the top
		p := (i - 1) / 2
		// p is the index of the parent node of the current node i

		if heap[p] >= x {
			break
		}
		// If the parent node is greater than or equal to the current node, then break the loop

		heap[i] = heap[p]
		// Swap the parent node with the current node

		i = p
		// Move to the parent node
	}

	heap[i] = x
	// Assign the value x to the current node

	sz++
	// Increment the size of the heap
}

func pop() int {
	ret := heap[0]
	// ret stores the value of the root node

	x := heap[sz-1]
	// x is the last element in the heap after popping the root node

	i := 0
	// i is the index of the current node

	for i*2+1 < sz {
		// Perform the heapify operation from the bottom to the top after popping the root node

		a := i*2 + 1
		// a is the index of the left child node of the current node i

		b := i*2 + 2
		// b is the index of the right child node of the current node i

		if b < sz && heap[b] > heap[a] {
			a = b
		}
		// If the right child node has a greater value than the left child node, then assign the index of the right child node to a

		if heap[a] <= x {
			break
		}
		// If the value of the node to be swapped is less than or equal to the value of the current node, then break the loop

		heap[i] = heap[a]
		// Swap the values of the current node and the node to be swapped

		i = a
		// Move to the node to be swapped
	}

	heap[i] = x
	// Assign the value of the current node to the node that was swapped

	sz--
	// Decrement the size of the heap

	return ret
	// Return the value of the root node before popping it
}

func main() {
	var n, m, i, j int
	// Declare variables n, m, i, and j for reading input and performing calculations

	var a [100000]int
	// Declare a long long array 'a' of size n for storing the input elements

	fmt.Scan(&n, &m)
	// Read the number of elements n and the number of queries m from the standard input

	for i = 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	// Read the elements of the array 'a' from the standard input

	for i = 0; i < n; i++ {
		push(a[i])
	}
	// Add each element of the array 'a' to the heap using the 'push' function

	for i = 0; i < m; i++ {
		tm := pop()
		// Pop an element from the heap

		tm /= 2
		// Divide the popped element by 2

		push(tm)
		// Add the divided element back to the heap using the 'push' function
	}
	// Perform m queries by popping an element from the heap, dividing it by 2, and adding it back to the heap

	var ans int
	// Initialize the variable ans to 0 for storing the sum of the elements in the heap

	for i = 0; i < n; i++ {
		ans += heap[i]
	}
	// Calculate the sum of the elements in the heap using a loop

	fmt.Println(ans)
	// Print the sum of the elements in the heap to the standard output

	// 