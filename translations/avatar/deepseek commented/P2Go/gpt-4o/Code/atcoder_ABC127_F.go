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
	var q int
	fmt.Scan(&q) // Read the number of queries
	ans := []int{0, 0} // Initialize the answer list with two zeros
	p1 := &IntHeap{} // Initialize the first priority queue
	p2 := &IntHeap{} // Initialize the second priority queue
	heap.Init(p1) // Heapify the first priority queue
	heap.Init(p2) // Heapify the second priority queue
	sumB := 0 // Initialize the sum of differences
	sumP1 := 0 // Initialize the sum of the first priority queue
	sumP2 := 0 // Initialize the sum of the second priority queue

	// Loop through each query
	for i := 0; i < q; i++ {
		var queryType, value, diff int
		fmt.Scan(&queryType, &value, &diff) // Read the query

		if queryType == 2 { // Check if the query type is 2
			if p1.Len() == p2.Len() { // If the lengths of the two heaps are equal
				fmt.Println(-(*p2)[0], sumP1-len(*p1)*-(*p2)[0]+len(*p2)*-(*p2)[0]-sumP2+sumB) // Print the median and the sum of differences
			} else { // If the lengths of the two heaps are not equal
				fmt.Println((*p1)[0], sumP1-len(*p1)*(*p1)[0]+len(*p2)*(*p1)[0]-sumP2+sumB) // Print the median and the sum of differences
			}
		} else { // If the query type is not 2
			sumB += diff // Add the given value to the sum of differences
			if p1.Len() == 0 { // If the first priority queue is empty
				heap.Push(p1, value) // Push the value to the first priority queue
				sumP1 += value // Update the sum of the first priority queue
			} else if (*p1)[0] <= value { // If the smallest element in the first priority queue is less than or equal to the given value
				heap.Push(p1, value) // Push the value to the first priority queue
				sumP1 += value // Update the sum of the first priority queue
			} else { // If the given value is less than the smallest element in the first priority queue
				heap.Push(p2, -value) // Push the negative value to the second priority queue
				sumP2 += value // Update the sum of the second priority queue
			}
			if p1.Len() < p2.Len() { // If the first priority queue has fewer elements than the second priority queue
				k := heap.Pop(p2).(int) // Pop the smallest element from the second priority queue
				heap.Push(p1, -k) // Push the negative value to the first priority queue
				sumP2 += k // Update the sum of the second priority queue
				sumP1 -= k // Update the sum of the first priority queue
			}
			if p1.Len()-1 > p2.Len() { // If the first priority queue has one more element than the second priority queue
				k := heap.Pop(p1).(int) // Pop the smallest element from the first priority queue
				heap.Push(p2, -k) // Push the negative value to the second priority queue
				sumP1 -= k // Update the sum of the first priority queue
				sumP2 += k // Update the sum of the second priority queue
			}
		}
	}
}

// <END-OF-CODE>
