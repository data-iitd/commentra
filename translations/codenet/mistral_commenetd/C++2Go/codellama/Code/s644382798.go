
package main

import (
	"fmt"
	"strconv"
)

type P struct {
	name string
	t    int
}

var Q [100005]P // queue to store process information
var head, tail, n int // head and tail indices of the queue, and total number of processes

func enqueue(x P) { // function to add a process to the queue
	Q[tail] = x
	tail = (tail + 1) % 100005
}

func dequeue() P { // function to remove a process from the queue
	x := Q[head]
	head = (head + 1) % 100005
	return x
}

func min(a, b int) int { // helper function to find the minimum of two integers
	if a < b {
		return a
	}
	return b
}

func main() { // main function
	var elaps, c int // elapsed time and the number of units processed in each iteration
	var i, q int // loop variables
	var u P // variable to store the process dequeued from the queue

	fmt.Scan(&n, &q) // read the number of processes and the number of queries

	for i = 1; i <= n; i++ { // initialize the queue with process information
		fmt.Scan(&Q[i].name)
		fmt.Scan(&Q[i].t)
		enqueue(Q[i]) // enqueue each process
	}
	head = 1
	tail = n + 1

	for head != tail { // processing loop
		u = dequeue() // dequeue a process
		c = min(q, u.t) // calculate the number of units to be processed in this iteration
		u.t -= c // update the remaining time for the process
		elaps += c // update the elapsed time
		if u.t > 0 { // if the process still has remaining time, enqueue it again
			enqueue(u)
		} else { // if the process has been fully processed, print the result
			fmt.Println(u.name, elaps)
		}
	}
}

