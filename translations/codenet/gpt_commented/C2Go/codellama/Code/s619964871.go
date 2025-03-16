/*
 * FileName:     the_number_of_inversions_fix
 * CreatedDate:  2020-06-05 16:25:10 +0900
 * LastModified: 2020-07-06 22:22:35 +0900
 */

package main

import (
	"fmt"
	"math"
)

const unko = 1e12  // Define a large constant to act as a sentinel value

// Function to merge two halves of an array and count inversions
func sort(a []int, left, middle, right int) int {
	// Create temporary arrays for left and right halves
	l_arr := make([]int, middle-left+1)
	r_arr := make([]int, right-middle+1)
	cnt := 0  // Initialize inversion count

	// Copy data to temporary arrays
	for i := 0; i < middle-left; i++ {
		l_arr[i] = a[i+left]
	}
	for i := 0; i < right-middle; i++ {
		r_arr[i] = a[i+middle]
	}

	// Add sentinel values to the end of the temporary arrays
	l_arr[middle-left] = int(unko)
	r_arr[right-middle] = int(unko)

	l := 0  // Initialize pointers for left and right arrays
	r := 0

	// Merge the two halves back into the original array
	for i := 0; i < right-left; i++ {
		if l_arr[l] <= r_arr[r] {
			a[left+i] = l_arr[l]
			l++
		} else {
			a[left+i] = r_arr[r]
			r++
			cnt += middle - left - l
		}
	}
	return cnt  // Return the count of inversions
}

// Function to recursively divide the array and count inversions
func merge(a []int, left, right int) int {
	if left+1 < right {
		middle := (left + right) / 2  // Find the middle point
		x1 := merge(a, left, middle)  // Count inversions in the left half
		x2 := merge(a, middle, right)  // Count inversions in the right half
		x3 := sort(a, left, middle, right)  // Count inversions while merging
		return x1 + x2 + x3  // Return total count of inversions
	} else {
		return 0  // Base case: no inversions if the segment has one or no elements
	}
}

func main() {
	var n int
	fmt.Scan(&n)  // Read the number of elements
	a := make([]int, n)  // Allocate memory for the array

	// Read the elements into the array
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Call the merge function and print the number of inversions
	fmt.Println(merge(a, 0, n))
}

