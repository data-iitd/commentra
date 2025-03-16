package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements (n) and the initial value (x) from input
	var n, x int
	fmt.Scan(&n, &x)

	// Read the list of integers
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Sort the list of integers
	sort.Ints(a)

	// Initialize the answer counter
	ans := 0

	// Check if the smallest element in the sorted list is greater than x
	if a[0] > x {
		// If true, print 0 and exit since no elements can be subtracted from x
		fmt.Println(0)
		return
	}

	// Iterate through the sorted list of integers
	for _, i := range a {
		// If the current element is greater than x, set x to 0 and break the loop
		if i > x {
			x = 0
			break
		}
		// Subtract the current element from x
		x -= i
		// Increment the answer counter
		ans++
	}

	// If there is any remaining value in x, decrement the answer counter
	if x != 0 {
		ans--
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
