package main

import (
	"fmt"
)

const MAX = 100000

// Partition function used in Quicksort algorithm
func Partition(C []rune, A []int, p, r int) int {
	// Variables to store temporary values during partition
	var i, j int
	var tmpC rune
	var tmpN int
	x := A[r]
	i = p - 1
	for j = p; j < r; j++ {
		if A[j] <= x {
			i++
			tmpN = A[j]
			tmpC = C[j]
			A[j] = A[i]
			C[j] = C[i]
			A[i] = tmpN
			C[i] = tmpC
		}
	}
	tmpN = A[i+1]
	tmpC = C[i+1]
	A[i+1] = A[r]
	C[i+1] = C[r]
	A[r] = tmpN
	C[r] = tmpC
	return i + 1
}

// Quicksort function to sort the array recursively
func Quicksort(C []rune, A []int, p, r int) {
	if p < r {
		q := Partition(C, A, p, r)
		Quicksort(C, A, p, q-1)
		Quicksort(C, A, q+1, r)
	}
}

// Merge function to merge two sorted subarrays
func Merge(MC []rune, MN []int, left, mid, right int) {
	n1 := mid - left + 1
	n2 := right - mid
	LN := make([]int, n1+1)
	RN := make([]int, n2+1)
	LC := make([]rune, n1+1)
	RC := make([]rune, n2+1)
	for i := 1; i <= n1; i++ {
		LN[i] = MN[left+i-1]
		LC[i] = MC[left+i-1]
	}
	for i := 1; i <= n2; i++ {
		RN[i] = MN[mid+i]
		RC[i] = MC[mid+i]
	}
	LN[n1+1] = 1000000000
	RN[n2+1] = 1000000000
	var i, j, k int
	i = 1
	j = 1
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
func Merge_Sort(MC []rune, MN []int, left, right int) {
	if left < right {
		mid := (left + right) / 2
		Merge_Sort(MC, MN, left, mid)
		Merge_Sort(MC, MN, mid+1, right)
		Merge(MC, MN, left, mid, right)
	}
}

func main() {
	// Arrays to store characters and their corresponding numbers
	A := make([]int, MAX+1)
	C := make([]rune, MAX+1)
	MC := make([]rune, MAX+1)
	MN := make([]int, MAX+1)
	// Variables to store the number of elements and loop index
	var i, p, n int
	var count int
	// Read the number of elements
	fmt.Scan(&n)
	// Read characters and their corresponding numbers
	for i = 1; i <= n; i++ {
		fmt.Scanf(" %c %d", &C[i], &A[i])
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
	count = 0
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
		fmt.Printf("%c %d\n", C[i], A[i])
	}
}
