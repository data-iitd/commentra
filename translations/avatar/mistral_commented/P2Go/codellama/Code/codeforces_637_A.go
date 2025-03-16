// Import necessary modules
package main

import (
	"fmt"
	"os"
	"strings"
)

// Set input function to read from standard input
func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

// Import Counter from collections module for counting occurrences
type Counter map[string]int

// Read the number of strings to be processed
func read() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Read the strings and split the last string by space
func readString() []string {
	var s string
	fmt.Scan(&s)
	return strings.Split(s, " ")[:len(strings.Split(s, " "))-1]
}

// Create a Counter object to store the occurrences of each string
func createCounter(s []string) Counter {
	w := make(Counter)
	for _, v := range s {
		w[v]++
	}
	return w
}

// Initialize variables for storing the index of the longest string and its value
func init() (c, a int) {
	c = -1
	a = 0
	return
}

// Iterate through each string in the Counter object
func iterate(w Counter) (c, a int) {
	for i, v := range w {
		if v == max(w) {
			if s.Index(i) > c {
				a = i
				c = s.Index(i)
			}
		}
	}
	return
}

// Print the longest string
func print(a string) {
	fmt.Println(a)
}

// Find the maximum value in the Counter object
func max(w Counter) int {
	var m int
	for _, v := range w {
		if v > m {
			m = v
		}
	}
	return m
}

// Main function
func main() {
	// Read the number of strings to be processed
	n := read()

	// Read the strings and split the last string by space
	s := readString()

	// Create a Counter object to store the occurrences of each string
	w := createCounter(s)

	// Initialize variables for storing the index of the longest string and its value
	c, a := init()

	// Iterate through each string in the Counter object
	c, a = iterate(w)

	// Print the longest string
	print(a)
}

