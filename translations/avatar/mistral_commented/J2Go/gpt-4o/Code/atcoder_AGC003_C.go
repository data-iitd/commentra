package main

import (
	"container/heap"
	"fmt"
)

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

func main() {
	var N int
	fmt.Scan(&N) // Reading the number of elements in the array

	// Creating a map to store the index of each unique element
	indexMap := make(map[int]int)

	// Creating a priority queue (min-heap) to store the elements
	nums := &IntHeap{}
	heap.Init(nums)

	// Reading the elements one by one and adding them to the priority queue and map
	for i := 0; i < N; i++ {
		var tmp int
		fmt.Scan(&tmp) // Reading an element
		heap.Push(nums, tmp) // Adding the element to the priority queue
		indexMap[tmp] = i // Adding the index of the element to the map
	}

	bin := 0 // Initializing a binary index variable
	diff := 0 // Initializing a variable to store the difference in parity between elements

	// Processing the elements in the priority queue
	for nums.Len() > 0 {
		num := heap.Pop(nums).(int) // Polling an element from the priority queue
		idx := indexMap[num] // Getting the index of the element from the map

		// Checking if the binary index and the index of the current element have opposite parity
		if (bin % 2) != (idx % 2) {
			diff++ // Incrementing the difference if the condition is true
		}

		bin++ // Incrementing the binary index
		bin %= 2 // Setting the binary index to 0 or 1 based on the current parity
	}

	// Calculating and printing the answer
	ans := diff / 2
	fmt.Println(ans)
}

// <END-OF-CODE>
