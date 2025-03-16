package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	N, _ := strconv.Atoi(os.Args[1])

	// Initialize a vector to store the elements
	a := make([]int, N)
	// Read the elements into the vector
	for i := 0; i < N; i++ {
		a[i], _ = strconv.Atoi(os.Args[i+2])
	}

	// Initialize index and answer counter
	idx := 1
	ans := 0

	// Iterate through the vector to count mismatches
	for i := 0; i < N; i++ {
		// If the current element matches the expected index
		if a[i] == idx {
			// Move to the next expected index
			idx++
		} else {
			// Count the mismatch
			ans++
		}
	}

	// If no elements matched the expected index
	if idx == 1 {
		fmt.Println("-1") // Output -1 to indicate no matches
	} else {
		// Output the count of mismatches
		fmt.Println(ans)
	}
}

