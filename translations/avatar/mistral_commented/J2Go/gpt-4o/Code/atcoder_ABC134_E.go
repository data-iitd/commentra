package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type Item struct {
	value    int // The value of the item
	priority int // The priority of the item
	index    int // The index of the item in the heap
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority < pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of test cases

	frequency := make(map[int]int) // Creating a map to store the frequency of each number

	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num) // Reading the number

		if _, exists := frequency[num]; !exists { // If the number is not present in the map
			frequency[num] = 1 // Initialize frequency to 1
		} else { // If the number is already present
			// Find the largest key less than num
			var lowerKey int
			for k := range frequency {
				if k < num && (lowerKey == 0 || k > lowerKey) {
					lowerKey = k
				}
			}

			if lowerKey != 0 { // If there is a lower key
				val := frequency[lowerKey] // Get the frequency of the lower key
				if val == 1 { // If the frequency is 1
					delete(frequency, lowerKey) // Remove the lower key from the map
				} else { // If the frequency is greater than 1
					frequency[lowerKey]-- // Decrement the frequency of the lower key
				}
			}

			frequency[num]++ // Increment the frequency of the current number
		}
	}

	ans := 0 // Initializing the answer variable to 0

	for _, val := range frequency { // Iterating through each value in the map
		ans += val // Adding the frequency to the answer
	}

	fmt.Println(ans) // Printing the answer
}

// <END-OF-CODE>
