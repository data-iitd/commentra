package main

import (
	"fmt"
)

const MAX = 100000

// Partition function used in Quicksort algorithm
func Partition(C []rune, A []int, p int, r int) int {
	var i, j int
	var tmpC rune
	var x rune
	var tmpN int
	var y int

	// Choose the last element as pivot
	x = C[r]
	y = A[r]
	i = p - 1

	// Rearrange elements in the array
	for j = p; j < r; j++ {
		if A[j] <= y {
			i++
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
func Quicksort(C []rune, A []int, p int, r int) {
	// Base case: if the subarray has more than one element
	if p < r {
		q := Partition(C, A, p, r)
		Quicksort(C, A, p, q-1)
		Quicksort(C, A, q+1, r)
	}
}

// Merge function to merge two sorted subarrays
func Merge(MC []rune, MN []int, left int, mid int, right int) {
	n1 := mid - left + 1
	n2 := right - mid
	LN := make([]int, n1+1)
	RN := make([]int, n2+1)
	LC := make([]rune, n1+1)
	RC := make([]rune, n2+1)

	// Copy data to temp arrays
	for i := 0; i < n1; i++ {
		LN[i] = MN[left+i]
		LC[i] = MC[left+i]
	}

	for i := 0; i < n2; i++ {
		RN[i] = MN[mid+i+1]
		RC[i] = MC[mid+i+1]
	}

	// Sentinel values to avoid checking if any subarray is empty
	LN[n1] = 1000000000
	RN[n2] = 1000000000

	// Initial indexes for subarrays
	i, j := 0, 0

	// Merge the temp arrays back into arr[left..right]
	for k := left; k <= right; k++ {
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
func Merge_Sort(MC []rune, MN []int, left int, right int) {
	if left < right {
		mid := (left + right) / 2
		Merge_Sort(MC, MN, left, mid)
		Merge_Sort(MC, MN, mid+1, right)
		Merge(MC, MN, left, mid, right)
	}
}

// Main function to read input, sort data using both algorithms, and check stability
func main() {
	var n int
	var count int

	// Arrays to store characters and their corresponding numbers
	A := make([]int, MAX+1)
	C := make([]rune, MAX+1)
	MC := make([]rune, MAX+1)
	MN := make([]int, MAX+1)

	// Read the number of elements
	fmt.Scan(&n)

	// Read characters and their corresponding numbers
	for i := 1; i <= n; i++ {
		var char rune
		var num int
		fmt.Scanf(" %c %d", &char, &num)
		C[i] = char
		A[i] = num
	}

	// Copy characters and numbers to another array for Merge Sort
	for i := 1; i <= n; i++ {
		MC[i] = C[i]
		MN[i] = A[i]
	}

	// Sort the copied array using Merge Sort
	Merge_Sort(MC, MN, 1, n)

	// Sort the original array using Quicksort
	Quicksort(C, A, 1, n)

	// Check if the sorting results are stable
	for i := 1; i <= n; i++ {
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
	for i := 1; i <= n; i++ {
		fmt.Printf("%c %d\n", C[i], A[i])
	}
}

// <END-OF-CODE>
