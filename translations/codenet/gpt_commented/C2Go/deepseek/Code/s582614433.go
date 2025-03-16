package main

import (
	"fmt"
	"sort"
	"strconv"
)

// Define long long type for convenience
type ll int64

// Macro for iterating from l to r
func rep(l, r ll) []ll {
	var result []ll
	for i := l; i < r; i++ {
		result = append(result, i)
	}
	return result
}

// Macro for iterating from l to r with step k
func repp(l, r, k ll) []ll {
	var result []ll
	for i := l; i < r; i += k {
		result = append(result, i)
	}
	return result
}

// Define a large constant for infinity
const INF = 9223372036854775807

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
func upll(a, b interface{}) int {
	ai := a.(ll)
	bi := b.(ll)
	if ai < bi {
		return -1
	}
	if ai > bi {
		return 1
	}
	return 0
}

// Comparison function for sorting in descending order
func downll(a, b interface{}) int {
	ai := a.(ll)
	bi := b.(ll)
	if ai < bi {
		return 1
	}
	if ai > bi {
		return -1
	}
	return 0
}

// Function to sort an array in ascending order
func sortup(a []ll) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

// Function to sort an array in descending order
func sortdown(a []ll) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

// Function to compute (a^n) % m using modular exponentiation
func pom(a, n, m ll) ll {
	a %= m
	x := ll(1)
	for n > 0 {
		if n%2 == 1 {
			x = x * a % m
		}
		a = a * a % m
		n /= 2
	}
	return x
}

// Define a large prime number for modulo operations
const MOD = 1000000007

// Macro to compute modular inverse using Fermat's little theorem
func invp(a, p ll) ll {
	return pom(a, p-2, p)
}

// Structure to hold edge information
type Edge struct {
	p ll
	i ll
	s string
}

// Comparison function for sorting edges
func esort(a, b interface{}) int {
	ea := a.(Edge)
	eb := b.(Edge)
	// First compare by string identifier
	if ea.s < eb.s {
		return -1
	}
	if ea.s > eb.s {
		return 1
	}
	// If identifiers are the same, compare by weight in descending order
	if ea.p < eb.p {
		return 1
	}
	return -1
}

// Array to hold edge data
var data []Edge

func main() {
	// Read the number of edges
	var n ll
	fmt.Scan(&n)
	
	// Read edge data from input
	data = make([]Edge, n)
	for i := range data {
		fmt.Scan(&data[i].s, &data[i].p)
		data[i].i = i + 1 // Store the original index
	}
	
	// Sort the edges based on the defined sorting criteria
	sort.Slice(data, func(i, j int) bool {
		return esort(data[i], data[j]) < 0
	})
	
	// Output the original indices of the sorted edges
	for _, edge := range data {
		fmt.Println(edge.i)
	}
}

