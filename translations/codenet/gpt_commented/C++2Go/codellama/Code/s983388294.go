
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Read the number of elements
	n, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println(err)
		return
	}

	// Initialize a slice to store the input elements
	a := make([]int, n)

	// Read n integers into the slice
	for i := 0; i < n; i++ {
		a[i], err = strconv.Atoi(os.Args[i+2])
		if err != nil {
			fmt.Println(err)
			return
		}
	}

	// Initialize a counter for the current expected number
	curr := 0

	// Iterate through the slice to find the longest prefix of consecutive integers starting from 1
	for i := 0; i < n; i++ {
		if a[i] == curr+1 {
			curr++
		}
	}

	// Check if any consecutive integers were found
	if curr > 0 {
		// Print the number of elements not in the consecutive sequence
		fmt.Println(n - curr)
	} else {
		// If no consecutive integers were found, print -1
		fmt.Println(-1)
	}
}

