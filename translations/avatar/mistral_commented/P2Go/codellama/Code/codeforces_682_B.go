// Import necessary packages
package main

import (
	"fmt"
	"sort"
)

// Function to read a list of integers from standard input
func I() []int {
	var n int
	fmt.Scanf("%d", &n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &l[i])
	}
	return l
}

// Function to read an integer from standard input
func IS() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Function to read an integer from standard input and convert it to an integer
func IN() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Function to read a float from standard input
func IF() float64 {
	var n float64
	fmt.Scanf("%f", &n)
	return n
}

// Read the number of test cases 'n'
n := IN()

// Read the list 'l' of length 'n' containing 'n' integers
l := I()

// Initialize variable 'f' to 1
f := 1

// Sort the list 'l' in ascending order
sort.Ints(l)

// Initialize variable 'c' to 0
c := 0

// Iterate through the list 'l'
for i := 0; i < len(l); i++ {
	// If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
	if l[i] > c {
		c++
	}
}

// Print the final result, which is the number of unique elements in the list 'l' plus 1
fmt.Println(c + 1)

