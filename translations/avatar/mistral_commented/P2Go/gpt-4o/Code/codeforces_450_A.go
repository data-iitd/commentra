package main

import (
	"fmt"
)

func main() {
	// Define the number of elements 'n' and the modulus 'm' in the list 'l'
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize a slice 'l' to store the elements
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Initialize a slice 'l2' to store the quotient of each element in 'l' divided by 'm'
	l2 := make([]int, n)

	// Iterate through each element 'i' in the list 'l'
	for i := 0; i < n; i++ {
		// Check if the element 'i' is divisible by 'm'
		if l[i]%m == 0 {
			l2[i] = l[i] / m
		} else {
			l2[i] = l[i]/m + 1
		}
	}

	// Find the maximum quotient in 'l2'
	mx := l2[0]
	for _, value := range l2 {
		if value > mx {
			mx = value
		}
	}

	// Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
	var ind int
	for i := 0; i < n; i++ {
		// Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient 'mx'
		if l2[i] == mx {
			ind = i
			break
		}
	}

	// Print the index 'ind' plus one (since the indices in Go start from 0)
	fmt.Println(ind + 1)
}

// <END-OF-CODE>
