package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements
	var N int
	fmt.Scan(&N)

	// Input the elements into array 'a'
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	// Populate 'ind_a' with the indices of the elements in 'a'
	ind_a := make([]int, N)
	for i := 0; i < N; i++ {
		ind_a[a[i]-1] = i // Store the index of each element based on its value
	}

	// Set to keep track of used indices
	used_inds := make([]int, 0)
	ans := 0 // Variable to accumulate the final answer

	// Iterate through each element's index
	for i := 0; i < N; i++ {
		left_border := -1 // Variable to store the left border index
		right_border := N // Variable to store the right border index
		cur_ind := ind_a[i] // Current index of the element being processed

		// Find the first used index that is not less than cur_ind
		left_it := sort.SearchInts(used_inds, cur_ind)
		// Find the first used index that is greater than cur_ind
		right_it := sort.SearchInts(used_inds, cur_ind+1)

		// Determine the left border
		if left_it == 0 {
			left_border = -1 // No used index to the left
		} else {
			if left_it == len(used_inds) || used_inds[left_it] > cur_ind {
				left_it-- // Move to the previous index
			}
			left_border = used_inds[left_it] // Set the left border to the found index
		}

		// Determine the right border
		if right_it == len(used_inds) {
			right_border = N // No used index to the right
		} else {
			right_border = used_inds[right_it] // Set the right border to the found index
		}

		// Calculate the contribution of the current index to the answer
		ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)

		// Uncomment the lines below for debugging purposes
		// fmt.Println(i, left_border, right_border)
		// fmt.Println(ans)

		// Insert the current index into the set of used indices
		used_inds = append(used_inds, cur_ind)
	}

	// Output the final answer
	fmt.Println(ans)
}

