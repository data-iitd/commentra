package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure to represent a task with a name and time
type task struct {
	name string // Name of the task
	time int    // Time required to complete the task
}

func main() {
	var n, q int // n: number of tasks, q: time quantum
	var elaps int // Variable to keep track of elapsed time
	var reader = bufio.NewReader(os.Stdin)

	// Read the number of tasks and the time quantum from input
	fmt.Fscan(reader, &n, &q)

	// Create a queue to manage tasks in a FIFO manner
	var Q []task

	// Read each task's name and time, and add it to the queue
	for i := 0; i < n; i++ {
		var tmp task
		var input, _ = reader.ReadString('\n')
		input = strings.TrimSpace(input)
		var parts = strings.Split(input, " ")
		tmp.name = parts[0]
		tmp.time, _ = strconv.Atoi(parts[1])
		Q = append(Q, tmp)
	}

	// Process tasks until the queue is empty
	for len(Q) > 0 {
		var p = Q[0] // Get the task at the front of the queue
		Q = Q[1:]   // Remove the task from the queue

		// Check if the task can be completed within the time quantum
		if p.time <= q {
			elaps += p.time // Update elapsed time
			fmt.Println(p.name, elaps) // Output task name and total elapsed time
		} else {
			// If the task cannot be completed, reduce its time and re-add it to the queue
			p.time -= q // Decrease the remaining time of the task
			elaps += q  // Update elapsed time by the time quantum
			Q = append(Q, p) // Re-add the task to the queue for further processing
		}
	}
}

