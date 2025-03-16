package main

import (
	"fmt"
)

// Define a structure to represent a card with a character and an integer value
type Card struct {
	s byte // Character representing the card's suit or type
	v int  // Integer representing the card's value
}

// Arrays to hold the left and right halves during merge sort
var L, R [100000/2 + 2]Card

// Merge function to combine two sorted halves of the array
func merge(a []Card, l, m, r int) {
	n1 := m - l // Size of the left half
	n2 := r - m // Size of the right half

	// Copy data to temporary arrays L and R
	for i := 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i := 0; i < n2; i++ {
		R[i] = a[m+i]
	}

	// Sentinel values to avoid out-of-bounds access
	L[n1].v = 2000000000
	R[n2].v = 2000000000

	// Merge the temporary arrays back into the original array
	i, j := 0, 0 // Index for left and right arrays
	for k := l; k < r; k++ {
		if L[i].v <= R[j].v {
			a[k] = L[i]
			i++ // Take from left if it's smaller or equal
		} else {
			a[k] = R[j]
			j++ // Take from right otherwise
		}
	}
}

// Merge sort function to recursively sort the array
func mergeSort(a []Card, l, r int) {
	if l+1 < r { // Base case: if the segment has more than one element
		m := (l + r) / 2 // Find the midpoint
		mergeSort(a, l, m) // Sort the left half
		mergeSort(a, m, r) // Sort the right half
		merge(a, l, m, r) // Merge the sorted halves
	}
}

// Partition function for quicksort
func partition(a []Card, p, r int) int {
	x := a[r] // Choose the last element as the pivot
	i := p - 1 // Index of smaller element
	for j := p; j < r; j++ {
		if a[j].v <= x.v { // If current element is smaller than or equal to pivot
			i++ // Increment index of smaller element
			// Swap elements
			a[i], a[j] = a[j], a[i]
		}
	}
	// Swap the pivot element with the element at i + 1
	a[i+1], a[r] = a[r], a[i+1]
	return i + 1 // Return the partitioning index
}

// Quicksort function to recursively sort the array
func quickSort(a []Card, p, r int) {
	if p < r { // Base case: if the segment has more than one element
		q := partition(a, p, r) // Partition the array
		quickSort(a, p, q-1) // Recursively sort the left half
		quickSort(a, q+1, r) // Recursively sort the right half
	}
}

// Main function
func main() {
	var n, v int
	var s [10]byte // Temporary storage for the character input
	var a, b [200000]Card // Arrays to hold the cards for sorting
	stable := true // Flag to check if the sorting is stable

	// Read the number of cards
	fmt.Scan(&n)

	// Read the cards into both arrays a and b
	for i := 0; i < n; i++ {
		fmt.Scanf("%s %d", &s, &v)
		a[i].s = s[0] // Store the character
		b[i].s = s[0] // Store the character
		a[i].v = v    // Store the value
		b[i].v = v    // Store the value
	}

	// Perform merge sort on array a
	mergeSort(a[:], 0, n)
	// Perform quicksort on array b
	quickSort(b[:], 0, n-1)

	// Check if the sorting is stable by comparing the original and sorted arrays
	for i := 0; i < n; i++ {
		if a[i].s != b[i].s {
			stable = false // If any character differs, it's not stable
		}
	}

	// Output the stability result
	if stable {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}

	// Print the sorted array
	for i := 0; i < n; i++ {
		fmt.Printf("%c %d\n", b[i].s, b[i].v)
	}
}

// <END-OF-CODE>
