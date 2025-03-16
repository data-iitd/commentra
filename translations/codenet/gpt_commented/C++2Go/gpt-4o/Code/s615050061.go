package main

import (
	"fmt"
)

const (
	B = 13131
	N = 500000 + 7
)

var (
	n   int
	s   [N]rune
	f   [N]uint64
	g   [N]int
	m   = make(map[uint64]uint64)
	cnt uint64
)

// Function to compute power of a number with a given exponent
func pow(a, k uint64) uint64 {
	if k < 0 {
		k += (1 << 63) - 1
	}
	t := uint64(1)
	for k > 0 {
		if k&1 == 1 {
			t *= a
		}
		a *= a
		k >>= 1
	}
	return t
}

func main() {
	// Read input values: number of operations and the operations string
	fmt.Scan(&n)
	var input string
	fmt.Scan(&input)

	for i := 1; i <= n; i++ {
		s[i] = rune(input[i-1]) // Convert to rune and store in s
		if s[i] == '+' || s[i] == '-' {
			f[i] = f[i-1] + (func() int {
				if s[i] == '+' {
					return 1
				}
				return -1
			}()) * pow(B, uint64(g[i-1]))
			g[i] = g[i-1]
		} else {
			f[i] = f[i-1] // No change in f
			if s[i] == '<' {
				g[i] = g[i-1] - 1 // Update g based on direction
			} else {
				g[i] = g[i-1] + 1
			}
		}
	}

	// Iterate backwards through the string to count valid combinations
	for i := n; i > 0; i-- {
		m[f[i]]++ // Increment the count of the current f value
		// Update the counter with the number of valid combinations found
		cnt += m[f[n]*pow(B, uint64(g[i-1]))+f[i-1]]
	}

	// Output the final count of valid combinations
	fmt.Println(cnt)
}

// <END-OF-CODE>
