<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Partition function used in Quicksort algorithm
func Partition(C []string, A []int, p int, r int) int {

	// Variables to store temporary values during partition
	var i, j int
	var tmpC string
	var tmpN int
	var x string
	var y int

	// Choose the last element as pivot
	x = C[r]
	y = A[r]
	i = p - 1

	// Rearrange elements in the array
	for j = p; j < r; j++ {
		if A[j] <= y {
			i = i + 1
			tmpN = A[j]
			tmpC = C[j]
			A[j] = A[i]
			C[j] = C[i]
			A[i] = tmpN
			C[i] = tmpC
		}
	}

	// Place the pivot element in its correct position
	tmpN = A[i+1]
	tmpC = C[i+1]
	A[i+1] = A[r]
	C[i+1] = C[r]
	A[r] = tmpN
	C[r] = tmpC

	return i + 1
}

// Quicksort function to sort the array recursively
func Quicksort(C []string, A []int, p int, r int) {

	// Base case: if the subarray has more than one element
	if p < r {
		q := Partition(C, A, p, r)
		Quicksort(C, A, p, q-1)
		Quicksort(C, A, q+1, r)
	}
}

// Merge function to merge two sorted subarrays
func Merge(MC []string, MN []int, left int, mid int, right int) {

	// Calculate sizes of two subarrays to be merged
	n1 := mid - left + 1
	n2 := right - mid
	LN := make([]int, n1+1)
	RN := make([]int, n2+1)
	LC := make([]string, n1+1)
	RC := make([]string, n2+1)

	// Copy data to temp arrays
	var i, j, k int
	for i = 1; i <= n1; i++ {
		LN[i] = MN[left+i-1]
		LC[i] = MC[left+i-1]
	}
	for i = 1; i <= n2; i++ {
		RN[i] = MN[mid+i]
		RC[i] = MC[mid+i]
	}

	// Sentinel values to avoid checking if any subarray is empty
	LN[n1+1] = 1000000000
	RN[n2+1] = 1000000000

	// Initial indexes for subarrays
	i = 1
	j = 1

	// Merge the temp arrays back into arr[left..right]
	for k = left; k <= right; k++ {
		if LN[i] <= RN[j] {
			MN[k] = LN[i]
			MC[k] = LC[i]
			i++
		} else {
			MN[k] = RN[j]
			MC[k] = RC[j]
			j++
		}
	}
}

// Merge Sort function to sort the array using recursion
func Merge_Sort(MC []string, MN []int, left int, right int) {
	var mid int

	// Base case: if the subarray has more than one element
	if left < right {
		mid = (left + right) / 2
		Merge_Sort(MC, MN, left, mid)
		Merge_Sort(MC, MN, mid+1, right)
		Merge(MC, MN, left, mid, right)
	}
}

func main() {

	// Arrays to store characters and their corresponding numbers
	var A [100001]int
	var C [100001]string
	var MC [100001]string
	var MN [100001]int

	// Variables to store the number of elements and loop index
	var i, p, n int
	var count int = 0

	// Read the number of elements
	fmt.Scanf("%d\n", &n)

	// Read characters and their corresponding numbers
	for i = 1; i <= n; i++ {
		fmt.Scanf("%s %d\n", &C[i], &A[i])
	}

	// Copy characters and numbers to another array for Merge Sort
	for i = 1; i <= n; i++ {
		MC[i] = C[i]
		MN[i] = A[i]
	}

	// Sort the copied array using Merge Sort
	Merge_Sort(MC, MN, 1, n)

	// Sort the original array using Quicksort
	p = 1
	Quicksort(C, A, p, n)

	// Check if the sorting results are stable
	for i = 1; i <= n; i++ {
		if MN[i] == A[i] && MC[i] == C[i] {
			count++
		}
	}

	// Print the stability result
	if count == n {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}

	// Print the sorted characters and their corresponding numbers
	for i = 1; i <= n; i++ {
		fmt.Printf("%s %d\n", C[i], A[i])
	}
}

