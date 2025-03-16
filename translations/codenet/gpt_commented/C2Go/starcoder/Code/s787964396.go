package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// I is the maximum range of input values
const I = 10000

// CountingSort function to sort the array 'a' and store the result in 'b'
func CountingSort(a []int, b []int) {
	var c [I]int
	var i, j int

	// Initialize the counting array 'c' to zero
	for i = 0; i <= I; i++ {
		c[i] = 0
	}

	// Count occurrences of each element in array 'a'
	for j = 0; j < len(a); j++ {
		c[a[j]]++
	}

	// Update the counting array 'c' to contain the actual positions of elements
	for i = 1; i < I + 1; i++ {
		c[i] += c[i-1]
	}

	// Build the output array 'b' using the counting array 'c'
	for j = len(a) - 1; j >= 0; j-- {
		b[c[a[j]]] = a[j]
		c[a[j]]--
	}
}

func main() {
	var a, b []int
	var i, n int

	// Read the number of elements to be sorted
	n, _ = strconv.Atoi(strings.TrimSpace(os.Args[1]))

	// Allocate memory for the input array 'a' and output array 'b'
	a = make([]int, n + 1)
	b = make([]int, n + 1)

	// Read 'n' elements into the array 'a'
	for i = 0; i < n; i++ {
		a[i+1], _ = strconv.Atoi(strings.TrimSpace(os.Args[i+2]))
	}

	// Call the CountingSort function to sort the array 'a' and store the result in 'b'
	CountingSort(a, b)

	// Print the sorted elements from array 'b'
	fmt.Printf("%d", b[1])
	for i = 2; i < n + 1; i++ {
		fmt.Printf(" %d", b[i])
	}
	fmt.Printf("\n")
}

