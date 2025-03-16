package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int // Read the number of elements N from the standard input
	fmt.Scan(&N)

	// Read N elements from the standard input and store them in the array 'a'
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize an empty set 'used_inds' to keep track of indices already used
	used_inds := make(map[int]bool)

	ans := 0 // Initialize an answer variable 'ans' to 0

	// Iterate through each index i from 0 to N-1
	for i := 0; i < N; i++ {
		left_border := -1 // Initialize variables 'left_border' and 'right_border' to store the indices of the left and right neighbors of the current index i, respectively
		right_border := N

		cur_ind := i // Get the index of the current element a[i] in the array 'ind_a'

		// Find the index of the left neighbor of the current index i in the set 'used_inds'
		left_it := sort.SearchInts(used_inds, cur_ind)

		// If the left neighbor does not exist, set 'left_border' to -1
		if left_it == 0 {
			left_border = -1
		} else {
			// If the left neighbor exists and its index is greater than the current index i, move the iterator left to find the index of the actual left neighbor
			if left_it == len(used_inds) || used_inds[left_it] > cur_ind {
				left_it--
			}
			left_border = used_inds[left_it]
		}

		// Find the index of the right neighbor of the current index i in the set 'used_inds'
		right_it := sort.SearchInts(used_inds, cur_ind+1)

		// If the right neighbor does not exist, set 'right_border' to N (the total number of elements)
		if right_it == len(used_inds) {
			right_border = N
		} else {
			right_border = used_inds[right_it]
		}

		// Calculate the contribution of the current index i to the answer 'ans'
		ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)

		// Insert the index of the current element a[i] into the set 'used_inds'
		used_inds[cur_ind] = true

		// Uncomment the following lines to print the values of i, left_border, right_border, and ans for debugging purposes
		// fmt.Println(i, left_border, right_border, ans)
		// fmt.Println(ans)
	}

	// Print the final answer 'ans' to the standard output
	fmt.Println(ans)

	// Return 0 to indicate successful execution of the program
	return 0
}

