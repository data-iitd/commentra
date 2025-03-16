
package main

import (
	"fmt"
	"os"
	"strconv"
)

// Define a structure to represent a card with a character and an integer value
type card struct {
	s byte
	v int
}

// Arrays to hold the left and right halves during merge sort
var L [100000 / 2 + 2]card
var R [100000 / 2 + 2]card

// Merge function to combine two sorted halves of the array
func me(a []card, n int, l int, m int, r int) {
	var i int
	var j int
	var k int
	var n1 int = m - l // Size of the left half
	var n2 int = r - m // Size of the right half

	// Copy data to temporary arrays L and R
	for i = 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[m+i]
	}

	// Sentinel values to avoid out-of-bounds access
	L[n1].v = R[n2].v = 2000000000

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
func ms(a []card, n int, l int, r int) {
	var m int
	if l+1 < r { // Base case: if the segment has more than one element
		m = (l + r) / 2 // Find the midpoint
		ms(a, n, l, m)  // Sort the left half
		ms(a, n, m, r)  // Sort the right half
		me(a, n, l, m, r) // Merge the sorted halves
	}
}

// Partition function for quicksort
func partiton(a []card, n int, p int, r int) int {
	var i int
	var j int
	var t card
	var x card
	x = a[r] // Choose the last element as the pivot
	i = p - 1 // Index of smaller element
	for j = p; j < r; j++ {
		if a[j].v <= x.v { // If current element is smaller than or equal to pivot
			i++ // Increment index of smaller element
			// Swap elements
			t = a[i]
			a[i] = a[j]
			a[j] = t
		}
	}
	// Swap the pivot element with the element at i + 1
	t = a[i+1]
	a[i+1] = a[r]
	a[r] = t
	return i + 1 // Return the partitioning index
}

// Quicksort function to recursively sort the array
func qs(a []card, n int, p int, r int) {
	var q int
	if p < r { // Base case: if the segment has more than one element
		q = partiton(a, n, p, r) // Partition the array
		qs(a, n, p, q-1)         // Recursively sort the left half
		qs(a, n, q+1, r)         // Recursively sort the right half
	}
}

// Main function
func main() {
	var n int
	var i int
	var v int
	var s string
	var stable int = 1 // Flag to check if the sorting is stable
	var a [200000]card // Arrays to hold the cards for sorting
	var b [200000]card

	// Read the number of cards
	n, _ = strconv.Atoi(os.Args[1])

	// Read the cards into both arrays a and b
	for i = 0; i < n; i++ {
		s = os.Args[2+i*2]
		v, _ = strconv.Atoi(os.Args[3+i*2])
		a[i].s = b[i].s = s[0] // Store the character
		a[i].v = b[i].v = v    // Store the value
	}

	// Perform merge sort on array a
	ms(a[:], n, 0, n)
	// Perform quicksort on array b
	qs(b[:], n, 0, n-1)

	// Check if the sorting is stable by comparing the original and sorted arrays
	for i = 0; i < n; i++ {
		if a[i].s != b[i].s {
			stable = 0 // If any character differs, it's not stable
		}
	}

	// Output the stability result
	if stable == 1 {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}

	// Print the sorted array
	for i = 0; i < n; i++ {
		fmt.Printf("%c %d\n", b[i].s, b[i].v)
	}
}

