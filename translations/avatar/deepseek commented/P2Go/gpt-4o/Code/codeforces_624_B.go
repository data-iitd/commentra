package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	pre := int(^uint(0) >> 1) // Initialize pre to infinity (max int)
	ans := 0                  // Initialize ans to 0

	sort.Sort(sort.Reverse(sort.IntSlice(a))) // Sort the list in descending order

	for j := 0; j < n; j++ {
		// Calculate the maximum value that can be added to ans
		if pre-1 < a[j] {
			ans += a[j]
		} else {
			ans += pre - 1
		}
		// Update pre to be the maximum of 0 and the minimum of pre - 1 and the current element
		if pre-1 < a[j] {
			pre = pre - 1
		} else {
			pre = a[j]
		}
		if pre < 0 {
			pre = 0
		}
	}

	// Printing the result
	fmt.Println(ans)
}

// <END-OF-CODE>
