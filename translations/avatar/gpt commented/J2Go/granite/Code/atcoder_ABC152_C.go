
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Call the solve method and print the result
	fmt.Println(solve())
}

func solve() int {
	// Create a scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the array
	scanner.Scan()
	N := len(scanner.Bytes())

	// Initialize an array to hold the input values
	arr := make([]int, N)

	// Populate the array with user input
	for i := 0; i < N; i++ {
		scanner.Scan()
		arr[i] = mustParseInt(scanner.Bytes())
	}

	// Initialize a variable to keep track of the count of elements
	sum := 0

	// Create a priority queue to manage the elements
	q := make(IntHeap, 0)

	// Iterate through the array to process each element
	for i := 0; i < N; i++ {
		// Add the current element to the priority queue
		heap.Push(&q, arr[i])

		// Check if the current element is less than or equal to the smallest element in the queue
		if arr[i] <= q[0] {
			// Increment the count if the condition is met
			sum++
		}
	}

	// Return the final count of elements that met the condition
	return sum
}

// IntHeap is a min-heap of integers
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func mustParseInt(b []byte) int {
	n, err := strconv.Atoi(string(b))
	if err!= nil {
		panic(err)
	}
	return n
}

