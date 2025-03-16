package main

import (
	"fmt"
	"sort"
)

func main() {
	// Step 1: Take an integer input `n` which represents the number of elements in the list `l1`.
	var n int
	fmt.Scan(&n)

	// Step 2: Take a space-separated string of integers, convert them into a slice of integers, and store it in `l1`.
	l1 := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l1[i])
	}

	// Step 3: Sort the slice `l1` in ascending order.
	sort.Ints(l1)

	// Step 4: Assign the last element of the sorted slice `l1` to `a`, which is the maximum value in the slice.
	a := l1[n-1]

	// Step 5: Assign the first element of the sorted slice `l1` to `b`, which is the minimum value in the slice.
	b := l1[0]

	// Step 6: Check if `a` is equal to `b`.
	if a == b {
		// Step 7: If `a` is equal to `b`, print the difference `a - b` and the number of ways to choose 2 elements from `n` elements.
		fmt.Println(a-b, n*(n-1)/2)
	} else {
		// Step 8: If `a` is not equal to `b`, calculate the count of occurrences of `a` and `b` in the slice `l1`.
		ac, bc := 0, 0
		for _, value := range l1 {
			if value == a {
				ac++
			}
			if value == b {
				bc++
			}
		}
		// Step 9: Print the difference `a - b` and the product of the counts of `a` and `b`.
		fmt.Println(a-b, ac*bc)
	}
}

// <END-OF-CODE>
