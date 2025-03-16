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

// Function to sort a subarray using merge-sort algorithm
func sort(a []int64, left, middle, right int) int64 {
	lArr := make([]int64, middle-left+1)
	rArr := make([]int64, right-middle)

	cnt := int64(0) // Initialize inversion count to zero

	// Copy elements from the left subarray to a temporary array
	for i := 0; i < middle-left+1; i++ {
		lArr[i] = a[left+i] // Copy elements from the original array to the temporary array
	}

	// Copy elements from the right subarray to a temporary array
	for i := 0; i < right-middle; i++ {
		rArr[i] = a[middle+i] // Copy elements from the original array to the temporary array
	}

	// Set the last element of left subarray and right subarray to a large value
	lArr[middle-left] = math.MaxInt64
	rArr[right-middle] = math.MaxInt64

	l, r := 0, 0 // Initialize pointers for left and right subarrays

	// Merge the sorted subarrays back to the original array and count inversions
	for i := left; i < right; i++ {
		if lArr[l] <= rArr[r] { // If current element from left subarray is smaller than or equal to current element from right subarray
			a[i] = lArr[l] // Copy the smaller element to the original array
			l++           // Move the pointer in the left array
		} else { // If current element from left subarray is greater than the current element from right subarray
			a[i] = rArr[r] // Copy the smaller element to the original array
			r++           // Move the pointer in the right array
			cnt += int64(middle - left - l) // Increment inversion count
		}
	}

	return cnt // Return the number of inversions
}

// Recursive function to merge-sort the given array
func merge(a []int64, left, right int) int64 {
	if left+1 < right { // If the subarray has more than one element
		middle := (left + right) / 2 // Calculate the middle index of the subarray
		x1 := merge(a, left, middle)  // Merge-sort the left subarray
		x2 := merge(a, middle, right)  // Merge-sort the right subarray
		x3 := sort(a, left, middle, right) // Merge the sorted subarrays and count inversions
		return x1 + x2 + x3 // Return the total number of inversions
	}
	return 0 // No inversions are present
}

// Main function to read input and call merge-sort function
func main() {
	var n int // Read the number of elements in the array
	fmt.Scan(&n) // Read the number of elements from the standard input

	a := make([]int64, n) // Allocate memory for the array

	for i := 0; i < n; i++ { // Read the elements of the array from the standard input
		fmt.Scan(&a[i])
	}

	fmt.Println(merge(a, 0, n)) // Call the merge-sort function and print the result
}
