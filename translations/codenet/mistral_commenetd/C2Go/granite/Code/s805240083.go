
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MAX = 100005
const N = 100

type P struct {
	name string
	t    int // time taken by each process
}

var Q [MAX + 1]P // Circular queue to store the processes
var head, tail int // pointers for head and tail of the queue

func Enqueue(x P) {
	// Function to add a process to the queue
	if MAX == tail { // Check if the queue is full
		tail = 0
	}
	Q[tail] = x // Store the process in the queue
	tail++ // Increment the tail pointer
}

func Dequeue() P {
	// Function to remove a process from the queue
	var temp P // Temporary variable to store the process to be removed
	if head == MAX { // Check if the queue is empty
		head = 0
	}
	temp = Q[head] // Store the process to be removed
	head++ // Increment the head pointer
	return temp // Return the process
}

func main() {
	var i, q, n int // Declare variables for input and loop counter
	var a P // Declare a variable to store the current process
	var T int = 0 // Initialize the total time to 0

	data, _ := os.Open(os.Args[1])
	defer data.Close()
	scanner := bufio.NewScanner(data)
	for scanner.Scan() {
		text := scanner.Text()
		// Read the number of processes and the time limit from the input
		if i == 0 {
			fields := strings.Fields(text)
			n, _ = strconv.Atoi(fields[0])
			q, _ = strconv.Atoi(fields[1])
		} else {
			fields := strings.Fields(text)
			a.name = fields[0]
			a.t, _ = strconv.Atoi(fields[1])
			Enqueue(a) // Enqueue the process
		}
		i++
	}

	for n!= 0 { // While there are still processes in the queue
		a = Dequeue() // Dequeue the current process
		if a.t > q { // If the process takes more time than the limit
			a.t = a.t - q // Subtract the excess time from the process time
			T = T + q // Add the time limit to the total time
			Enqueue(a) // Re-enqueue the process
		} else { // If the process takes less time than the limit
			T = T + a.t // Add the process time to the total time
			fmt.Printf("%s %d\n", a.name, T) // Print the name and total time taken for the process
			n-- // Decrement the number of processes left
		}
	}
}

// Translate the above Go code to C and end with comment "