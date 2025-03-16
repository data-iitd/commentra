
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements (n) and the maximum size of the queue (b)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ := strconv.Atoi(scanner.Text())

	// Initialize an array to store the results
	ans := make([]int64, n)

	// Create a slice to act as a queue for managing time values
	q := make([]int64, 0)

	// Process each element based on the input
	for i := 0; i < n; i++ {
		// Read the time (t) and duration (d) for the current element
		scanner.Scan()
		t, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		d, _ := strconv.Atoi(scanner.Text())

		// Remove elements from the front of the queue that are no longer valid (i.e., their time is less than or equal to t)
		for len(q) > 0 && q[0] <= int64(t) {
			q = q[1:]
		}

		// Check if the size of the queue is within the allowed limit
		if len(q) <= b {
			// If the queue is empty, set the answer to the current time (t) plus duration (d)
			// Otherwise, set it to the last element in the queue plus duration (d)
			ans[i] = int64(t) + int64(d)

			// Add the computed answer to the queue
			q = append(q, ans[i])
		} else {
			// If the queue size exceeds the limit, set the answer to -1
			ans[i] = -1
		}
	}

	// Print the results stored in the ans array
	for i := 0; i < n; i++ {
		fmt.Printf("%d ", ans[i])
	}
	fmt.Println()
}

