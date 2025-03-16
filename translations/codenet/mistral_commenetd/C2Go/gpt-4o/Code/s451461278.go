package main

import (
	"fmt"
)

const MAX = 100000

// Function declarations
func partition(C []rune, A []int, p int, r int) int
func quicksort(C []rune, A []int, p int, r int)
func merge(MC []rune, MN []int, left int, mid int, right int)
func mergeSort(MC []rune, MN []int, left int, right int)

func main() {
	var n int
	fmt.Scan(&n)

	A := make([]int, MAX+1) // Dynamically allocated array for integers A
	C := make([]rune, MAX+1) // Dynamically allocated array for characters C
	MC := make([]rune, MAX+1) // Dynamically allocated array for characters MC (Modified C)
	MN := make([]int, MAX+1) // Dynamically allocated array for integers MN (Modified N)

	// Read characters and integers from the standard input
	for i := 1; i <= n; i++ {
		var char byte
		var num int
		fmt.Scanf(" %c %d", &char, &num)
		C[i] = rune(char)
		A[i] = num
	}

	// Copy characters and integers from A to MC and MN respectively
	for i := 1; i <= n; i++ {
		MC[i] = C[i]
		MN[i] = A[i]
	}

	// Merge sort on MC and MN arrays
	mergeSort(MC, MN, 1, n)

	// Quick sort on C and A arrays
	p := 1
	quicksort(C, A, p, n)

	// Check if the arrays are equal after sorting
	count := 0
	for i := 1; i <= n; i++ {
		if MN[i] == A[i] && MC[i] == C[i] {
			count++
		}
	}

	// Print the result
	if count == n {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}

	// Print the sorted arrays
	for i := 1; i <= n; i++ {
		fmt.Printf("%c %d\n", C[i], A[i])
	}
}

// Partition function for quick sort
func partition(C []rune, A []int, p int, r int) int {
	x := C[r]
	y := A[r]
	i := p - 1

	for j := p; j < r; j++ {
		if A[j] <= y {
			i++
			A[i], A[j] = A[j], A[i]
			C[i], C[j] = C[j], C[i]
		}
	}

	A[i+1], A[r] = A[r], A[i+1]
	C[i+1], C[r] = C[r], C[i+1]

	return i + 1
}

// Quicksort function
func quicksort(C []rune, A []int, p int, r int) {
	if p < r {
		q := partition(C, A, p, r)
		quicksort(C, A, p, q-1)
		quicksort(C, A, q+1, r)
	}
}

// Merge function for merge sort
func merge(MC []rune, MN []int, left int, mid int, right int) {
	n1 := mid - left + 1
	n2 := right - mid
	LN := make([]int, n1+1)
	LC := make([]rune, n1+1)
	RN := make([]int, n2+1)
	RC := make([]rune, n2+1)

	// Copy the left partition to LN and LC arrays
	for i := 1; i <= n1; i++ {
		LN[i] = MN[left+i-1]
		LC[i] = MC[left+i-1]
	}

	// Copy the right partition to RN and RC arrays
	for i := 1; i <= n2; i++ {
		RN[i] = MN[mid+i]
		RC[i] = MC[mid+i]
	}

	// Set the sentinel values for LN and RN arrays
	LN[n1+1] = 1000000000
	RN[n2+1] = 1000000000

	// Merge the left and right partitions into the original arrays
	i, j, k := 1, 1, left
	for i <= n1 && j <= n2 {
		if LN[i] <= RN[j] {
			MN[k] = LN[i]
			MC[k] = LC[i]
			i++
		} else {
			MN[k] = RN[j]
			MC[k] = RC[j]
			j++
		}
		k++
	}
}

// Merge sort function
func mergeSort(MC []rune, MN []int, left int, right int) {
	if left < right {
		mid := (left + right) / 2
		mergeSort(MC, MN, left, mid)
		mergeSort(MC, MN, mid+1, right)
		merge(MC, MN, left, mid, right)
	}
}

// <END-OF-CODE>
