
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

	// Iterator to traverse the slice
	var itr int

	// Perform the required operations for M times
	for i := 0; i < M; i++ {
		max_L := L[len(L)-1] // Get the last element of the slice

		// If the last element is 0, break the loop
		if max_L == 0 {
			break
		}

		// Divide the last element by 2
		max_L /= 2

		// Find the position of the element greater than or equal to max_L using sort.SearchInts
		itr = sort.SearchInts(L, max_L)

		// Insert max_L before the found position and remove the last element
		L = append(L[:itr], append([]int{max_L}, L[itr:]...)...)
		L = L[:len(L)-1]
	}

	// Calculate the answer and print it
	ans := 0
	for _, v := range L {
		ans += int64(v)
	}
	fmt.Println(ans)
}

