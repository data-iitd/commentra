
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the values of N and K from input
	N, K := readInput()

	// Read the list L of integers from input
	L := readList()

	// Insert -1 at the beginning of the list L
	L = append([]int{-1}, L...)

	// Initialize the path list with the first element 1
	path := []int{1}

	// Initialize index tracker to 0
	ind := 0

	// Initialize count to 0
	count := 0

	// Initialize current position to 1
	x := 1

	// Initialize loop start index to -1
	t := -1

	// Initialize flag to indicate loop detection
	flag := false

	// Initialize a map to keep track of indices of elements in path
	Hash := make(map[int]int)

	// Main loop to traverse the path
	for i := 0; i < N+1; i++ {
		// Get the next element in the path
		ne := L[x]

		// Check if the next element is already in the Hash
		if Hash[ne] != 0 {
			// Loop detected, set flag and record the start index
			flag = true
			t = Hash[ne]
			break
		}

		// Append the next element to the path and update index
		path = append(path, ne)
		ind++

		// Update the Hash with the current index
		Hash[ne] = ind

		// Move to the next element
		x = ne
	}

	// Check if a loop is detected
	if flag {
		// Create a loop slice from the detected start index to the end
		loop := path[t:]

		// If K is within the bounds of the path length, print the K-th element
		if K < len(path) {
			fmt.Println(path[K])
		} else {
			// Adjust K for the loop length
			K = K - len(path)
			K = K % len(loop)
			// Print the K-th element of the loop
			fmt.Println(loop[K])
		}
	} else {
		// If no loop, print the (K-1)-th element of the path
		fmt.Println(path[K-1])
	}
}

func readInput() (int, int) {
	var N, K int
	fmt.Scan(&N, &K)
	return N, K
}

func readList() []int {
	var L []int
	fmt.Scan(&L)
	return L
}

// 