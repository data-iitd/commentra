
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the user
	s := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the array
	s.Scan()
	n, _ := strconv.Atoi(s.Text())

	// Initialize an array of size n to hold the integers
	a := make([]int, n)

	// Populate the array with user input
	for i := 0; i < n; i++ {
		s.Scan()
		a[i], _ = strconv.Atoi(s.Text())
	}

	// Create a list to store the result pairs
	r := make([]string, 0)

	// Variable to track the index of the element with the maximum absolute value
	m := 0

	// Find the index of the element with the maximum absolute value
	for i := 1; i < n; i++ {
		if abs(a[m]) < abs(a[i]) {
			m = i
		}
	}

	// Generate pairs of indices based on the sign of the maximum absolute value element
	for i := 0; i < n; i++ {
		if (a[m] >= 0)!= (a[i] >= 0) {
			r = append(r, fmt.Sprintf("%d %d", m+1, i+1))
		}
	}

	// If the maximum absolute value element is non-negative
	if a[m] >= 0 {
		// Add pairs of consecutive indices in ascending order
		for i := 1; i < n; i++ {
			r = append(r, fmt.Sprintf("%d %d", i, i+1))
		}
	} else {
		// If the maximum absolute value element is negative, add pairs in descending order
		for i := n; i > 1; i-- {
			r = append(r, fmt.Sprintf("%d %d", i, i-1))
		}
	}

	// Print the size of the result list
	fmt.Println(len(r))

	// Print each pair in the result list
	for _, pair := range r {
		fmt.Println(pair)
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

