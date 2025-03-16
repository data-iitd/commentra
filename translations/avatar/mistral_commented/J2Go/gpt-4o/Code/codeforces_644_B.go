package main

import (
	"container/list"
	"fmt"
)

func main() {
	var n, b int
	fmt.Scan(&n, &b) // Reading the first two integer values

	ans := make([]int64, n) // Creating a slice of int64 type with length n
	q := list.New()         // Creating a new doubly linked list

	for i := 0; i < n; i++ {
		var t, d int
		fmt.Scan(&t, &d) // Reading the current test case's values

		// Removing elements from the front of the list if they are less than or equal to t
		for q.Len() > 0 && q.Front().Value.(int64) <= int64(t) {
			q.Remove(q.Front()) // Removing the smallest element from the queue
		}

		// Checking if the size of the queue is less than or equal to b
		if q.Len() <= b {
			// If true, calculate the answer for the current test case
			if q.Len() == 0 {
				ans[i] = int64(t) + int64(d)
			} else {
				ans[i] = q.Back().Value.(int64) + int64(d)
			}
			// Adding the answer to the queue
			q.PushBack(ans[i])
		} else {
			// If false, set the answer to -1
			ans[i] = -1
		}
	}

	// Printing the answers for all the test cases
	for i := 0; i < n; i++ {
		fmt.Print(ans[i], " ") // Printing the answer followed by a space
	}
}
