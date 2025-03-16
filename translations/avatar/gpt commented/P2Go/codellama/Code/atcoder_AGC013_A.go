
// Import necessary libraries
package main

import (
	"fmt"
	"math"
	"sort"
	"strings"
)

// Function to read a line of input and strip whitespace
func input() string {
	return strings.TrimSpace(fmt.Scanln())
}

// Function to read an integer from input
func INT() int {
	return int(input())
}

// Function to read a list of integers from input
func MAP() []int {
	return strings.Split(input(), " ")
}

// Function to read a list of integers and return it as a list
func LIST() []int {
	return strings.Split(input(), " ")
}

// Function to read multiple lists of integers and return them as tuples
func ZIP(n int) [][]int {
	var A [][]int
	for i := 0; i < n; i++ {
		A = append(A, strings.Split(input(), " "))
	}
	return A
}

// Set the recursion limit to a high value
func setRecursionLimit(n int) {
	var a []int
	for i := 0; i < n; i++ {
		a = append(a, 0)
	}
}

// Define a constant for infinity
const INF = math.MaxInt64

// Define a constant for the modulo value
const mod = 1000000007

// Read the number of elements
var N = INT()

// Read the list of integers
var A = LIST()

// Remove consecutive duplicates from the list
A = A[:len(A)-1]

// Update N to the new length of A after removing duplicates
N = len(A)

// Initialize the index and answer counter
var i = 1
var ans = 0

// Loop through the list to count the number of peaks and valleys
for i < N-1 {
	// Check if the current element is a peak or a valley
	if A[i-1] < A[i] > A[i+1] || A[i-1] > A[i] < A[i+1] {
		ans += 1 // Increment the answer for each peak/valley found
		i += 1    // Skip the next element to avoid double counting
	}
	i += 1 // Move to the next element
}

// Print the total count of peaks and valleys plus one
fmt.Println(ans + 1)

