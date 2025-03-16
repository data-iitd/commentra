package main

import (
	"fmt"
	"math"
)

const INF = math.MaxInt64 // Define a large constant for comparison
const MAXN = 2 * 1e5 + 10 // Define the maximum size for the array

var a [MAXN]int
var n int
var L [MAXN/2]int
var R [MAXN/2]int

// Function to merge two halves of the array and count inversions
func merge(left, mid, right int) int64 {
	var i, j, k int
	var cnt int64 = 0 // Initialize inversion count
	n1 := mid - left
	n2 := right - mid

	// Copy data to temporary arrays L and R
	for i = 0; i < n1; i++ {
		L[i] = a[left + i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[mid + i]
	}

	// Sentinel values to avoid out-of-bounds access
	L[n1] = INF
	R[n2] = INF

	i, j = 0, 0 // Initialize pointers for L and R
	// Merge the two subarrays back into the original array
	for k = left; k < right; k++ {
		if L[i] <= R[j] {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
			cnt += int64(n1 - i) // Count inversions: all remaining elements in L are greater than R[j]
		}
	}
	return cnt // Return the count of inversions
}

// Function to perform mergesort and count inversions
func mergesort(left, right int) int64 {
	var mid int
	var v1, v2, v3 int64
	// Base case: if the subarray has more than one element
	if left + 1 < right {
		mid = (left + right) / 2
		v1 = mergesort(left, mid) // Sort the left half and count inversions
		v2 = mergesort(mid, right) // Sort the right half and count inversions
		v3 = merge(left, mid, right) // Merge both halves and count cross inversions
		return v1 + v2 + v3 // Return total inversion count
	}
	return 0 // Return 0 for a single element (no inversions)
}

func main() {
	fmt.Scan(&n) // Read the number of elements
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read the elements into the array
	}

	ans := mergesort(0, n) // Perform mergesort and get the inversion count
	fmt.Println(ans) // Output the result
}

