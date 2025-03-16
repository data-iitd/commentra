package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Declare variables for the number of elements (N) and the number of operations (M)
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize a slice to hold the elements, with a size of 100000
	L := make([]int, 100000)
	var l int

	// Read N integers from input and store them in the slice L
	for i := 0; i < N; i++ {
		fmt.Scan(&l)
		L[i] = l
	}

	// Sort the slice L in ascending order
	sort.Ints(L)

	// Declare an iterator for the slice
	var itr int

	// Perform M operations to modify the slice L
	for i := 0; i < M; i++ {
		// Get the maximum element from the end of the sorted slice
		max_L := L[len(L)-1]

		// If the maximum element is 0, break the loop as no further operations are needed
		if max_L == 0 {
			break
		}

		// Halve the maximum element
		max_L /= 2

		// Find the position to insert the halved value in the sorted slice
		itr = sort.SearchInts(L, max_L)

		// Insert the halved value into the slice at the found position
		L = append(L[:itr], append([]int{max_L}, L[itr:]...)...)

		// Remove the last element (the original maximum) from the slice
		L = L[:len(L)-1]
	}

	// Calculate the sum of all elements in the slice L
	ans := 0
	for _, v := range L {
		ans += v
	}

	// Output the final sum
	fmt.Println(ans)
}

