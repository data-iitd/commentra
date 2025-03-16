package main

import (
	"fmt"
)

const LEN = 100005

type P struct {
	name [100]byte
	t    int // time taken by each process
}

var Q [LEN]P // queue to store process information
var head, tail, n int // head and tail indices of the queue, and total number of processes

func enqueue(x P) { // function to add a process to the queue
	Q[tail] = x
	tail = (tail + 1) % LEN
}

func dequeue() P { // function to remove a process from the queue
	x := Q[head]
	head = (head + 1) % LEN
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
	var i int // loop variables
	var u P // variable to store the process dequeued from the queue

	fmt.Scan(&n, &q) // read the number of processes and the number of queries

	for i = 0; i < n; i++ { // initialize the queue with process information
		fmt.Scan(&Q[i].name, &Q[i].t)
		enqueue(Q[i]) // enqueue each process
	}
	head = 0
	tail = n

	for head != tail { // processing loop
		u = dequeue() // dequeue a process
		c = min(q, u.t) // calculate the number of units to be processed in this iteration
		u.t -= c // update the remaining time for the process
		elaps += c // update the elapsed time
		if u.t > 0 { // if the process still has remaining time, enqueue it again
			u.t = u.t
			enqueue(u)
		} else { // if the process has been fully processed, print the result
			fmt.Printf("%s %d\n", u.name, elaps)
		}
	}
}

