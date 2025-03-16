package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// <START-OF-CODE>

// Task structure
type Task struct {
	arr []int
}

// NewTask creates a new instance of Task
func NewTask(arr []int) *Task {
	return &Task{arr: arr}
}

// Solve the task
func (t *Task) Solve() int {
	// Get the length of the input array
	n := len(t.arr)

	// Create a sorted copy of the input array
	sorted := make([]int, n)
	copy(sorted, t.arr)
	sort.Ints(sorted)

	// Calculate the total number of pairs possible in the array
	total := int64(n) * (n + 1) / 2

	// Initialize pointers for binary search
	l, r := 0, n-1

	// Perform binary search to find the median-like value
	for l < r {
		// Calculate the midpoint of the current search range
		mid := l + (r-l)/2

		// Get the target value from the sorted array
		target := sorted[mid]

		// Initialize counters for the current state
		cur, cnt := 0, int64(0)

		// Create a Binary Indexed Tree (BIT) for counting
		bit := make([]int64, 2*n+2)

		// Initialize the BIT with base values
		for x := n + 1; x < len(bit); x += x & -x {
			bit[x]++
		}

		// Count the number of elements less than or equal to the target
		for i := 0; i < n; i++ {
			cur += t.arr[i] <= target
			for x := cur + n + 1; x < len(bit); x += x & -x {
				bit[x]++
			}
			for x := cur + n; x > 0; x -= x & -x {
				cnt += bit[x]
			}
		}

		// Adjust the search range based on the count of pairs
		if cnt >= total/2+1 {
			r = mid // Move left if count is sufficient
		} else {
			l = mid + 1 // Move right if count is insufficient
		}
	}

	// Return the median-like value found
	return sorted[l]
}

// 