package main

import (
	"container/list"
	"fmt"
)

func main() {
	var n, b int
	fmt.Scan(&n, &b)

	// Initialize a slice to store the results
	ans := make([]int64, n)

	// Create a linked list to act as a queue for managing time values
	q := list.New()

	// Process each element based on the input
	for i := 0; i < n; i++ {
		var t, d int
		fmt.Scan(&t, &d)

		// Remove elements from the front of the queue that are no longer valid
		for q.Len() > 0 && q.Front().Value.(int64) <= int64(t) {
			q.Remove(q.Front())
		}

		// Check if the size of the queue is within the allowed limit
		if q.Len() <= b {
			// If the queue is empty, set the answer to the current time (t) plus duration (d)
			// Otherwise, set it to the last element in the queue plus duration (d)
			if q.Len() == 0 {
				ans[i] = int64(t) + int64(d)
			} else {
				ans[i] = q.Back().Value.(int64) + int64(d)
			}

			// Add the computed answer to the queue
			q.PushBack(ans[i])
		} else {
			// If the queue size exceeds the limit, set the answer to -1
			ans[i] = -1
		}
	}

	// Print the results stored in the ans slice
	for _, value := range ans {
		fmt.Print(value, " ")
	}
}

// <END-OF-CODE>
