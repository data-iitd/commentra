package main

import (
	"container/heap"
	"fmt"
)

func main() {
	// Call the solve function and print the result
	fmt.Println(solve())
}

func solve() int {
	// Create a Scanner object to read input from the user
	sc := new(Scanner)

	// Read the number of elements in the array
	var N int
	fmt.Scan(&N)

	// Initialize an array to hold the input values
	arr := make([]int, N)

	// Populate the array with user input
	for i := 0; i < N; i++ {
		fmt.Scan(&arr[i])
	}

	// Initialize a variable to keep track of the count of elements
	sum := 0

	// Create a priority queue to manage the elements
	q := make(PriorityQueue, 0)

	// Iterate through the array to process each element
	for i := 0; i < len(arr); i++ {
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

// Define a type for the priority queue
type PriorityQueue []int

// Define the methods for the priority queue
func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] < pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

