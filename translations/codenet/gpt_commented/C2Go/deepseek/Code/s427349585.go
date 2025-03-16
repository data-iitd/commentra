package main

import (
	"fmt"
)

// Define a structure to represent a card with a character and an integer value
type card struct {
	s string // Character representing the card's suit or type
	v int    // Integer representing the card's value
}

// Arrays to hold the left and right halves during merge sort
var L = [100000/2 + 2]card{}
var R = [100000/2 + 2]card{}

// Merge function to combine two sorted halves of the array
func merge(a []card, n, l, m, r int) {
	i, j, k := 0, 0, 0
	n1 := m - l
	n2 := r - m

	// Copy data to temporary arrays L and R
	for i = 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[m+i]
	}

	// Sentinel values to avoid out-of-bounds access
	L[n1].v = 2000000000
	R[n2].v = 2000000000

	// Merge the temporary arrays back into the original array
	i = 0 // Index for left array
	j = 0 // Index for right array
	for k = l; k < r; k++ {
		if L[i].v <= R[j].v {
			a[k] = L[i] // Take from left if it's smaller or equal
			i++
		} else {
			a[k] = R[j] // Take from right otherwise
			j++
		}
	}
}

// Merge sort function to recursively sort the array
func mergeSort(a []card, n, l, r int) {
	if l+1 < r {
		m := (l + r) / 2
		mergeSort(a, n, l, m) // Sort the left half
		mergeSort(a, n, m, r) // Sort the right half
		merge(a, n, l, m, r)  // Merge the sorted halves
	}
}

// Partition function for quicksort
func partition(a []card, n, p, r int) int {
	x := a[r] // Choose the last element as the pivot
	i := p - 1
	for j := p; j < r; j++ {
		if a[j].v <= x.v {
			i++
			// Swap elements
			a[i], a[j] = a[j], a[i]
		}
	}
	// Swap the pivot element with the element at i + 1
	a[i+1], a[r] = a[r], a[i+1]
	return i + 1 // Return the partitioning index
}

// Quicksort function to recursively sort the array
func quickSort(a []card, n, p, r int) {
	if p < r {
		q := partition(a, n, p, r) // Partition the array
		quickSort(a, n, p, q-1)   // Recursively sort the left half
		quickSort(a, n, q+1, r)   // Recursively sort the right half
	}
}

func main() {
	var n, i, v int
	var a, b []card // Arrays to hold the cards for sorting
	var s string   // Temporary storage for the character input
	var stable = true // Flag to check if the sorting is stable

	// Read the number of cards
	fmt.Scan(&n)

	// Read the cards into both arrays a and b
	a = make([]card, n)
	b = make([]card, n)
	for i = 0; i < n; i++ {
		fmt.Scan(&s, &v)
		a[i] = card{s, v} // Store the character and value
		b[i] = card{s, v} // Store the character and value
	}

	// Perform merge sort on array a
	mergeSort(a, n, 0, n)
	// Perform quicksort on array b
	quickSort(b, n, 0, n-1)

	// Check if the sorting is stable by comparing the original and sorted arrays
	for i = 0; i < n; i++ {
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
	for i = 0; i < n; i++ {
		fmt.Printf("%s %d\n", b[i].s, b[i].v)
	}
}

