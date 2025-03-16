package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, M int // Initialize two integers to read input from user

	// Read input from user
	fmt.Scan(&N, &M)

	// Initialize a slice of integers with size N
	L := make([]int, N)

	// Read integers from user and store them in the slice
	for i := 0; i < N; i++ {
		fmt.Scan(&L[i]) // Read an integer and store it in the slice
	}

	// Sort the slice in ascending order
	sort.Ints(L)

	// Perform the required operations for M times
	for i := 0; i < M; i++ {
		maxL := L[len(L)-1] // Get the last element of the slice

		// If the last element is 0, break the loop
		if maxL == 0 {
			break
		}

		// Divide the last element by 2
		maxL /= 2

		// Find the position to insert maxL using sort.Search
		pos := sort.Search(len(L), func(i int) bool {
			return L[i] >= maxL
		})

		// Insert maxL before the found position and remove the last element
		L = append(L[:pos], append([]int{maxL}, L[pos:]...)...)
		L = L[:len(L)-1] // Remove the last element
	}

	// Calculate the answer and print it
	var ans int64 = 0
	for _, v := range L {
		ans += int64(v)
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
