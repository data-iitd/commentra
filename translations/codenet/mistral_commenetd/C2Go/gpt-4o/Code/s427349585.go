package main

import (
	"fmt"
)

// Define a custom data structure 'card' with a character and an integer.
type card struct {
	s byte
	v int
}

// Allocate memory for two slices L and R, each with size (n+2), where n is the number of input cards.
var L, R []card

// Function 'me' sorts a subarray of 'a' using merge sort algorithm.
func me(a []card, l, m, r int) {
	n1 := m - l // Number of elements to be copied to L array.
	n2 := r - m // Number of elements to be copied to R array.

	// Copy elements from 'a' to L and R slices.
	L = make([]card, n1+1)
	R = make([]card, n2+1)
	for i := 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i := 0; i < n2; i++ {
		R[i] = a[m+i]
	}

	// Set the last elements of L and R slices with a large value to mark the end of each array.
	L[n1].v = 2000000000
	R[n2].v = 2000000000

	// Merge sorted subarrays L and R back to 'a'.
	i, j := 0, 0
	for k := l; k < r; k++ {
		// Compare elements from L and R slices and copy smaller one to 'a'.
		if L[i].v <= R[j].v {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
		}
	}
}

// Recursive function 'ms' to merge sort the entire array 'a'.
func ms(a []card, l, r int) {
	if l+1 < r {
		m := (l + r) / 2
		// Recursively sort left and right subarrays and then merge them.
		ms(a, l, m)
		ms(a, m, r)
		// Merge sorted subarrays.
		me(a, l, m, r)
	}
}

// Function 'partition' partitions an array into two parts: one with elements smaller than 'x' and another with elements greater than or equal to 'x'.
func partition(a []card, p, r int) int {
	x := a[r] // Set 'x' as the last element of the array.
	i := p - 1 // Index of the last element in the left subarray.

	// Iterate through the array from index p to r-1 and swap elements if they are smaller than 'x'.
	for j := p; j < r; j++ {
		if a[j].v <= x.v {
			i++ // Increment index of the last element in the left subarray.
			a[i], a[j] = a[j], a[i] // Swap elements a[i] and a[j].
		}
	}
	// Swap the last elements of the left and right subarrays.
	a[i+1], a[r] = a[r], a[i+1]
	// Return the index 'i+1' as the pivot index.
	return i + 1
}

// Function 'qs' implements quicksort algorithm to sort the array 'a'.
func qs(a []card, p, r int) {
	if p < r {
		q := partition(a, p, r)
		// Recursively sort the left and right subarrays.
		qs(a, p, q-1)
		qs(a, q+1, r)
	}
}

// Main function to read input, sort the array using merge sort and quicksort, and print the sorted array.
func main() {
	var n int
	fmt.Scan(&n)

	a := make([]card, n)
	b := make([]card, n)
	var s string
	stable := true

	// Read input cards and initialize 'a' and 'b' slices.
	for i := 0; i < n; i++ {
		fmt.Scan(&s, &a[i].v)
		a[i].s = s[0] // Set the character part of 'a' and 'b' equal to the first character of the input string.
		b[i] = a[i]   // Set 'b' equal to 'a'.
	}

	// Merge sort the 'a' slice.
	ms(a, 0, n)

	// Quick sort the 'b' slice.
	qs(b, 0, n-1)

	// Compare 'a' and 'b' slices to check stability.
	for i := 0; i < n; i++ {
		if a[i].s != b[i].s {
			stable = false
		}
	}
	// Print the result and the sorted array 'b'.
	if stable {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}
	// Print the sorted array 'b'.
	for i := 0; i < n; i++ {
		fmt.Printf("%c %d\n", b[i].s, b[i].v)
	}
}

// <END-OF-CODE>
