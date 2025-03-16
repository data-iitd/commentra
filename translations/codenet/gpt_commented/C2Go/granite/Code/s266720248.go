
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure to hold the name and time of each process
type P struct {
	name string
	t    int
}

// Declare a queue to hold the processes
var Q [100005]P
var head, tail, n int

// Function to add a process to the queue
func enqueue(x P) {
	Q[tail] = x // Add the process to the queue at the tail
	tail = (tail + 1) % 100005 // Move the tail pointer in a circular manner
}

// Function to remove a process from the queue
func dequeue() P {
	x := Q[head] // Get the process at the head of the queue
	head = (head + 1) % 100005 // Move the head pointer in a circular manner
	return x // Return the removed process
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	data, _ := os.Open(os.Args[1])
	defer data.Close()
	scanner := bufio.NewScanner(data)
	for scanner.Scan() {
		text := scanner.Text()
		if text == "" {
			break
		}
		sp := strings.Split(text, " ")
		n, _ = strconv.Atoi(sp[0])
		q, _ := strconv.Atoi(sp[1])
		for i := 1; i <= n; i++ {
			sp = strings.Split(scanner.Text(), " ")
			Q[i].name = sp[0]
			Q[i].t, _ = strconv.Atoi(sp[1])
		}
		head = 1
		tail = n + 1
		elaps := 0
		c := 0
		u := P{}
		for head!= tail {
			u = dequeue() // Remove the next process from the queue
			c = min(q, u.t) // Determine the time slice to process (minimum of quantum and remaining time)
			u.t -= c // Decrease the remaining time of the process
			elaps += c // Increase the elapsed time by the time slice
			if u.t > 0 {
				enqueue(u) // If the process is not finished, re-add it to the queue
			} else {
				// If the process is finished, print its name and the total elapsed time
				fmt.Printf("%s %d\n", u.name, elaps)
			}
		}
	}
}

// END-OF-CODE