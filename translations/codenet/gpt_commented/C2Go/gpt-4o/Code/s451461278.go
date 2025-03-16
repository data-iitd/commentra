package main

import (
	"fmt"
)

const MAX = 100000

// Function prototypes for partitioning and sorting
func partition(C []rune, A []int, p int, r int) int {
	i := p - 1
	x := C[r]
	y := A[r]

	for j := p; j < r; j++ {
		if A[j] <= y {
			i++
			// Swap elements to partition the array
			A[i], A[j] = A[j], A[i]
			C[i], C[j] = C[j], C[i]
		}
	}

	// Place the pivot in the correct position
	A[i+1], A[r] = A[r], A[i+1]
	C[i+1], C[r] = C[r], C[i+1]

	return i + 1 // Return the pivot index
}

func quicksort(C []rune, A []int, p int, r int) {
	if p < r {
		q := partition(C, A, p, r) // Partition the array
		quicksort(C, A, p, q-1)    // Recursively sort the left subarray
		quicksort(C, A, q+1, r)    // Recursively sort the right subarray
	}
}

func merge(MC []rune, MN []int, left int, mid int, right int) {
	n1 := mid - left + 1 // Size of left subarray
	n2 := right - mid     // Size of right subarray
	LN := make([]int, n1+1)
	RC := make([]rune, n2+1)
	LC := make([]rune, n1+1)
	RN := make([]int, n2+1)

	// Copy data to temporary arrays
	for i := 1; i <= n1; i++ {
		LN[i] = MN[left+i-1]
		LC[i] = MC[left+i-1]
	}

	for i := 1; i <= n2; i++ {
		RN[i] = MN[mid+i]
		RC[i] = MC[mid+i]
	}

	// Sentinel values for merging
	LN[n1+1] = 1000000000
	RN[n2+1] = 1000000000

	i, j := 1, 1 // Index for left and right subarrays

	// Merge the temporary arrays back into the original arrays
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

func mergeSort(MC []rune, MN []int, left int, right int) {
	if left < right {
		mid := (left + right) / 2 // Find the midpoint
		mergeSort(MC, MN, left, mid)       // Recursively sort the left half
		mergeSort(MC, MN, mid+1, right)    // Recursively sort the right half
		merge(MC, MN, left, mid, right)    // Merge the sorted halves
	}
}

func main() {
	var n int
	var count int // Counter for stable sorting check

	// Declare arrays for storing values and characters
	A := make([]int, MAX+1) // Array for integer values
	C := make([]rune, MAX+1) // Array for characters
	MC := make([]rune, MAX+1) // Array for characters for merge sort
	MN := make([]int, MAX+1) // Array for integer values for merge sort

	// Read the number of elements
	fmt.Scan(&n)

	// Read character and integer pairs into arrays
	for i := 1; i <= n; i++ {
		var char rune
		var num int
		fmt.Scanf(" %c %d", &char, &num)
		C[i] = char
		A[i] = num
	}

	// Copy original arrays to auxiliary arrays for merge sort
	for i := 1; i <= n; i++ {
		MC[i] = C[i]
		MN[i] = A[i]
	}

	// Perform merge sort on the auxiliary arrays
	mergeSort(MC, MN, 1, n)

	// Perform quicksort on the original arrays
	quicksort(C, A, 1, n)

	// Check if the sorting is stable by comparing original and sorted arrays
	for i := 1; i <= n; i++ {
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
	for i := 1; i <= n; i++ {
		fmt.Printf("%c %d\n", C[i], A[i])
	}
}

// <END-OF-CODE>
