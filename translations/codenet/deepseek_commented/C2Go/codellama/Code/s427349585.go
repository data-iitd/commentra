
package main

import (
	"fmt"
	"sort"
)

// Define the card structure
type card struct {
	s string
	v int
}

// Define arrays for left and right subarrays
var L [100000 / 2 + 2]card
var R [100000 / 2 + 2]card

// Merge function to merge two subarrays
func me(a []card, n, l, m, r int) {
	var i, j, k int
	n1 := m - l
	n2 := r - m

	// Copy elements to left and right subarrays
	for i = 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i = 0; i < n2; i++ {
		R[i] = a[m+i]
	}

	// Sentinel values to avoid checking for array boundaries
	L[n1].v = R[n2].v = 2000000000

	i = 0
	j = 0

	// Merge the two subarrays back into the original array
	for k = l; k < r; k++ {
		if L[i].v <= R[j].v {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
		}
	}
}

// Merge sort function to sort the array
func ms(a []card, n, l, r int) {
	var m int
	if l+1 < r {
		m = (l + r) / 2
		ms(a, n, l, m)
		ms(a, n, m, r)
		me(a, n, l, m, r)
	}
}

// Partition function to partition the array around a pivot
func partition(a []card, n, p, r int) int {
	var i, j int
	var t card
	x := a[r]
	i = p - 1
	for j = p; j < r; j++ {
		if a[j].v <= x.v {
			i++
			t = a[i]
			a[i] = a[j]
			a[j] = t
		}
	}
	t = a[i+1]
	a[i+1] = a[r]
	a[r] = t
	return i + 1
}

// Quick sort function to sort the array
func qs(a []card, n, p, r int) {
	var q int
	if p < r {
		q = partition(a, n, p, r)
		qs(a, n, p, q-1)
		qs(a, n, q+1, r)
	}
}

// Main function to read input, sort the arrays, check for stability, and print the result
func main() {
	var n, i, v int
	var a [200000]card
	var b [200000]card
	var s string
	var stable int = 1

	// Read the number of cards
	fmt.Scan(&n)

	// Read each card's suit and value
	for i = 0; i < n; i++ {
		fmt.Scan(&s, &v)
		a[i].s = b[i].s = s
		a[i].v = b[i].v = v
	}

	// Sort the array using merge sort
	ms(a[:], n, 0, n)

	// Sort the array using quick sort
	qs(b[:], n, 0, n-1)

	// Check if the sorting is stable
	for i = 0; i < n; i++ {
		if a[i].s != b[i].s {
			stable = 0
		}
	}

	// Print the stability status
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

