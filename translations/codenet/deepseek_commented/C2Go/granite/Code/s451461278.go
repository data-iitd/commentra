
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Partition function used in Quicksort algorithm
func Partition(C []string, A []int, p int, r int) int {
	// Variables to store temporary values during partition
	var i, j int
	x := C[r]
	y := A[r]
	i = p - 1

	// Rearrange elements in the array
	for j = p; j < r; j++ {
		if A[j] <= y {
			i = i + 1
			tmpN := A[j]
			tmpC := C[j]
			A[j] = A[i]
			C[j] = C[i]
			A[i] = tmpN
			C[i] = tmpC
		}
	}

	// Place the pivot element in its correct position
	tmpN := A[i+1]
	tmpC := C[i+1]
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

	// Create temp arrays
	LN := make([]int, n1+1)
	LC := make([]string, n1+1)
	RN := make([]int, n2+1)
	RC := make([]string, n2+1)

	// Copy data to temp arrays
	i, j, k := 1, 1, left
	for i = 1; i <= n1; i++ {
		LN[i] = MN[left+i-1]
		LC[i] = MC[left+i-1]
	}
	for j = 1; j <= n2; j++ {
		RN[j] = MN[mid+j]
		RC[j] = MC[mid+j]
	}

	// Add sentinel values to avoid checking if any subarray is empty
	LN[n1+1] = 1000000000
	RN[n2+1] = 1000000000

	// Initial indexes for subarrays
	i, j = 1, 1

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
	mid := (left + right) / 2

	// Base case: if the subarray has more than one element
	if left < right {
		Merge_Sort(MC, MN, left, mid)
		Merge_Sort(MC, MN, mid+1, right)
		Merge(MC, MN, left, mid, right)
	}
}

func main() {
	// Read input
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements: ")
	n, _ := strconv.Atoi(reader.ReadLine()[0:1])
	C := make([]string, n+1)
	A := make([]int, n+1)
	for i := 1; i <= n; i++ {
		input := strings.Split(reader.ReadLine(), " ")
		C[i] = input[0]
		A[i], _ = strconv.Atoi(input[1])
	}

	// Copy characters and numbers to another array for Merge Sort
	MC := make([]string, n+1)
	MN := make([]int, n+1)
	for i := 1; i <= n; i++ {
		MC[i] = C[i]
		MN[i] = A[i]
	}

	// Sort the copied array using Merge Sort
	Merge_Sort(MC, MN, 1, n)

	// Sort the original array using Quicksort
	Quicksort(C, A, 1, n)

	// Check if the sorting results are stable
	count := 0
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
		fmt.Printf("%s %d\n", C[i], A[i])
	}
}

