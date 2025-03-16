<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define the maximum number of processes
const MAX = 100005

// Define the maximum length of the process name
const N = 100

// Define a structure for processes
type P struct {
	name string
	t    int
}

// Declare a queue of processes
var Q [MAX]P
var head, tail int

// Function to add a process to the queue
func Enqueue(x P) {
	if MAX == tail {
		tail = 0
	}
	Q[tail] = x
	tail++
}

// Function to remove and return the process at the front of the queue
func Dequeue() P {
	if MAX == head {
		head = 0
	}
	x := Q[head]
	head++
	return x
}

func main() {
	var i, q, n, T int
	var a P
	fmt.Sscanf(os.Args[1], "%d %d", &n, &q)
	for i = 0; i < n; i++ {
		fmt.Sscanf(os.Args[i+2], "%s%d", &a.name, &a.t)
		Enqueue(a)
	}
	for n!= 0 {
		a = Dequeue()
		if a.t > q {
			a.t = a.t - q
			T += q
			Enqueue(a)
		} else {
			T = T + a.t
			fmt.Printf("%s %d\n", a.name, T)
			n--
		}
	}
}

