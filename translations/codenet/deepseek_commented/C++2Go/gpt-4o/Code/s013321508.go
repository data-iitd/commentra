package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M) // Reading two integers, N and M.

	L := make([]int, N) // Initializing a slice L with a size of N.
	for i := 0; i < N; i++ {
		fmt.Scan(&L[i]) // Reading N integers and populating the slice L.
	}

	sort.Ints(L) // Sorting the slice L in ascending order.

	for i := 0; i < M; i++ { // Performing M operations.
		maxL := L[len(L)-1] // Finding the largest element in the slice.
		if maxL == 0 {
			break // If the largest element is 0, break the loop.
		}

		maxL /= 2 // Halving the largest element.
		L = append(L[:len(L)-1], maxL) // Removing the largest element from the slice.
		sort.Ints(L) // Re-sorting the slice after modification.
	}

	ans := 0 // Variable to hold the sum of elements in the slice L.
	for _, value := range L {
		ans += value // Calculating the sum of all elements in the slice L.
	}

	fmt.Println(ans) // Printing the result.
}

// <END-OF-CODE>
