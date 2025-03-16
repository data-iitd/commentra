package main

import (
	"fmt"
)

const MAX = 100000

// Function prototypes for partitioning and sorting
func Partition(C []rune, A []int, p, r int) int
func Quicksort(C []rune, A []int, p, r int)
func Merge(MC []rune, MN []int, left, mid, right int)
func MergeSort(MC []rune, MN []int, left, right int)

// Global variable for partition index
var q int

func main() {
	// Declare arrays for storing values and characters
	A := make([]int, MAX+1) // Array for integer values
	C := make([]rune, MAX+1) // Array for characters
	MC := make([]rune, MAX+1) // Array for characters for merge sort
	MN := make([]int, MAX+1) // Array for integer values for merge sort

	var i, p, n int
	var count int = 0 // Counter for stable sorting check

	// Read the number of elements
	fmt.Scan(&n)

	// Read character and integer pairs into arrays
	for i = 1; i <= n; i++ {
		fmt.Scanf(" %c %d", &C[i], &A[i])
	}

	// Copy original arrays to auxiliary arrays for merge sort
	for i = 1; i <= n; i++ {
		MC[i] = C[i]
		MN[i] = A[i]
	}

	// Perform merge sort on the auxiliary arrays
	MergeSort(MC, MN, 1, n)

	// Perform quicksort on the original arrays
	p = 1
	Quicksort(C, A, p, n)

	// Check if the sorting is stable by comparing original and sorted arrays
	for i = 1; i <= n; i++ {
		if MN[i] == A[i] && MC[i] == C[i] {
			count++
		}
	}

	// Output stability result
	if count == n {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}

	// Print the sorted character and integer pairs
	for i = 1; i <= n; i++ {
		fmt.Printf("%c %d\n", C[i], A[i])
	}
}

// Function to partition the array for quicksort
func Partition(C []rune, A []int, p, r int) int {
	var i, j int
	var tmpC rune
	var tmpN int
	var x rune
	var y int

	// Choose the last element as pivot
	x = C[r]
	y = A[r]
	i = p - 1

	// Rearrange elements based on the pivot
	for j = p; j < r; j++ {
		if A[j] <= y {
			i = i + 1
			// Swap elements to partition the array
			tmpN = A[j]
			tmpC = C[j]
			A[j] = A[i]
			C[j] = C[i]
			A[i] = tmpN
			C[i] = tmpC
		}
	}

	// Place the pivot in the correct position
	tmpN = A[i+1]
	tmpC = C[i+1]
	A[i+1] = A[r]
	C[i+1] = C[r]
	A[r] = tmpN
	C[r] = tmpC

	return i + 1 // Return the pivot index
}

// Function to perform quicksort
func Quicksort(C []rune, A []int, p, r int) {
	// Base case for recursion
	if p < r {
		q = Partition(C, A, p, r) // Partition the array
		Quicksort(C, A, p, q-1) // Recursively sort the left subarray
		Quicksort(C, A, q+1, r) // Recursively sort the right subarray
	}
}

// Function to merge two sorted subarrays
func Merge(MC []rune, MN []int, left, mid, right int) {
	var n1 int = mid - left + 1 // Size of left subarray
	var n2 int = right - mid   // Size of right subarray
	var LN []int = make([]int, n1+1) // Left subarray for integers
	var RN []int = make([]int, n2+1) // Right subarray for integers
	var LC []rune = make([]rune, n1+1) // Left subarray for characters
	var RC []rune = make([]rune, n2+1) // Right subarray for characters

	var i, j, k int

	// Copy data to temporary arrays
	for i = 1; i <= n1; i++ {
		LN[i] = MN[left+i-1]
		LC[i] = MC[left+i-1]
	}

	for i = 1; i <= n2; i++ {
		RN[i] = MN[mid+i]
		RC[i] = MC[mid+i]
	}

	// Sentinel values for merging
	LN[n1+1] = 1000000000
	RN[n2+1] = 1000000000

	i = 1 // Index for left subarray
	j = 1 // Index for right subarray

	// Merge the temporary arrays back into the original arrays
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

// Function to perform merge sort
func MergeSort(MC []rune, MN []int, left, right int) {
	var mid int

	// Base case for recursion
	if left < right {
		mid = (left + right) / 2 // Find the midpoint
		MergeSort(MC, MN, left, mid) // Recursively sort the left half
		MergeSort(MC, MN, mid+1, right) // Recursively sort the right half
		Merge(MC, MN, left, mid, right) // Merge the sorted halves
	}
}

