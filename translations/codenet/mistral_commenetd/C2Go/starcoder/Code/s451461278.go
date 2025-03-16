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

// Function declarations
func Partition(C []string, A []int, p int, r int) int {
	var i, j int
	var tmpC string
	var tmpN int
	var x string
	var y int

	// Set the pivot element as the last element of the array
	x = C[r]
	y = A[r]

	// Set the initial index of the left partition as p - 1
	i = p - 1

	// Iterate through the array from p to r - 1
	for j = p; j < r; j++ {
		// If the current element is smaller than the pivot, increment i and swap the elements
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

	// Swap the pivot element with the element at index i + 1
	tmpN = A[i+1]
	tmpC = C[i + 1]
	A[i+1] = A[r]
	C[i+1] = C[r]
	A[r] = tmpN
	C[r] = tmpC

	// Return the index of the pivot element
	return i + 1
}

func Quicksort(C []string, A []int, p int, r int) {
	// Base case: if p is less than r, recursively call Partition and Quicksort functions
	if p < r {
		q := Partition(C, A, p, r)
		Quicksort(C, A, p, q-1)
		Quicksort(C, A, q+1, r)
	}
}

func Merge(MC []string, MN []int, left int, mid int, right int) {
	var n1 int
	var n2 int
	var LN []int
	var RN []int
	var LC []string
	var RC []string

	// Calculate the size of the left partition
	n1 = mid - left + 1

	// Calculate the size of the right partition
	n2 = right - mid

	// Dynamically allocate memory for the left partition of integers
	LN = make([]int, n1+1)

	// Dynamically allocate memory for the right partition of integers
	RN = make([]int, n2+1)

	// Dynamically allocate memory for the left partition of characters
	LC = make([]string, n1+1)

	// Dynamically allocate memory for the right partition of characters
	RC = make([]string, n2+1)

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
	i := 1
	j := 1
	k := left
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

	// Free the dynamically allocated memory
	LN = nil
	RN = nil
	LC = nil
	RC = nil
}

func Merge_Sort(MC []string, MN []int, left int, right int) {
	var mid int

	// Base case: if left is less than right, recursively call Merge_Sort and Merge functions
	if left < right {
		mid = (left + right) / 2
		Merge_Sort(MC, MN, left, mid)
		Merge_Sort(MC, MN, mid+1, right)
		Merge(MC, MN, left, mid, right)
	}
}

// Main function
func main() {
	var i, p, n int
	var count int
	var A []int
	var C []string
	var MC []string
	var MN []int

	// Read the number of elements n
	fmt.Scanf("%d", &n)

	// Dynamically allocate memory for the arrays
	A = make([]int, n+1)
	C = make([]string, n+1)
	MC = make([]string, n+1)
	MN = make([]int, n+1)

	// Read characters and integers from the standard input
	for i = 1; i <= n; i++ {
		fmt.Scanf(" %s %d", &C[i], &A[i])
	}

	// Copy characters and integers from A to MC and MN respectively
	for i = 1; i <= n; i++ {
		MC[i] = C[i]
		MN[i] = A[i]
	}

	// Merge sort on MC and MN arrays
	Merge_Sort(MC, MN, 1, n)

	// Quick sort on C and A arrays
	p = 1
	Quicksort(C, A, p, n)

	// Check if the arrays are equal after sorting
	for i = 1; i <= n; i++ {
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
	for i = 1; i <= n; i++ {
		fmt.Printf("%s %d\n", C[i], A[i])
	}
}

