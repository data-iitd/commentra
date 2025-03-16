package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure to hold a person's name and their time
type Person struct {
	name string
	t    int
}

// Declare a queue to hold Person structures
var Q [100005]Person
var head, tail int

// Function to add an element to the queue
func Enqueue(x Person) {
	// Wrap around the tail if it reaches the maximum size
	if tail == 100005 {
		tail = 0
	}
	Q[tail] = x
	tail++
}

// Function to remove and return an element from the queue
func Dequeue() Person {
	// Wrap around the head if it reaches the maximum size
	if head == 100005 {
		head = 0
	}
	x := Q[head]
	head++
	return x
}

func main() {
	var i, q, n, T int
	var a Person

	// Read the number of people and the query time
	n, q = readInts()

	// Read each person's name and time, and enqueue them
	for i = 0; i < n; i++ {
		a = readPerson()
		Enqueue(a)
	}

	// Process the queue until all people have been served
	for n!= 0 {
		a = Dequeue()
		// Check if the person's time exceeds the query time
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

// Read an integer from stdin
func readInt() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Read a slice of integers from stdin
func readInts() []int {
	var ns []int
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		ns = append(ns, x)
	}
	return ns
}

// Read a string from stdin
func readString() string {
	var s string
	fmt.Scanf("%s", &s)
	return s
}

// Read a slice of strings from stdin
func readStrings() []string {
	var ss []string
	var s string
	fmt.Scanf("%s", &s)
	ss = strings.Split(s, " ")
	return ss
}

// Read a person from stdin
func readPerson() Person {
	var p Person
	var s string
	fmt.Scanf("%s", &s)
	ss := strings.Split(s, " ")
	p.name = ss[0]
	p.t, _ = strconv.Atoi(ss[1])
	return p
}

// 