
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Include the standard input/output library

<<<<<<< HEAD
var (
	n, m int
	a    []int
)

// Declare variables n, m, and a for reading input and performing calculations

func main() {
	fmt.Scanf("%d %d", &n, &m)
	// Read the number of elements n and the number of queries m from the standard input

	a = make([]int, n)
	// Declare a slice 'a' of size n for storing the input elements

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
		// Read the elements of the array 'a' from the standard input
	}

	for i := 0; i < n; i++ {
		push(a[i])
		// Add each element of the array 'a' to the heap using the 'push' function
	}

	for i := 0; i < m; i++ {
		tm := pop()
		// Pop an element from the heap

		tm /= 2
		// Divide the popped element by 2

		push(tm)
		// Add the divided element back to the heap using the 'push' function
	}
	// Perform m queries by popping an element from the heap, dividing it by 2, and adding it back to the heap

	ans := 0
	// Initialize the variable ans to 0 for storing the sum of the elements in the heap

	for i := 0; i < n; i++ {
		ans += heap[i]
		// Calculate the sum of the elements in the heap using a loop
	}

	fmt.Printf("%d\n", ans)
	// Print the sum of the elements in the heap to the standard output
}

func push(x int) {
	i := sz
=======
var heap []int
// Declare a slice 'heap' for storing the elements in the heap

func push(x int) {
	i := len(heap)
>>>>>>> 98c87cb78a (data updated)
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
}

func pop() int {
	ret := heap[0]
	// ret stores the value of the root node

<<<<<<< HEAD
	x := heap[sz-1]
=======
	x := heap[len(heap)-1]
>>>>>>> 98c87cb78a (data updated)
	// x is the last element in the heap after popping the root node

	i := 0
	// i is the index of the current node

<<<<<<< HEAD
	for i*2+1 < sz {
=======
	for i*2+1 < len(heap) {
>>>>>>> 98c87cb78a (data updated)
		// Perform the heapify operation from the bottom to the top after popping the root node

		a := i*2 + 1
		// a is the index of the left child node of the current node i

		b := i*2 + 2
		// b is the index of the right child node of the current node i

<<<<<<< HEAD
		if b < sz && heap[b] > heap[a] {
=======
		if b < len(heap) && heap[b] > heap[a] {
>>>>>>> 98c87cb78a (data updated)
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

<<<<<<< HEAD
	sz--
	// Decrease the size of the heap by 1

=======
>>>>>>> 98c87cb78a (data updated)
	return ret
	// Return the value of the root node before popping it
}

<<<<<<< HEAD
func init() {
	heap = make([]int, 100000)
	// Declare a long long array 'heap' of size 100000 for storing the elements in the heap

	sz = 0
	// Initialize the size of the heap to zero
=======
func main() {
	reader := bufio.NewReader(os.Stdin)
	// Create a new buffered reader

	n, m, i, j := 0, 0, 0, 0
	// Declare variables n, m, i, and j for reading input and performing calculations

	a := make([]int, 100000)
	// Declare a slice 'a' of size n for storing the input elements

	fmt.Fscan(reader, &n, &m)
	// Read the number of elements n and the number of queries m from the standard input

	for i = 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
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

	ans := 0
	// Initialize the variable ans to 0 for storing the sum of the elements in the heap

	for i = 0; i < n; i++ {
		ans += heap[i]
	}
	// Calculate the sum of the elements in the heap using a loop

	fmt.Fprintln(os.Stdout, ans)
	// Print the sum of the elements in the heap to the standard output
>>>>>>> 98c87cb78a (data updated)
}

