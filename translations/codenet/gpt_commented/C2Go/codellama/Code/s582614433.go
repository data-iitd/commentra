
package main

import (
	"fmt"
	"sort"
	"strconv"
)

// Define long long type for convenience
type ll int64

// Macro for iterating from l to r
func rep(i, l, r ll) {
	for i = l; i < r; i++ {
	}
}

// Macro for iterating from l to r with step k
func repp(i, l, r, k ll) {
	for i = l; i < r; i += k {
	}
}

// Define a large constant for infinity
const INF = (1 << 62) - (1 << 31)

// Macro to get the maximum of two values
func max(p, q ll) ll {
	if p > q {
		return p
	}
	return q
}

// Macro to get the minimum of two values
func min(p, q ll) ll {
	if p < q {
		return p
	}
	return q
}

// Macro to check the bit at position m in n
func bit(n, m ll) ll {
	return (n >> m) & 1
}

// Comparison function for sorting in ascending order
func upll(a, b ll) int {
	if a < b {
		return -1
	}
	if a > b {
		return 1
	}
	return 0
}

// Comparison function for sorting in descending order
func downll(a, b ll) int {
	if a < b {
		return 1
	}
	if a > b {
		return -1
	}
	return 0
}

// Function to sort an array in ascending order
func sortup(a []ll, n ll) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

// Function to sort an array in descending order
func sortdown(a []ll, n ll) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

// Function to compute (a^n) % m using modular exponentiation
func pom(a, n, m ll) ll {
	x := 1 // Initialize result
	for a %= m; n > 0; n /= 2 { // Loop until n is zero
		if n&1 == 1 { // If n is odd, multiply x by a
			x = x * a % m
		}
		a = a * a % m // Square a
	}
	return x // Return the result
}

// Define a large prime number for modulo operations
const MOD = 1000000007

// Macro to compute modular inverse using Fermat's little theorem
func invp(a, p ll) ll {
	return pom(a, p-2, p)
}

// Structure to hold edge information
type E struct {
	p ll // Weight or value associated with the edge
	i ll // Index of the edge
	s string // Name or identifier of the edge
}

// Comparison function for sorting edges
func esort(a, b E) int {
	// First compare by string identifier
	if a.s < b.s {
		return -1
	}
	if a.s > b.s {
		return 1
	}
	// If identifiers are the same, compare by weight in descending order
	if a.p < b.p {
		return 1
	}
	return -1 // Otherwise, return -1 for sorting
}

// Array to hold edge data
var data []E
var n, m ll // Variables to hold the number of edges and other data

func main() {
	// Read the number of edges
	fmt.Scan(&n)

	// Read edge data from input
	data = make([]E, n)
	rep(i, 0, n) {
		fmt.Scan(&data[i].s, &data[i].p) // Read string and weight
		data[i].i = i                    // Store the original index
	}

	// Sort the edges based on the defined sorting criteria
	sort.Slice(data, func(i, j int) bool {
		return esort(data[i], data[j]) < 0
	})

	// Output the original indices of the sorted edges
	rep(i, 0, n) {
		fmt.Println(data[i].i + 1)
	}
}

