
package main

import (
	"fmt"
)

func main() {
	// Read the number of elements N
	var N int
	fmt.Scan(&N)

	// Read N integers into a slice `a`
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize idx to 1 and ans to 0
	idx := 1
	ans := 0

	// Iterate through the slice `a`
	for i := 0; i < N; i++ {
		// If the current element is equal to `idx`, increment `idx`
		if a[i] == idx {
			idx++
		} else {
			// If not, increment `ans`
			ans++
		}
	}

	// If `idx` is still 1, it means no elements matched, so print `-1`
	if idx == 1 {
		fmt.Println(-1)
	} else {
		// Otherwise, print `ans`
		fmt.Println(ans)
	}
}

