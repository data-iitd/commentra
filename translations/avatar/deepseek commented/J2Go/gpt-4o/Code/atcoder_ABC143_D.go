package main

import (
	"fmt"
	"sort"
)

func main() {
	// Step 1: Read the number of elements N from the standard input
	var N int
	fmt.Scan(&N)

	// Step 2: Read N integers from the standard input and add them to the slice L
	L := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&L[i])
	}

	// Step 3: Sort the slice L in ascending order
	sort.Ints(L)

	// Step 4: Initialize a counter to zero
	count := 0

	// Step 5: Use two nested loops to iterate through the slice L, selecting pairs of elements (a, b) where a < b
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			a := L[i]
			b := L[j]

			// Step 6: For each pair (a, b), call the find method to determine the number of elements in the slice L
			// that are greater than a + b and are located after the index j+1
			res := find(L, j+1, a+b)

			// Step 7: Add the result of the find method to the counter count
			count += res
		}
	}

	// Step 8: After all pairs have been processed, print the value of count
	fmt.Println(count)
}

// Step 9: The find method uses a binary search algorithm to efficiently find the number of elements in the slice L
// that are greater than a + b and are located after the index from
func find(li []int, from int, target int) int {
	low := from
	upp := len(li) - 1

	if upp-low < 0 {
		return 0
	} else if li[from] >= target {
		return 0
	} else if li[upp] < target {
		return upp - low + 1
	}

	for upp-low > 1 {
		mid := (low + upp) / 2
		if li[mid] >= target {
			upp = mid
		} else {
			low = mid
		}
	}

	return low - from + 1
}

// <END-OF-CODE>
