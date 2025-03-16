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

	// Initialize a map to store value and its index
	mapIndex := make(map[int]int)

	// Initialize a priority queue (min-heap) to store numbers
	nums := &IntHeap{}
	heap.Init(nums)

	// Read each number, add it to the priority queue, and store its value and index in the map
	for i := 0; i < N; i++ {
		var tmp int
		fmt.Scan(&tmp)
		heap.Push(nums, tmp)
		mapIndex[tmp] = i
	}

	// Initialize variables to keep track of the current index and the count of differences
	bin := 0
	diff := 0

	// Loop until the priority queue is empty
	for nums.Len() > 0 {
		// Retrieve the next number from the priority queue
		num := heap.Pop(nums).(int)
		idx := mapIndex[num]

		// If the current index is not even when bin is even (or vice versa), increment the diff counter
		if (bin%2) != (idx%2) {
			diff++
		}

		// Update bin and take modulo 2 to keep it within 0 or 1
		bin++
		bin %= 2
	}

	// Calculate the answer by dividing diff by 2
	ans := diff / 2

	// Print the result
	fmt.Println(ans)
}

// <END-OF-CODE>
