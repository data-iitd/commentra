
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	INF = 0x3f3f3f3f // Define a large constant for comparison
	MAXN = 2 * 1e5 + 10 // Define the maximum size for the array
)

var (
	a [MAXN]int // Declare the array
	L [MAXN/2]int // Declare temporary arrays for merging
	R [MAXN/2]int // Declare temporary arrays for merging
)

// Function to merge two halves of the array and count inversions
func merge(left, mid, right int) int {
	var (
		i, j, k int
		cnt int // Initialize inversion count
	)
	n1 := mid - left // Size of the left subarray
	n2 := right - mid // Size of the right subarray

	// Copy data to temporary arrays L and R
	for i = 0; i < n1; i++ {
		L[i] = a[left+i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[mid+i]
	}

	// Sentinel values to avoid out-of-bounds access
	L[n1] = R[n2] = INF

	i, j = 0, 0 // Initialize pointers for L and R
	// Merge the two subarrays back into the original array
	for k = left; k < right; k++ {
		if L[i] <= R[j] {
			a[k] = L[i] // If L[i] is smaller, take it
			i++ // Move the pointer for L
		} else {
			a[k] = R[j] // If R[j] is smaller, take it
			cnt += n1 - i // Count inversions: all remaining elements in L are greater than R[j]
			j++ // Move the pointer for R
		}
	}
	return cnt // Return the count of inversions
}

// Function to perform mergesort and count inversions
func mergesort(left, right int) int {
	var (
		mid int
		v1, v2, v3 int
	)
	// Base case: if the subarray has more than one element
	if left+1 < right {
		mid = (left + right) / 2 // Find the mid point
		v1 = mergesort(left, mid) // Sort the left half and count inversions
		v2 = mergesort(mid, right) // Sort the right half and count inversions
		v3 = merge(left, mid, right) // Merge both halves and count cross inversions
		return v1 + v2 + v3 // Return total inversion count
	}
	return 0 // Return 0 for a single element (no inversions)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements:")
	n, _ := reader.ReadString('\n')
	fmt.Sscanf(n, "%d", &n) // Read the number of elements

	for i := 0; i < n; i++ {
		fmt.Printf("Enter element %d: ", i+1)
		fmt.Fscanf(reader, "%d", &a[i]) // Read the elements into the array
	}

	ans := mergesort(0, n) // Perform mergesort and get the inversion count
	fmt.Println("The number of inversions is:", ans) // Output the result
}

