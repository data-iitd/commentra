
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define a structure to represent a card with a character and an integer value
type card struct {
	s string // Character representing the card's suit or type
	v int    // Integer representing the card's value
}

// Merge function to combine two sorted halves of the array
func me(a []card, n int, l int, m int, r int) {
	var i, j, k int
	n1 := m - l // Size of the left half
	n2 := r - m // Size of the right half

	// Copy data to temporary arrays L and R
	L := make([]card, n1+1)
	R := make([]card, n2+1)
	for i = 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[m+i]
	}

	// Sentinel values to avoid out-of-bounds access
	L[n1].v = R[n2].v = 20000000000
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
		ms(a, n, l, m) // Sort the left half
		ms(a, n, m, r) // Sort the right half
		me(a, n, l, m, r) // Merge the sorted halves
	}
}

// Partition function for quicksort
func partiton(a []card, n int, p int, r int) int {
	var i, j int
	t := a[r] // Choose the last element as the pivot
	i = p - 1 // Index of smaller element
	for j = p; j < r; j++ {
		if a[j].v <= t.v { // If current element is smaller than or equal to pivot
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
func qs(a []card, n int, p int, r int) {
	var q int
	if p < r { // Base case: if the segment has more than one element
		q = partiton(a, n, p, r) // Partition the array
		qs(a, n, p, q-1) // Recursively sort the left half
		qs(a, n, q+1, r) // Recursively sort the right half
	}
}

// Main function
func main() {
	var n, i, v int
	var s string
	var stable int = 1 // Flag to check if the sorting is stable
	a := make([]card, 200000) // Array to hold the cards for sorting
	b := make([]card, 200000) // Array to hold the cards for sorting

	// Read the number of cards
	fmt.Scan(&n)

	// Read the cards into both arrays a and b
	for i = 0; i < n; i++ {
		fmt.Scan(&s, &v)
		a[i].s = b[i].s = s[0] // Store the character
		a[i].v = b[i].v = v // Store the value
	}

	// Perform merge sort on array a
	ms(a, n, 0, n)
	// Perform quicksort on array b
	qs(b, n, 0, n-1)

	// Check if the sorting is stable by comparing the original and sorted arrays
	for i = 0; i < n; i++ {
		if a[i].s!= b[i].s {
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
		fmt.Printf("%s %d\n", b[i].s, b[i].v)
	}
}

// Read the number of cards
fmt.Scan(&n)

// Read the cards into both arrays a and b
for i = 0; i < n; i++ {
	fmt.Scan(&s, &v)
	a[i].s = b[i].s = s[0] // Store the character
	a[i].v = b[i].v = v // Store the value
}

// Perform merge sort on array a
ms(a, n, 0, n)
// Perform quicksort on array b
qs(b, n, 0, n-1)

// Check if the sorting is stable by comparing the original and sorted arrays
for i = 0; i < n; i++ {
	if a[i].s!= b[i].s {
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
	fmt.Printf("%s %d\n", b[i].s, b[i].v)
}

// Read the number of cards
fmt.Scan(&n)

// Read the cards into both arrays a and b
for i = 0; i < n; i++ {
	fmt.Scan(&s, &v)
	a[i].s = b[i].s = s[0] // Store the character
	a[i].v = b[i].v = v // Store the value
}

// Perform merge sort on array a
ms(a, n, 0, n)
// Perform quicksort on array b
qs(b, n, 0, n-1)

// Check if the sorting is stable by comparing the original and sorted arrays
for i = 0; i < n; i++ {
	if a[i].s!= b[i].s {
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
	fmt.Printf("%s %d\n", b[i].s, b[i].v)
}

// Read the number of cards
fmt.Scan(&n)

// Read the cards into both arrays a and b
for i = 0; i < n; i++ {
	fmt.Scan(&s, &v)
	a[i].s = b[i].s = s[0] // Store the character
	a[i].v = b[i].v = v // Store the value
}

// Perform merge sort on array a
ms(a, n, 0, n)
// Perform quicksort on array b
qs(b, n, 0, n-1)

// Check if the sorting is stable by comparing the original and sorted arrays
for i = 0; i < n; i++ {
	if a[i].s!= b[i].s {
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
	fmt.Printf("%s %d\n", b[i].s, b[i].v)
}

// Read the number of cards
fmt.Scan(&n)

// Read the cards into both arrays a and b
for i = 0; i < n; i++ {
	fmt.Scan(&s, &v)
	a[i].s = b[i].s = s[0] // Store the character
	a[i].v = b[i].v = v // Store the value
}

// Perform merge sort on array a
ms(a, n, 0, n)
// Perform quicksort on array b
qs(b, n, 0, n-1)

// Check if the sorting is stable by comparing the original and sorted arrays
for i = 0; i < n; i++ {
	if a[i].s!= b[i].s {
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
	fmt.Printf("%s %d\n", b[i].s, b[i].v)
}

// Read the number of cards
fmt.Scan(&n)

// Read the cards into both arrays a and b
for i = 0; i < n; i++ {
	fmt.Scan(&s, &v)
	a[i].s = b[i].s = s[0] // Store the character
	a[i].v = b[i].v = v // Store the value
}

// Perform merge sort on array a
ms(a, n, 0, n)
// Perform quicksort on array b
qs(b, n, 0, n-1)

// Check if the sorting is stable by comparing the original and sorted arrays
for i = 0; i < n; i++ {
	if a[i].s!= b[i].s {
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
	fmt.Printf("%s %d\n", b[i].s, b[i].v)
}

// Read the number of cards
fmt.Scan(&n)

// Read the cards into both arrays a and b
for i = 0; i < n; i++ {
	fmt.Scan(&s, &v)
	a[i].s = b[i].s = s[0] // Store the character
	a[i].v = b[i].v = v // Store the value
}

// Perform merge sort on array a
ms(a, n, 0, n)
// Perform quicksort on array b
qs(b, n, 0, n-1)

// Check if the sorting is stable by comparing the original and sorted arrays
for i = 0; i < n; i++ {
	if a[i].s!= b[i].s {
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
	fmt.Printf("%s %d\n", b[i].s, b[i].v)
}

// Read the number of cards
fmt.Scan(&n)

// Read the cards into both arrays a and b
for i = 0; i < n; i++ {
	fmt.Scan(&s, &v)
	a[i].s = b[i].s = s[0] // Store the character
	a[i].v = b[i].v = v // Store the value
}

// Perform merge sort on array a
ms(a, n, 0, n)
// Perform quicksort on array b
qs(b, n, 0, n-1)

// Check if the sorting is stable by comparing the original and sorted arrays
for i = 0; i < n; i++ {
	if a[i].s!= b[i].s {
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
	fmt.Printf("%s %d\n", b[i].s, b[i].v)
}

// Read the number of cards
fmt.Scan(&n)

// Read the cards into both arrays a and b
for i = 0; i < n; i++ {
	fmt.Scan(&s, &v)
	a[i].s = b[i].s = s[0] // Store the character
	a[i].v = b[i].v = v // Store the value
}

// Perform merge sort on array a
ms(a, n, 0, n)
// Perform quicksort on array b
qs(b, n, 0, n-1)

// Check if the sorting is stable by comparing the original and sorted arrays
for i = 0; i < n; i++ {
	if a[i].s!= b[i].s {
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
	fmt.Printf("%s %d\n", b[i].s, b[i].v)
}

// Read the number of cards
fmt.Scan(&n)

// Read the cards into both arrays a and b
for i = 0; i < n; i++ {
	fmt.Scan(&s, &v)
	a[i].s = b[i].s = s[0] // Store the character
	a[i].v = b[i].v = v // Store the value
}

// Perform merge sort on array a
ms(a, n, 0, n)
// Perform quicksort on array b
qs(b, n, 0, n-1)

// Check if the sorting is stable by comparing the original and sorted arrays
for i = 0; i < n; i++ {
	if a[i].s!= b[i].s {
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
	fmt.Printf("%s %d\n", b[i].s, b[i].v)
}

// Read the number of cards
fmt.Scan(&n)

// Read the cards into both arrays a and b
for i = 0; i < n; i++ {
	fmt.Scan(&s, &v)
	a[i].s = b[i].s = s[0] // Store the character
	a[i].v = b[i].v = v // Store the value
}

// Perform merge sort on array a
ms(a, n, 0, n)
// Perform quicksort on array b
qs(b, n, 0, n-1)

// Check if the sorting is stable by comparing the original and sorted arrays
for i = 0; i < n;