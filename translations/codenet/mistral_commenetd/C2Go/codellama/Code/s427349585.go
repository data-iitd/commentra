
package main

import (
	"fmt"
)

// Define a custom data structure 'card' with a character and an integer.
type card struct {
	s byte
	v int
}

// Allocate memory for two arrays L and R, each with size (n+2), where n is the number of input cards.
var L [100000 / 2 + 2]card
var R [100000 / 2 + 2]card

// Function 'me' sorts a subarray of 'a' using merge sort algorithm.
func me(a []card, n, l, m, r int) {
	var i, j, k int
	n1 := m - l // Number of elements to be copied to L array.
	n2 := r - m // Number of elements to be copied to R array.

	// Copy elements from 'a' to L and R arrays.
	for i = 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[m+i]
	}

	// Set the last elements of L and R arrays with a large value to mark the end of each array.
	L[n1].v = R[n2].v = 2000000000

	// Merge sorted subarrays L and R back to 'a'.
	i = 0
	j = 0
	for k = l; k < r; k++ {
		// Compare elements from L and R arrays and copy smaller one to 'a'.
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
func ms(a []card, n, l, r int) {
	var m int
	// Base case: if the subarray has only one element, it is already sorted.
	if l+1 < r {
		// Calculate the middle index 'm' of the subarray.
		m = (l + r) / 2
		// Recursively sort left and right subarrays and then merge them.
		ms(a, n, l, m)
		ms(a, n, m, r)
		// Merge sorted subarrays.
		me(a, n, l, m, r)
	}
}

// Function 'partiton' partitions an array into two parts: one with elements smaller than 'x' and another with elements greater than or equal to 'x'.
func partiton(a []card, n, p, r int) int {
	var i, j int
	x := a[r] // Set 'x' as the last element of the array.
	i = p - 1 // Index of the last element in the left subarray.

	// Iterate through the array from index p to r-1 and swap elements if they are smaller than 'x'.
	for j = p; j < r; j++ {
		if a[j].v <= x.v {
			i++ // Increment index of the last element in the left subarray.
			t := a[i] // Swap elements a[i] and a[j].
			a[i] = a[j]
			a[j] = t
		}
	}
	// Swap the last elements of the left and right subarrays.
	t := a[i+1]
	a[i+1] = a[r]
	a[r] = t
	// Return the index 'i+1' as the pivot index.
	return i + 1
}

// Function 'qs' implements quicksort algorithm to sort the array 'a'.
func qs(a []card, n, p, r int) {
	var q int

	// Base case: if the subarray has only one element, it is already sorted.
	if p < r {
		// Partition the array into two parts using 'partiton' function.
		q = partiton(a, n, p, r)
		// Recursively sort the left and right subarrays.
		qs(a, n, p, q-1)
		qs(a, n, q+1, r)
	}
}

// Main function to read input, sort the array using merge sort and quicksort, and print the sorted array.
func main() {
	var n, i, v int
	var a [200000]card
	var b [200000]card
	var s string
	var stable int = 1

	// Read the number of input cards 'n'.
	fmt.Scan(&n)

	// Read input cards and initialize 'a' and 'b' arrays.
	for i = 0; i < n; i++ {
		fmt.Scan(&s, &v)
		a[i].s = b[i].s = s[0] // Set the character part of 'a' and 'b' equal to the first character of the input string.
		a[i].v = b[i].v = v    // Set the integer part of 'a' and 'b' equal to the integer value of the input card.
	}

	// Merge sort the 'a' array.
	ms(a[:], n, 0, n)

	// Quick sort the 'b' array.
	qs(b[:], n, 0, n-1)

	// Compare 'a' and 'b' arrays to check stability.
	for i = 0; i < n; i++ {
		if a[i].s != b[i].s {
			stable = 0
		}
	}
	// Print the result and the sorted array 'b'.
	if stable == 1 {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}
	// Print the sorted array 'b'.
	for i = 0; i < n; i++ {
		fmt.Printf("%c %d\n", b[i].s, b[i].v)
	}
}

