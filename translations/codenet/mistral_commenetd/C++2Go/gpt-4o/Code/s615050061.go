package main

import (
	"fmt"
)

const (
	B = 13131 // Base number for exponentiation
	N = 500000 + 7 // Maximum size of input string
)

var (
	n   int // Number of symbols in input string
	s   [N]rune // Input string
	f   [N]uint64 // Intermediate result array
	g   [N]int // Exponent array
	m   = make(map[uint64]uint64) // Map to store intermediate results for faster calculation
	cnt uint64 // Final result
)

// Function to calculate B raised to the power of k
func pow(a, k uint64) uint64 {
	if k < 0 {
		k += (1 << 63) - 1 // Handle negative exponents by converting them to positive
	}
	t := uint64(1) // Initialize result to 1
	for k > 0 {
		if k&1 == 1 {
			t *= a // If the current bit is 1, multiply the current base to the result
		}
		a *= a // Square the base
		k >>= 1 // Right shift k
	}
	return t // Return the result
}

func main() {
	// Read the number of symbols and the input string from standard input
	fmt.Scan(&n)
	var input string
	fmt.Scan(&input)
	for i, ch := range input {
		s[i+1] = ch // Store the input string in the rune array
	}

	// Initialize the first element of f and g arrays
	f[0] = 0
	g[0] = 0

	// Process each symbol in the input string
	for i := 1; i <= n; i++ {
		// Update the current element of f array based on the current symbol
		if s[i] == '+' || s[i] == '-' {
			if s[i] == '+' {
				f[i] = f[i-1] + pow(B, uint64(g[i-1]))
			} else {
				f[i] = f[i-1] - pow(B, uint64(g[i-1]))
			}
			g[i] = g[i-1]
		} else {
			f[i] = f[i-1]
			if s[i] == '<' {
				g[i] = g[i-1] - 1
			} else {
				g[i] = g[i-1] + 1
			}
		}
	}

	// Calculate the final result
	for i := n; i > 0; i-- {
		m[f[i]]++ // Increment the count of the intermediate result in the map
		cnt += m[f[n]*pow(B, uint64(g[i-1]))+f[i-1]] // Add the contribution of the current symbol to the final result
	}

	fmt.Println(cnt) // Print the final result to standard output
}

// <END-OF-CODE>
