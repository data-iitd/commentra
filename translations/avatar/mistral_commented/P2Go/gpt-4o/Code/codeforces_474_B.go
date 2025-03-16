package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Initialize an empty slice `L`
	var L []int

	// Read the first input, which is the number of elements to add to the list
	var n int
	fmt.Scan(&n)

	// Use a for loop to iterate through each integer in the input
	var r int = 1
	for i := 0; i < n; i++ {
		var k int
		fmt.Scan(&k)
		// Add `r` elements to the slice `L` with the value `r`
		for j := 0; j < k; j++ {
			L = append(L, r)
		}
		// Increment the value of `r` by 1 to prepare for the next iteration
		r++
	}

	// Read the second input, which represents the indices of the elements to print from the list
	var m int
	fmt.Scan(&m)

	// Use another for loop to iterate through each integer in the input
	for i := 0; i < m; i++ {
		var j int
		fmt.Scan(&j)
		// Print the element at the given index using the index as an offset from the beginning of the list
		fmt.Println(L[j-1])
	}
}

// <END-OF-CODE>
