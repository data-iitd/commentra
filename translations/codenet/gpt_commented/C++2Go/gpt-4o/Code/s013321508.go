package main

import (
	"fmt"
	"sort"
)

func main() {
	// Declare variables for the number of elements (N) and the number of operations (M)
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize a slice to hold the elements
	L := make([]int, N)

	// Read N integers from input and store them in the slice L
	for i := 0; i < N; i++ {
		fmt.Scan(&L[i])
	}

	// Sort the slice L in ascending order
	sort.Ints(L)

	// Perform M operations to modify the slice L
	for i := 0; i < M; i++ {
		// Get the maximum element from the end of the sorted slice
		maxL := L[len(L)-1]

		// If the maximum element is 0, break the loop as no further operations are needed
		if maxL == 0 {
			break
		}

		// Halve the maximum element
		maxL /= 2

		// Find the position to insert the halved value in the sorted slice
		itr := sort.Search(len(L), func(i int) bool {
			return L[i] >= maxL
		})

		// Insert the halved value into the slice at the found position
		L = append(L[:itr], append([]int{maxL}, L[itr:]...)...)

		// Remove the last element (the original maximum) from the slice
		L = L[:len(L)-1]
	}

	// Calculate the sum of all elements in the slice L
	var ans int64
	for _, v := range L {
		ans += int64(v)
	}

	// Output the final sum
	fmt.Println(ans)
}

// <END-OF-CODE>
