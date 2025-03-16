package main

import (
	"fmt"
	"math"
)

const unko = math.MaxInt64

// Function to merge two subarrays and count inversions
func sort(a []int64, left, middle, right int) int64 {
	lArr := make([]int64, middle-left+1)
	rArr := make([]int64, right-middle+1)
	cnt := int64(0)
	// Copy elements into temporary arrays
	for i := 0; i < middle-left; i++ {
		lArr[i] = a[i+left]
	}
	for i := 0; i < right-middle; i++ {
		rArr[i] = a[i+middle]
	}
	// Sentinel values to simplify merging
	lArr[middle-left] = unko
	rArr[right-middle] = unko
	l, r := 0, 0
	// Merge the two subarrays while counting inversions
	for i := 0; i < right-left; i++ {
		if lArr[l] <= rArr[r] {
			a[left+i] = lArr[l]
			l++
		} else {
			a[left+i] = rArr[r]
			r++
			cnt += int64(middle - left - l)
		}
	}
	return cnt
}

// Recursive function to count inversions in the array
func merge(a []int64, left, right int) int64 {
	if left+1 < right {
		middle := (left + right) / 2
		// Recursively count inversions in the left and right halves
		x1 := merge(a, left, middle)
		x2 := merge(a, middle, right)
		// Merge the two halves and count inversions in the merge step
		x3 := sort(a, left, middle, right)
		return x1 + x2 + x3
	} else {
		return 0
	}
}

// Main function to read input, count inversions, and print the result
func main() {
	var n int
	fmt.Scan(&n) // Read the size of the array
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read the elements of the array
	}
	fmt.Println(merge(a, 0, n)) // Count and print the number of inversions
}

