package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text()) // Read the number of tasks
	scanner.Scan()
	b, _ := strconv.Atoi(scanner.Text()) // Read the buffer size
	ans := make([]int64, n)              // Array to store task completion times
	q := []int64{}                       // Queue to manage buffer

	// Process each task
	for i := 0; i < n; i++ {
		scanner.Scan()
		t, _ := strconv.Atoi(scanner.Text()) // Read the task's start time
		scanner.Scan()
		d, _ := strconv.Atoi(scanner.Text()) // Read the task's duration

		// Remove completed tasks from the front of the queue
		for len(q) > 0 && q[0] <= int64(t) {
			q = q[1:]
		}

		// Check if the task can be added to the buffer
		if len(q) <= b {
			if len(q) == 0 {
				ans[i] = int64(t) + int64(d)
			} else {
				ans[i] = q[len(q)-1] + int64(d)
			}
			q = append(q, ans[i])
		} else {
			ans[i] = -1
		}
	}

	// Output the completion times of all tasks
	for i := 0; i < n; i++ {
		fmt.Print(ans[i], " ")
	}
}

