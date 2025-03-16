package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, x int
	fmt.Scan(&n, &x) // Read the values of n and x from input

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read the list `a` from input
	}

	sort.Ints(a) // Sort the list `a` in ascending order

	ans := 0 // Initialize the variable `ans` to store the result

	if a[0] > x {
		fmt.Println(0) // Check if the smallest element in the sorted list `a` is greater than `x`. If so, print 0 and exit.
		return
	}

	for _, i := range a {
		if i > x {
			x = 0
			break
		}
		x -= i
		ans++ // Increment `ans`
	}

	if x != 0 {
		ans-- // If `x` is not 0 after the loop, decrement `ans` by 1.
	}

	fmt.Println(ans) // Print the value of `ans`.
}

// <END-OF-CODE>
