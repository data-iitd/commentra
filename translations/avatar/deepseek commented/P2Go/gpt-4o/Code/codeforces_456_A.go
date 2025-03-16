package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input representing the number of elements in the list `m`
	m := make([][]int, n)

	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x, &y) // Read two integers for each sublist
		m[i] = []int{x, y}
	}

	// Sort the list `m` in descending order based on the second element of each sublist
	sort.Slice(m, func(i, j int) bool {
		return m[i][1] > m[j][1]
	})

	a := m[0] // Assign the first element of the sorted list `m` to the variable `a`

	// Iterate over the rest of the elements in `m` starting from the second element
	for _, i := range m[1:] {
		if i[1] > a[1] { // Check if the second element of the current element `i` is greater than the second element of the variable `a`
			fmt.Println("Happy Alex") // If true, print "Happy Alex" and break out of the loop
			return
		}
		a = i // If false, assign the current element `i` to the variable `a`
	}

	// If the loop completes without breaking
	fmt.Println("Poor Alex") // Print "Poor Alex"
}

// <END-OF-CODE>
