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
	fmt.Scan(&N)

	// Initialize a map to store the index of each number
	indexMap := make(map[int]int)

	// Initialize a priority queue (min-heap) to store the numbers in sorted order
	nums := &IntHeap{}
	heap.Init(nums)

	// Read N numbers from input
	for i := 0; i < N; i++ {
		var tmp int
		fmt.Scan(&tmp) // Read the next number
		heap.Push(nums, tmp) // Add the number to the priority queue
		indexMap[tmp] = i // Store the index of the number in the map
	}

	// Initialize variables to track the binary state and the difference count
	bin := 0
	diff := 0

	// Process the numbers in sorted order
	for nums.Len() > 0 {
		num := heap.Pop(nums).(int) // Retrieve and remove the smallest number
		idx := indexMap[num] // Get the original index of the number

		// Check if the parity of the current index and the binary state differ
		if (bin%2) != (idx%2) {
			diff++ // Increment the difference count if they differ
		}

		// Update the binary state
		bin++
		bin %= 2 // Toggle between 0 and 1
	}

	// Calculate the final answer as half of the difference count
	ans := diff / 2

	// Output the result
	fmt.Println(ans)
}

// <END-OF-CODE>
