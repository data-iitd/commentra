package main

import (
	"container/heap"
	"fmt"
	"os"
	"strconv"
)

// Define a priority queue (min-heap)
type MinHeap []int

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// Define a priority queue (max-heap)
type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	var q int
	fmt.Scan(&q)

	// Initialize empty priority queues for piles p1 and p2
	p1 := &MinHeap{}
	heap.Init(p1)
	p2 := &MaxHeap{}
	heap.Init(p2)

	// Initialize variables for sums of balls and priority queues
	sumB := 0
	sumP1 := 0
	sumP2 := 0

	// Iterate through each query
	for i := 0; i < q; i++ {
		var query []int
		fmt.Scan(&query)

		if query[0] == 2 {
			// Check if both piles have equal number of balls
			if p1.Len() == p2.Len() {
				// Calculate the answer and print it
				fmt.Println(-(*p2)[0], sumP1-p1.Len()*(-(*p2)[0])+p2.Len()*(-(*p2)[0])-sumP2+sumB)
			} else {
				// Calculate the answer and print it
				fmt.Println((*p1)[0], sumP1-p1.Len()*(*p1)[0]+p2.Len()*(*p1)[0]-sumP2+sumB)
			}
		} else {
			// Add the number of balls to the total sum
			sumB += query[2]

			// If pile p1 is empty, add the ball to it
			if p1.Len() == 0 {
				heap.Push(p1, query[1])
				sumP1 += query[1]
			} else if (*p1)[0] <= query[1] {
				// Else, add the ball to pile p1
				heap.Push(p1, query[1])
				sumP1 += query[1]
			} else {
				// Else, add the ball to pile p2 and adjust the sums accordingly
				heap.Push(p2, query[1])
				sumP2 += query[1]
				sumP1 -= query[1]
				sumP2 -= query[1]
			}

			// Adjust the priority queues if necessary
			if p1.Len() < p2.Len() {
				k := heap.Pop(p2).(int)
				heap.Push(p1, k)
				sumP2 += k
				sumP1 -= k
			}

			if p1.Len() > p2.Len()+1 {
				k := heap.Pop(p1).(int)
				heap.Push(p2, k)
				sumP1 -= k
				sumP2 += k
			}
		}
	}
}
