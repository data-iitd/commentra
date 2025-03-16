package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Read two integers n and m from input

	l := make([]int, n) // Initialize a slice of integers with length n
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i]) // Read the list of integers
	}

	l2 := make([]int, n) // Initialize an empty slice to store the results

	// Iterate over each element in the list l
	for i := 0; i < n; i++ {
		if l[i]%m == 0 { // Check if the element is divisible by m
			l2[i] = l[i] / m // Store the quotient in l2
		} else {
			l2[i] = l[i]/m + 1 // Store the quotient plus one in l2
		}
	}

	mx := l2[0] // Initialize mx with the first element of l2
	for _, value := range l2 {
		if value > mx {
			mx = value // Find the maximum value in l2
		}
	}

	// Iterate over l2 to find the index of the maximum value
	var ind int
	for i := 0; i < n; i++ {
		if l2[i] == mx {
			ind = i // Store the index of the maximum value
			break
		}
	}

	fmt.Println(ind + 1) // Print the index of the maximum value plus one
}

// <END-OF-CODE>
