package main

import (
	"container/heap"
	"fmt"
	"os"
)

// An IntHeap is a type that implements heap.Interface and holds int values.
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

// Push and Pop methods for the heap interface
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

func solve() int {
	var N int
	fmt.Scan(&N) // Reading the number of elements in the array

	arr := make([]int, N) // Creating an integer slice of size N

	// Using for loop to read and store elements in the slice
	for i := 0; i < N; i++ {
		fmt.Scan(&arr[i]) // Reading an integer and storing it in the slice at the current index
	}

	sum := 0 // Initializing sum variable to 0
	h := &IntHeap{} // Creating an empty IntHeap
	heap.Init(h) // Initializing the heap

	// Using for loop to iterate through the slice
	for i := 0; i < len(arr); i++ {
		heap.Push(h, arr[i]) // Adding the current element to the heap

		// Checking if the current element is smaller than or equal to the top element of the heap
		if arr[i] <= (*h)[0] {
			sum++ // Incrementing sum if the condition is true
		}
	}

	return sum // Returning the sum as the solution
}

func main() {
	fmt.Println(solve()) // Calling solve function to get the solution and print it
}

// <END-OF-CODE>
