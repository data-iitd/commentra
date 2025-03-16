package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	// Read the elements of the array
	A := make([]int, N)
	for n := 0; n < N; n++ {
		fmt.Scan(&A[n])
	}

	// Sort the array
	sort.Ints(A)

	// Find the minimum and maximum values in the array
	min := A[0]
	max := A[N-1]

	// Count the occurrences of the minimum and maximum values
	mins, maxs := 0, 0
	for _, value := range A {
		if value == min {
			mins++
		}
		if value == max {
			maxs++
		}
	}

	// Special case: if min == max
	if min == max {
		fmt.Println((max - min), (mins*(mins-1))/2)
	} else {
		// General case: if min != max
		fmt.Println((max - min), (mins * maxs))
	}
}

// Debugging method to print debug statements
func debug(obj ...interface{}) {
	fmt.Println(obj)
}

// <END-OF-CODE>
