package main

import (
	"fmt"
	"sort"
)

func main() {
	// Initialize scanner for user input
	var N int
	fmt.Scan(&N)

	// Calculate the size of the array S based on N
	size := 1 << N
	// Initialize the array S with user input
	S := make([]int, size)
	// Initialize a boolean array spawned to keep track of which slimes have been spawned
	spawned := make([]bool, size)
	// Set the last element of spawned to true
	spawned[size-1] = true

	// Read the initial positions of slimes from user input and store them in array S
	for i := 0; i < size; i++ {
		fmt.Scan(&S[i])
	}
	// Sort the array S in ascending order
	sort.Ints(S)

	// Initialize a slice named active to store the indices of the currently active slimes
	active := []int{size - 1}

	// Iterate through each generation of slimes
	for i := 0; i < N; i++ {
		// Sort the slice active in descending order
		sort.Sort(sort.Reverse(sort.IntSlice(active)))

		// Initialize a slice named activated to store the indices of the slimes that will be activated in the next generation
		activated := []int{}
		// Initialize a variable named next to keep track of the index of the current slime in array S
		next := size - 1

		// Iterate through each slime in the current generation
		for _, slime := range active {
			// While the current index next is greater than or equal to 0 and the slime size is greater than or equal to the size of the current slime or the current index has already been spawned
			for next >= 0 && (S[next] >= slime || spawned[next]) {
				next--
			}
			// If the current index next is less than 0, print "No" and exit the program
			if next < 0 {
				fmt.Println("No")
				return
			}
			// Set the current index as spawned and add its index to the activated slice
			spawned[next] = true
			activated = append(activated, S[next])
		}
		// Add all the indices of the activated slimes to the active slice
		active = append(active, activated...)
	}

	// Print "Yes" to indicate that the program has successfully determined the positions of all N slimes
	fmt.Println("Yes")
}

// <END-OF-CODE>
