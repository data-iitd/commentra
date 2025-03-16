package main

import (
	"fmt"
)

func main() {
	// Function to read input as a slice of integers
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize a slice to store the elements
	lst := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lst[i])
	}

	// Initialize a map to store the frequency of each element
	l := make(map[int]int)

	// Iterate through each element in the slice 'lst'
	for i := 0; i < n; i++ {
		l[lst[i]]++
	}

	// Initialize result variable 'res' to 0
	res := 0

	// Iterate through each element in the slice 'lst'
	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			// Calculate the number of elements that have a smaller frequency than the current element
			res += n - i - l[lst[i]]
			// Decrease the frequency of the current element in the map 'l' by 1
			l[lst[i]]--
		} else {
			// Calculate the number of elements that have not been processed yet
			res += n - i - 1
		}
	}

	// Print the final result
	fmt.Println(res)
}

// <END-OF-CODE>
