package main

import (
	"fmt"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)

	L := make([]int, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&L[i])
	}
	L[0] = -1 // Insert -1 at the beginning of the list L

	path := []int{1} // Initialize the path list with the first element 1
	ind := 0         // Initialize index tracker to 0
	count := 0       // Initialize count to 0
	x := 1           // Initialize current position to 1
	t := -1          // Initialize loop start index to -1
	flag := false    // Initialize flag to indicate loop detection
	Hash := make(map[int]int) // Initialize a map to keep track of indices of elements in path

	// Main loop to traverse the path
	for i := 0; i <= N; i++ {
		ne := L[x] // Get the next element in the path

		// Check if the next element is already in the Hash
		if _, exists := Hash[ne]; exists {
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

// <END-OF-CODE>
