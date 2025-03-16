package main

import (
	"fmt"
)

func main() {
	// Read two integers n and m from input
	var n, m int
	fmt.Scan(&n, &m)

	// Read a list of n integers from input
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Initialize an empty slice to store the results after processing the input list
	l2 := make([]int, n)

	// Iterate through each element in the input list
	for i := 0; i < n; i++ {
		if l[i]%m == 0 {
			l2[i] = l[i] / m
		} else {
			l2[i] = l[i]/m + 1
		}
	}

	// Find the maximum value in the processed list l2
	mx := l2[0]
	for _, value := range l2 {
		if value > mx {
			mx = value
		}
	}

	// Iterate through the range of n to find the index of the maximum value in l2
	var ind int
	for i := 0; i < n; i++ {
		if l2[i] == mx {
			ind = i // Store the index of the maximum value
			break
		}
	}

	// Print the index of the maximum value (1-based index)
	fmt.Println(ind + 1)
}

// <END-OF-CODE>
