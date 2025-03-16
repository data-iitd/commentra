package main

import (
	"fmt"
	"sort"
)

const mod = 1e9 + 7 // Define constant for modulo operation.

var DX = []int{-1, 0, 1, 0}
var DY = []int{0, -1, 0, 1}

var n int       // Declare variable for the size of the array.
var k int64     // Declare variable for the target value.
var a []int64   // Declare array to store the values.

func main() {
	var INF int64 = 1e18 + 1 // Define a large number as infinity.
	
	fmt.Scan(&n) // Read the size of the array.
	fmt.Scan(&k) // Read the target value.
	a = make([]int64, n) // Initialize the array.

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read the elements of the array.
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	}) // Sort the array.

	l, r := -INF, INF // Initialize the boundaries of the search.

	for l+1 < r { // Perform binary search.
		c := (l + r) / 2 // Calculate the middle point.
		if check(c) {
			l = c // Adjust the left boundary.
		} else {
			r = c // Adjust the right boundary.
		}
	}

	fmt.Println(l) // Print the result.
}

func check(x int64) bool {
	tot := int64(0) // Initialize the total count.

	for i := 0; i < n; i++ {
		now := a[i] // Get the current element.
		l, r := 0, n // Initialize the boundaries for binary search.

		if now >= 0 { // If the current element is non-negative.
			for l < r { // Perform binary search.
				c := (l + r) / 2
				if now*a[c] < x {
					l = c + 1 // Adjust the left boundary.
				} else {
					r = c // Adjust the right boundary.
				}
			}
			tot += int64(l) // Add the result to the total.
		} else { // If the current element is negative.
			for l < r { // Perform binary search.
				c := (l + r) / 2
				if now*a[c] >= x {
					l = c + 1 // Adjust the left boundary.
				} else {
					r = c // Adjust the right boundary.
				}
			}
			tot += int64(n - l) // Add the result to the total.
		}

		if now*now < x {
			tot-- // Adjust the total if necessary.
		}
	}

	return tot/2 < k // Return true if the count is less than k.
}

// <END-OF-CODE>
