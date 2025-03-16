/*
 * FileName:     the_number_of_inversions_fix.go
 * CreatedDate:  2020-06-05 16:25:10 +0900
 * LastModified: 2020-07-06 22:22:35 +0900
 */

package main

import (
	"fmt"
	"math"
)

// Define a large constant to act as a sentinel value
const unko = 1e12

// Function to merge two halves of an array and count inversions
func sort(a []int64, left, middle, right int) int64 {
	// Create temporary slices for left and right halves
	lArr := make([]int64, middle-left+1)
	rArr := make([]int64, right-middle+1)
	cnt := int64(0) // Initialize inversion count

	// Copy data to temporary slices
	for i := 0; i < middle-left; i++ {
		lArr[i] = a[left+i]
	}
	for i := 0; i < right-middle; i++ {
		rArr[i] = a[middle+i]
	}

	// Add sentinel values to the end of the temporary slices
	lArr[middle-left] = unko
	rArr[right-middle] = unko

	l, r := 0, 0 // Initialize pointers for left and right slices

	// Merge the two halves back into the original array
	for i := 0; i < right-left; i++ {
		if lArr[l] <= rArr[r] {
			a[left+i] = lArr[l] // Take from left slice
			l++
		} else {
			a[left+i] = rArr[r] // Take from right slice
			r++
			cnt += int64(middle - left - l) // Count inversions
		}
	}
	return cnt // Return the count of inversions
}

// Function to recursively divide the array and count inversions
func merge(a []int64, left, right int) int64 {
	if left+1 < right {
		middle := (left + right) / 2 // Find the middle point
		x1 := merge(a, left, middle)  // Count inversions in the left half
		x2 := merge(a, middle, right)  // Count inversions in the right half
		x3 := sort(a, left, middle, right) // Count inversions while merging
		return x1 + x2 + x3 // Return total count of inversions
	}
	return 0 // Base case: no inversions if the segment has one or no elements
}

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements
	a := make([]int64, n) // Allocate memory for the array

	// Read the elements into the array
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Call the merge function and print the number of inversions
	fmt.Println(merge(a, 0, n))
}
