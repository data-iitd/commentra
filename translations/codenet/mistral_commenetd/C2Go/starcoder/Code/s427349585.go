
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Define a custom data structure 'card' with a character and an integer.
type card struct {
	s string
	v int
}

// Function'me' sorts a subarray of 'a' using merge sort algorithm.
func me(a []card, l, m, r int) {
<<<<<<< HEAD
	var i, j, k int
	var n1, n2 int
	n1 = m - l
	n2 = r - m
	var L, R []card

	// Copy elements from 'a' to L and R arrays.
	L = make([]card, n1)
	R = make([]card, n2)
	for i = 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[m+i]
	}

	// Set the last elements of L and R arrays with a large value to mark the end of each array.
	L[n1].v = 2000000000
	R[n2].v = 2000000000

	// Merge sorted subarrays L and R back to 'a'.
	i = 0
	j = 0
	for k = l; k < r; k++ {
		// Compare elements from L and R arrays and copy smaller one to 'a'.
=======
	n1 := m - l
	n2 := r - m
	L := make([]card, n1+2)
	R := make([]card, n2+2)
	for i := 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i := 0; i < n2; i++ {
		R[i] = a[m+i]
	}
	L[n1].v = 2000000000
	R[n2].v = 2000000000
	i := 0
	j := 0
	for k := l; k < r; k++ {
>>>>>>> 98c87cb78a (data updated)
		if L[i].v <= R[j].v {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
		}
	}
}

// Recursive function'ms' to merge sort the entire array 'a'.
<<<<<<< HEAD
func ms(a []card, n, l, r int) {
	var m int
	// Base case: if the subarray has only one element, it is already sorted.
	if l+1 < r {
		// Calculate the middle index'm' of the subarray.
		m = (l + r) / 2
		// Recursively sort left and right subarrays and then merge them.
		ms(a, n, l, m)
		ms(a, n, m, r)
		// Merge sorted subarrays.
=======
func ms(a []card, l, r int) {
	if l+1 < r {
		m := (l + r) / 2
		ms(a, l, m)
		ms(a, m, r)
>>>>>>> 98c87cb78a (data updated)
		me(a, l, m, r)
	}
}

// Function 'partiton' partitions an array into two parts: one with elements smaller than 'x' and another with elements greater than or equal to 'x'.
func partiton(a []card, p, r int) int {
<<<<<<< HEAD
	var i, j int
	var t, x card
	x = a[r] // Set 'x' as the last element of the array.
	i = p - 1 // Index of the last element in the left subarray.

	// Iterate through the array from index p to r-1 and swap elements if they are smaller than 'x'.
	for j = p; j < r; j++ {
		if a[j].v <= x.v {
			i++ // Increment index of the last element in the left subarray.
			t = a[i] // Swap elements a[i] and a[j].
			a[i] = a[j]
			a[j] = t
		}
	}
	// Swap the last elements of the left and right subarrays.
	t = a[i+1]
	a[i+1] = a[r]
	a[r] = t
	// Return the index 'i+1' as the pivot index.
=======
	i := p - 1
	x := a[r]
	for j := p; j < r; j++ {
		if a[j].v <= x.v {
			i++
			a[i], a[j] = a[j], a[i]
		}
	}
	a[i+1], a[r] = a[r], a[i+1]
>>>>>>> 98c87cb78a (data updated)
	return i + 1
}

// Function 'qs' implements quicksort algorithm to sort the array 'a'.
<<<<<<< HEAD
func qs(a []card, n, p, r int) {
	var q int
	// Base case: if the subarray has only one element, it is already sorted.
	if p < r {
		// Partition the array into two parts using 'partiton' function.
		q = partiton(a, p, r)
		// Recursively sort the left and right subarrays.
		qs(a, n, p, q-1)
		qs(a, n, q+1, r)
=======
func qs(a []card, p, r int) {
	if p < r {
		q := partiton(a, p, r)
		qs(a, p, q-1)
		qs(a, q+1, r)
>>>>>>> 98c87cb78a (data updated)
	}
}

// Main function to read input, sort the array using merge sort and quicksort, and print the sorted array.
func main() {
<<<<<<< HEAD
	var n, i, v int
	var a, b []card
	var s string
	var stable int = 1

	// Read the number of input cards 'n'.
	fmt.Scanf("%d", &n)

	// Read input cards and initialize 'a' and 'b' arrays.
	a = make([]card, n)
	b = make([]card, n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%s%d", &s, &v)
		a[i].s = s[0] // Set the character part of 'a' and 'b' equal to the first character of the input string.
		a[i].v = v    // Set the integer part of 'a' and 'b' equal to the integer value of the input card.
		b[i].s = s[0]
		b[i].v = v
	}

	// Merge sort the 'a' array.
	ms(a, n, 0, n)

	// Quick sort the 'b' array.
	qs(b, n, 0, n-1)

	// Compare 'a' and 'b' arrays to check stability.
	for i = 0; i < n; i++ {
		if a[i].s!= b[i].s {
			stable = 0
		}
	}
	// Print the result and the sorted array 'b'.
	if stable == 1 {
=======
	var n int
	var a, b []card
	var s string
	var v int
	var stable bool
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%s %d", &s, &v)
		a = append(a, card{s[0], v})
		b = append(b, card{s[0], v})
	}
	ms(a, 0, n)
	qs(b, 0, n-1)
	stable = true
	for i := 0; i < n; i++ {
		if a[i].s!= b[i].s {
			stable = false
		}
	}
	if stable {
>>>>>>> 98c87cb78a (data updated)
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}
<<<<<<< HEAD
	// Print the sorted array 'b'.
	for i = 0; i < n; i++ {
=======
	for i := 0; i < n; i++ {
>>>>>>> 98c87cb78a (data updated)
		fmt.Printf("%s %d\n", b[i].s, b[i].v)
	}
}

