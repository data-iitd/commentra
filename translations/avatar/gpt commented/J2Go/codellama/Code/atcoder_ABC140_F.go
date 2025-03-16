package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := new(Scanner)

	// Read the integer N which determines the size of the input array
	var N int
	fmt.Scan(&N)

	// Calculate the size of the array as 2^N
	size := 1 << N

	// Initialize an array S to hold the input values
	S := make([]int, size)

	// Initialize a boolean array to track which elements have been spawned
	spawned := make([]bool, size)

	// Mark the last element as spawned (the largest element)
	spawned[size-1] = true

	// Read N elements into the array S
	for i := 0; i < size; i++ {
		fmt.Scan(&S[i])
	}

	// Sort the array S in ascending order
	sort.Ints(S)

	// Create a list to keep track of active slimes
	active := make([]int, 0)

	// Add the largest element to the active list
	active = append(active, S[size-1])

	// Mark the largest element as spawned
	spawned[size-1] = true

	// Iterate N times to activate new slimes
	for i := 0; i < N; i++ {
		// Sort the active list in descending order
		sort.Sort(sort.Reverse(sort.IntSlice(active)))

		// Create a list to keep track of newly activated slimes
		activated := make([]int, 0)

		// Initialize the next index to the last element of S
		next := size - 1

		// Iterate through each slime in the active list
		for _, slime := range active {
			// Find the next unspawned element that is less than the current slime
			for next >= 0 && (S[next] >= slime || spawned[next]) {
				next--
			}

			// If no valid unspawned element is found, print "No" and exit
			if next < 0 {
				fmt.Println("No")
				return
			}

			// Mark the found element as spawned
			spawned[next] = true

			// Add the newly activated slime to the activated list
			activated = append(activated, S[next])
		}

		// Add all newly activated slimes to the active list
		active = append(active, activated...)
	}

	// If all iterations complete successfully, print "Yes"
	fmt.Println("Yes")
}

// END-OF-CODE
