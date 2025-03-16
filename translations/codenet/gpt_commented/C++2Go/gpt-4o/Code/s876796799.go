package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	// Declare arrays to hold the input values and their indices
	a := make([]int64, N)
	ind_a := make([]int, N)

	// Input the elements into array 'a'
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	// Populate 'ind_a' with the indices of the elements in 'a'
	for i := 0; i < N; i++ {
		ind_a[a[i]-1] = i // Store the index of each element based on its value
	}

	// Slice to keep track of used indices
	used_inds := []int{}
	ans := int64(0) // Variable to accumulate the final answer

	// Iterate through each element's index
	for i := 0; i < N; i++ {
		var left_border, right_border int64
		cur_ind := int64(ind_a[i]) // Current index of the element being processed

		// Find the first used index that is not less than cur_ind
		left_it := sort.Search(len(used_inds), func(j int) bool {
			return int64(used_inds[j]) >= cur_ind
		})

		// Find the first used index that is greater than cur_ind
		right_it := sort.Search(len(used_inds), func(j int) bool {
			return int64(used_inds[j]) > cur_ind
		})

		// Determine the left border
		if left_it == 0 {
			left_border = -1 // No used index to the left
		} else {
			left_border = int64(used_inds[left_it-1]) // Set the left border to the found index
		}

		// Determine the right border
		if right_it == len(used_inds) {
			right_border = int64(N) // No used index to the right
		} else {
			right_border = int64(used_inds[right_it]) // Set the right border to the found index
		}

		// Calculate the contribution of the current index to the answer
		ans += (cur_ind - left_border) * (right_border - cur_ind) * int64(i+1)

		// Insert the current index into the slice of used indices
		used_inds = append(used_inds, int(cur_ind))
		sort.Ints(used_inds) // Keep the slice sorted
	}

	// Output the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
