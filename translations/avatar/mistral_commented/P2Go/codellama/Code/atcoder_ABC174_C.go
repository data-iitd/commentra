// Import necessary packages
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

// Define constants
const (
	mod = 1000000007
)

// Read an integer from standard input and return it
func ii1() int {
	var i int
	fmt.Scan(&i)
	return i
}

// Read a string from standard input and return it
func is1() string {
	var s string
	fmt.Scan(&s)
	return s
}

// Read a list of integers from standard input and return it
func iia() []int {
	var a []int
	s := is1()
	for _, v := range strings.Split(s, " ") {
		i, _ := strconv.Atoi(v)
		a = append(a, i)
	}
	return a
}

// Read a list of strings from standard input and return it, split by spaces
func isa() []string {
	var a []string
	s := is1()
	a = strings.Split(s, " ")
	return a
}

// Set the value of k from standard input
var k = ii1()

// Initialize a variable t to 0
var t = 0

// Loop from 1 to k
for i := 1; i <= k; i++ {
	// Calculate the value of t using the current value of i and k
	t = ( (t % k) * 10 + 7 ) % k

	// Check if t is a multiple of k
	if t == 0 {
		// Print the value of i and break out of the loop
		fmt.Println(i)
		break
	}
}

// If the loop completes without finding a multiple of k, print -1
if t != 0 {
	fmt.Println(-1)
}

