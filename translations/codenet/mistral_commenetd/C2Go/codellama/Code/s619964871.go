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
func sort(a []int, left, middle, right int) int {
	l_arr := make([]int, middle-left+1) // Allocate memory for left and right subarrays
	r_arr := make([]int, right-middle+1)
	cnt := 0 // Initialize inversion count to zero

	// Copy elements from the left subarray to a temporary array
	for i := 0; i < middle-left; i++ {
		l_arr[i] = a[i+left] // Copy elements from the original array to the temporary array
	}

	// Copy elements from the right subarray to a temporary array
	for i := 0; i < right-middle; i++ {
		r_arr[i] = a[i+middle] // Copy elements from the original array to the temporary array
	}

	// Set the last element of left subarray and right subarray to a large value
	l_arr[middle-left] = math.MaxInt64
	r_arr[right-middle] = math.MaxInt64

	l := 0 // Initialize pointers for left and right subarrays
	r := 0

	// Merge the sorted subarrays back to the original array and count inversions
	for i := 0; i < right-left; i++ {
		if l_arr[l] <= r_arr[r] { // If current element from left subarray is smaller than or equal to current element from right subarray
			a[left+i] = l_arr[l] // Copy the smaller element to the original array
			l++
		} else { // If current element from left subarray is greater than the current element from right subarray
			a[left+i] = r_arr[r] // Copy the smaller element to the original array
			r++
			cnt += middle - left - l // Increment inversion count
		}
	}

	return cnt // Return the number of inversions
}

// Recursive function to merge-sort the given array
func merge(a []int, left, right int) int {
	if left+1 < right { // If the subarray has more than one element
		middle := (left + right) / 2 // Calculate the middle index of the subarray
		x1 := merge(a, left, middle) // Merge-sort the left subarray
		x2 := merge(a, middle, right) // Merge-sort the right subarray
		x3 := sort(a, left, middle, right) // Merge the sorted subarrays and count inversions
		return x1 + x2 + x3 // Return the total number of inversions
	} else { // If the subarray has only one element
		return 0 // No inversions are present
	}
}

// Main function to read input and call merge-sort function
func main() {
	var n int // Read the number of elements in the array
	fmt.Scan(&n)
	a := make([]int, n) // Allocate memory for the array

	for i := 0; i < n; i++ { // Read the elements of the array from the standard input
		fmt.Scan(&a[i])
	}

	fmt.Println(merge(a, 0, n)) // Call the merge-sort function and print the result
}

