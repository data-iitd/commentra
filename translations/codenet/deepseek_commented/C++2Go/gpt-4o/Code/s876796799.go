package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N int
	fmt.Fscan(reader, &N) // Read the number of elements

	a := make([]int64, N) // Slice to store the elements
	ind_a := make([]int, N) // Slice to store the indices of elements in array a

	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &a[i]) // Read the elements into slice a
	}

	for i := 0; i < N; i++ {
		ind_a[a[i]-1] = i // Initialize ind_a with the indices of elements in array a
	}

	used_inds := []int{} // Slice to keep track of used indices
	ans := int64(0) // Variable to store the final answer

	for i := 0; i < N; i++ {
		var left_border, right_border int64
		cur_ind := ind_a[i] // Current index of the element being processed

		// Find the left border
		left_it := sort.Search(len(used_inds), func(j int) bool {
			return used_inds[j] >= cur_ind
		})

		if left_it == 0 {
			left_border = -1 // If left_it is the first element, set left_border to -1
		} else {
			left_border = int64(used_inds[left_it-1]) // Set left_border to the value pointed by left_it
		}

		// Find the right border
		right_it := sort.Search(len(used_inds), func(j int) bool {
			return used_inds[j] > cur_ind
		})

		if right_it == len(used_inds) {
			right_border = int64(N) // If right_it is the end, set right_border to N
		} else {
			right_border = int64(used_inds[right_it]) // Set right_border to the value pointed by right_it
		}

		// Calculate the contribution of the current element to the answer
		ans += (cur_ind - int(left_border)) * (right_border - cur_ind) * int64(i+1)

		// Insert the current index into the slice used_inds
		used_inds = append(used_inds, cur_ind)
		sort.Ints(used_inds) // Maintain the sorted order of used_inds
	}

	fmt.Println(ans) // Output the final answer
}

// <END-OF-CODE>
