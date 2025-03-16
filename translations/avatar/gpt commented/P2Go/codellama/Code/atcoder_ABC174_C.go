// Import necessary packages
package main

import (
	"fmt"
	"math"
	"strconv"
)

// Define input functions for convenience
func ii1() int {
	var i int
	fmt.Scan(&i)
	return i
}

func is1() string {
	var s string
	fmt.Scan(&s)
	return s
}

func iia() []int {
	var a []int
	fmt.Scan(&a)
	return a
}

func isa() []string {
	var a []string
	fmt.Scan(&a)
	return a
}

// Define a constant for modulo operations
const mod = 1000000007

// Read the integer k from input
k := ii1()

// Initialize a variable to hold the current value of t
t := 0

// Loop through numbers from 1 to k
for i := 1; i <= k; i++ {
	// Update t by appending a '7' at the end and taking modulo k
	t = (t % k) * 10 + 7

	// Check if the current value of t is divisible by k
	if t%k == 0 {
		fmt.Println(i) // Print the current index if divisible
		break
	}
}

// If no index was found, print -1
fmt.Println(-1)

