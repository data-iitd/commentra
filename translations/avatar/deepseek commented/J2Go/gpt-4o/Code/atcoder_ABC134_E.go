package main

import (
	"container/heap"
	"fmt"
	"sort"
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
	var n int
	fmt.Scan(&n) // Reading the integer n from the input

	frequency := make(map[int]int) // Initializing a map to store the frequency of numbers
	var keys IntHeap                // Slice to maintain the keys for sorting

	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num) // Reading the next integer from the input

		if len(keys) == 0 || keys[len(keys)-1] < num {
			// Incrementing the frequency of the current number
			frequency[num]++
			if frequency[num] == 1 {
				heap.Push(&keys, num) // Add the new key to the heap
			}
		} else {
			// Finding the largest key less than the current number
			sort.Ints(keys) // Sort the keys to find the largest key less than num
			for j := len(keys) - 1; j >= 0; j-- {
				if keys[j] < num {
					// Decrementing the frequency of the found key
					frequency[keys[j]]--
					if frequency[keys[j]] == 0 {
						delete(frequency, keys[j]) // Remove the key if frequency becomes zero
						keys = append(keys[:j], keys[j+1:]...) // Remove from the slice
					}
					break
				}
			}
			// Incrementing the frequency of the current number
			frequency[num]++
			if frequency[num] == 1 {
				heap.Push(&keys, num) // Add the new key to the heap
			}
		}
	}

	// Calculating the sum of all frequencies in the map
	ans := 0
	for _, val := range frequency {
		ans += val
	}

	// Printing the sum of frequencies
	fmt.Println(ans)
}

// <END-OF-CODE>
