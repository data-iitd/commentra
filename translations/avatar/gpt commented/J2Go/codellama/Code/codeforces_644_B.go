package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements (n) and the maximum size of the queue (b)
	n, _ := strconv.Atoi(sc.Text())
	b, _ := strconv.Atoi(sc.Text())

	// Initialize an array to store the results
	ans := make([]int64, n)

	// Create a LinkedList to act as a queue for managing time values
	q := list.New()

	// Process each element based on the input
	for i := 0; i < n; i++ {
		// Read the time (t) and duration (d) for the current element
		t, _ := strconv.Atoi(sc.Text())
		d, _ := strconv.Atoi(sc.Text())

		// Remove elements from the front of the queue that are no longer valid (i.e., their time is less than or equal to t)
		for q.Len() > 0 && q.Front().Value.(int) <= t {
			q.Remove(q.Front())
		}

		// Check if the size of the queue is within the allowed limit
		if q.Len() <= b {
			// If the queue is empty, set the answer to the current time (t) plus duration (d)
			// Otherwise, set it to the last element in the queue plus duration (d)
			ans[i] = int64(t + d)

			// Add the computed answer to the queue
			q.PushBack(ans[i])
		} else {
			// If the queue size exceeds the limit, set the answer to -1
			ans[i] = -1
		}
	}

	// Print the results stored in the ans array
	for i := 0; i < n; i++ {
		fmt.Printf("%d ", ans[i])
	}
}

