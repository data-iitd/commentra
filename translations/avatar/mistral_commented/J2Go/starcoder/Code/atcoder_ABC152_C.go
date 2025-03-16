package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// solve method to find the solution
func solve() int {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	// Convert the string to an integer
	N, err := strconv.Atoi(strings.TrimSpace(line))
	if err!= nil {
		panic(err)
	}
	// Create an integer array of size N
	arr := make([]int, N)
	// Read the next N lines of input
	for i := 0; i < N; i++ {
		line, err := reader.ReadString('\n')
		if err!= nil {
			panic(err)
		}
		// Convert the string to an integer
		arr[i], err = strconv.Atoi(strings.TrimSpace(line))
		if err!= nil {
			panic(err)
		}
	}
	// Initialize sum variable to 0
	sum := 0
	// Create an empty PriorityQueue
	q := make(PriorityQueue, 0)
	// Iterate through the array
	for i := 0; i < N; i++ {
		q = append(q, arr[i]) // Adding the current element to the queue
		// Check if the current element is smaller than or equal to the top element of the queue
		if arr[i] <= q[0] {
			sum++ // Incrementing sum if the condition is true
		}
	}
	// Return the sum as the solution
	return sum
}

// PriorityQueue is a min-heap implementation of a queue
type PriorityQueue []int

// Len returns the length of the queue
func (pq PriorityQueue) Len() int {
	return len(pq)
}

// Less returns true if the element at index i is less than the element at index j
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] < pq[j]
}

// Swap swaps the elements at index i and j
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

// Push adds an element to the queue
func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

// Pop removes the element at the top of the queue
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

func main() {
	// Print the solution
	fmt.Println(solve())
}

