
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function prototypes for partitioning and sorting
func Partition(C []rune, A []int, p int, r int) int {
	var i, j int
	var tmpC rune
	var x int
	var tmpN int

	// Choose the last element as pivot
	x = A[r]
	i = p - 1

	// Rearrange elements based on the pivot
	for j = p; j < r; j++ {
		if A[j] <= x {
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

func Quicksort(C []rune, A []int, p int, r int) {
	// Base case for recursion
	if p < r {
		q := Partition(C, A, p, r) // Partition the array
		Quicksort(C, A, p, q-1) // Recursively sort the left subarray
		Quicksort(C, A, q+1, r) // Recursively sort the right subarray
	}
}

func Merge(C []rune, A []int, left int, mid int, right int) {
	n1 := mid - left + 1
	n2 := right - mid

	LN := make([]int, n1+1) // Left subarray for integers
	LC := make([]rune, n1+1) // Left subarray for characters
	RN := make([]int, n2+1) // Right subarray for integers
	RC := make([]rune, n2+1) // Right subarray for characters

	var i, j, k int

	// Copy data to temporary arrays
	for i = 1; i <= n1; i++ {
		LN[i] = A[left+i-1]
		LC[i] = C[left+i-1]
	}

	for i = 1; i <= n2; i++ {
		RN[i] = A[mid+i]
		RC[i] = C[mid+i]
	}

	// Sentinel values for merging
	LN[n1+1] = 1000000000
	RN[n2+1] = 1000000000

	i = 1 // Index for left subarray
	j = 1 // Index for right subarray

	// Merge the temporary arrays back into the original arrays
	for k = left; k <= right; k++ {
		if LN[i] <= RN[j] {
			A[k] = LN[i]
			C[k] = LC[i]
			i++
		} else {
			A[k] = RN[j]
			C[k] = RC[j]
			j++
		}
	}
}

func Merge_Sort(C []rune, A []int, left int, right int) {
	var mid int

	// Base case for recursion
	if left < right {
		mid = (left + right) / 2 // Find the midpoint
		Merge_Sort(C, A, left, mid) // Recursively sort the left half
		Merge_Sort(C, A, mid+1, right) // Recursively sort the right half
		Merge(C, A, left, mid, right) // Merge the sorted halves
	}
}

func main() {
	// Declare arrays for storing values and characters
	var A []int // Array for integer values
	var C []rune // Array for characters
	var MC []rune // Array for characters for merge sort
	var MN []int // Array for integer values for merge sort

	var i, p, n int
	var count int // Counter for stable sorting check

	// Read the number of elements
	fmt.Scan(&n)

	// Read character and integer pairs into arrays
	A = make([]int, n+1)
	C = make([]rune, n+1)
	MC = make([]rune, n+1)
	MN = make([]int, n+1)

	for i = 1; i <= n; i++ {
		fmt.Scanf(" %c %d", &C[i], &A[i])
	}

	// Copy original arrays to auxiliary arrays for merge sort
	for i = 1; i <= n; i++ {
		MC[i] = C[i]
		MN[i] = A[i]
	}

	// Perform merge sort on the auxiliary arrays
	Merge_Sort(MC, MN, 1, n)

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
