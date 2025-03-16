package main

import (
	"fmt"
	"math"
)

const unko = 1e12

// Function to sort a subarray using merge-sort algorithm
func sort(a []int64, left, middle, right int) int64 {
	lArr := make([]int64, middle-left+1) // Allocate memory for left subarray
	rArr := make([]int64, right-middle+1) // Allocate memory for right subarray
	var cnt int64 = 0 // Initialize inversion count to zero

	// Copy elements from the left subarray to a temporary array
	for i := 0; i < middle-left; i++ {
		lArr[i] = a[i+left] // Copy elements from the original array to the temporary array
	}

	// Copy elements from the right subarray to a temporary array
	for i := 0; i < right-middle; i++ {
		rArr[i] = a[i+middle] // Copy elements from the original array to the temporary array
	}

	// Set the last element of left subarray and right subarray to a large value
	lArr[middle-left] = unko
	rArr[right-middle] = unko

	l, r := 0, 0 // Initialize pointers for left and right subarrays

	// Merge the sorted subarrays back to the original array and count inversions
	for i := 0; i < right-left; i++ {
		if lArr[l] <= rArr[r] { // If current element from left subarray is smaller than or equal to current element from right subarray
			a[left+i] = lArr[l] // Copy the smaller element to the original array
			l++
		} else { // If current element from left subarray is greater than the current element from right subarray
			a[left+i] = rArr[r] // Copy the smaller element to the original array
			cnt += int64(middle-left-l) // Increment inversion count
			r++
		}
	}

	return cnt // Return the number of inversions
}

// Recursive function to merge-sort the given array
func merge(a []int64, left, right int) int64 {
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
	var n int
	fmt.Scan(&n) // Read the number of elements from the standard input
	a := make([]int64, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read the elements of the array from the standard input
	}

	result := merge(a, 0, n) // Call the merge-sort function and get the result
	fmt.Println(result) // Print the result
}

