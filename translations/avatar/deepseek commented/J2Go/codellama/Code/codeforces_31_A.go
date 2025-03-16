
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var f int
	var k int
	var j int
	var i int
	var t int
	var a []int

	// Read the number of elements in the array
	n, _ = strconv.Atoi(os.Args[1])

	// Initialize the array
	a = make([]int, n)

	// Read the elements of the array
	for i = 0; i < n; i++ {
		a[i], _ = strconv.Atoi(os.Args[i+2])
	}

	// Initialize the flag
	f = 0

	// Initialize the indices
	k = 0
	j = 0
	i = 0

	// Outer loop to iterate over each element as a potential a[k]
	for k = 0; k < n; k++ {
		// Current element as t
		t = a[k]

		// Inner loops to find two indices i and j such that a[i] + a[j] = t
		for i = 0; i < n; i++ {
			for j = 0; j < n-1; j++ {
				if i != j && t == (a[i]+a[j]) {
					f = 1 // Set flag to 1 if triplet is found
					break // Break out of the inner loop
				}
			}
			if f == 1 {
				break // Break out of the outer loop if triplet is found
			}
		}
		if f == 1 {
			break // Break out of the main loop if triplet is found
		}
	}

	// Check if a triplet was found and print the result
	if f == 1 {
		fmt.Println(k+1, j+1, i+1)
	} else {
		fmt.Println(-1)
	}
}

