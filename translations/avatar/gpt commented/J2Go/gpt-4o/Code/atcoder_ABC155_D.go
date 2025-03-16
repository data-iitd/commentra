package main

import (
	"fmt"
	"sort"
)

const mod = 1e9 + 7

var n int
var k int64
var a []int64

func main() {
	// Initialize scanner for input
	var err error
	_, err = fmt.Scan(&n, &k)
	if err != nil {
		return
	}

	// Initialize the array to hold the long integers
	a = make([]int64, n)

	// Read the elements into the array
	for i := 0; i < n; i++ {
		_, err = fmt.Scan(&a[i])
		if err != nil {
			return
		}
	}

	// Sort the array to facilitate binary search
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})

	// Define a large value for infinity
	var INF int64 = 1e18 + 1

	// Set the initial bounds for binary search
	l, r := -INF, INF

	// Perform binary search to find the maximum value satisfying the condition
	for l+1 < r {
		c := (l + r) / 2
		if check(c) {
			l = c // If check returns true, move the lower bound up
		} else {
			r = c // Otherwise, move the upper bound down
		}
	}

	// Output the result
	fmt.Println(l)
}

// Function to check if a certain value x can be achieved
func check(x int64) bool {
	tot := int64(0) // Total count of valid pairs

	// Iterate through each element in the array
	for i := 0; i < n; i++ {
		now := a[i] // Current element
		l, r := 0, n // Initialize binary search bounds

		// If the current element is non-negative
		if now >= 0 {
			// Perform binary search to count valid pairs
			for l < r {
				c := (l + r) / 2
				if now*a[c] < x {
					l = c + 1 // Move right if the product is less than x
				} else {
					r = c // Move left otherwise
				}
			}
			tot += int64(l) // Add the count of valid pairs
		} else {
			// If the current element is negative
			for l < r {
				c := (l + r) / 2
				if now*a[c] >= x {
					l = c + 1 // Move right if the product is greater than or equal to x
				} else {
					r = c // Move left otherwise
				}
			}
			tot += int64(n - l) // Count valid pairs with negative current element
		}

		// Adjust total count if the product of the element with itself is less than x
		if now*now < x {
			tot--
		}
	}

	// Return true if the total count of pairs is less than k
	return tot/2 < k
}

// <END-OF-CODE>
