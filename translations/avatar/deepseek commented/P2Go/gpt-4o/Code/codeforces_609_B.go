package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	lst := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lst[i])
	}

	// Initialize a map to store the frequency of elements
	l := make(map[int]int)

	// Populate the map with the frequency of each element in the list
	for i := 0; i < n; i++ {
		l[lst[i]]++
	}

	// Initialize the result variable to store the final result
	res := 0

	// Iterate over the list to calculate the result
	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			// Calculate the number of pairs that can be formed with the current element
			res += n - i - l[lst[i]]
			// Decrement the frequency of the current element in the map
			l[lst[i]]--
		} else {
			// If the frequency is not greater than 1, calculate the number of pairs
			res += n - i - 1
		}
	}

	// Print the final result
	fmt.Println(res)
}

// <END-OF-CODE>
