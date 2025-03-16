package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from user input
	a := make([]int, n) // Creating an integer slice of size n

	// Initializing the slice with user input
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Sorting the slice in ascending order
	sort.Ints(a)

	// Checking if there is any pair of adjacent elements that satisfy the condition
	for i := 0; i < len(a)-1; i++ {
		// Checking if the next element is less than twice the current element and they are not the same
		if a[i+1] < a[i]*2 && a[i] != a[i+1] {
			fmt.Println("YES") // Printing "YES" if a pair is found
			return // Exiting the function if a pair is found
		}
	}

	// If no pair is found, printing "NO"
	fmt.Println("NO")
}

// <END-OF-CODE>
