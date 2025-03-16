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

// Define a structure 'pp' to store name and time of each process
type pp struct {
	name string
	t    int
}

// Initialize head and tail pointers and size of the queue
var Q [100005]pp
var head, tail, n int

// Function to add an element to the queue
func enqueue(x pp) {
	Q[tail] = x
	tail = (tail + 1) % 100005
}

// Function to remove an element from the queue
func dequeue() pp {
	x := Q[head]
	head = (head + 1) % 100005
	return x
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var elaps, c, i, q int
	var u pp

	// Read number of processes and number of queries
	n, q = readInt()

	// Allocate memory for each process and read its name and time
	for i = 1; i <= n; i++ {
		Q[i] = readPP()
		enqueue(Q[i])
	}
	head = 1
	tail = n + 1

	// Simulate the queue and serve processes based on their arrival time and time taken
	for head!= tail {
		u = dequeue()
		c = min(q, u.t)
		u.t -= c
		elaps += c
		if u.t > 0 {
			enqueue(u)
		} else {
			fmt.Printf("%s %d\n", u.name, elaps)
		}
	}
}

// Read an integer from input
func readInt() (int, int) {
	var i, j int
	var s string
<<<<<<< HEAD
	fmt.Scanf("%s", &s)
	i, j = 0, len(s)-1
	for i < j && s[i] =='' {
		i++
	}
	for j >= 0 && s[j] =='' {
		j--
	}
	if j < 0 {
		return 0, 0
	}
	return strconv.Atoi(s[i:j+1])
=======
	fmt.Scanf("%d", &i)
	fmt.Scanf("%d", &j)
	return i, j
>>>>>>> 98c87cb78a (data updated)
}

// Read a process from input
func readPP() pp {
	var x pp
	var s string
	fmt.Scanf("%s", &s)
	x.name = s
<<<<<<< HEAD
	x.t, _ = readInt()
=======
	x.t, _ = strconv.Atoi(strings.Split(s, " ")[1])
>>>>>>> 98c87cb78a (data updated)
	return x
}

