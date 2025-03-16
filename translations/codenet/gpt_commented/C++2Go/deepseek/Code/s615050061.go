package main

import (
	"fmt"
	"math"
)

// Define constants for base and maximum size
const B = 13131
const N = 500000 + 7

// Declare global variables
var n int // Length of the input string
var s = make([]byte, N) // Input string
var f = make([]uint64, N) // Array to store computed values based on the input string
var g = make([]int, N) // Array to store the shift values
var m = make(map[uint64]uint64) // Map to count occurrences of computed values
var cnt uint64 // Counter for the final result

// Function to compute power of a number with a given exponent
func pow(a, k uint64) uint64 {
	// Adjust exponent if negative
	if k < 0 {
		k += (1 << 63) - 1
	}
	t := uint64(1) // Initialize result
	// Exponentiation by squaring
	for ; k > 0; a *= a {
		if k & 1 == 1 {
			t *= a
		}
		k >>= 1
	}
	return t // Return computed power
}

func main() {
	// Uncomment the following lines to read from a file
	// freopen("code.in", "r", stdin);
	// freopen("code.out", "w", stdout);

	// Read input values: number of operations and the operations string
	fmt.Scanf("%d%s", &n, s[1:])
	
	// Process each character in the input string
	for i := 1; i <= n; i++ {
		// If the character is '+' or '-', update f and g arrays
		if s[i] == '+' || s[i] == '-' {
			f[i] = f[i-1] + uint64(math.Pow(float64(B), float64(g[i] = g[i-1]))) * (1 if s[i] == '+' else -1)
		} else {
			// If the character is '<' or '>', update f and g arrays accordingly
			f[i] = f[i-1] // No change in f
			g[i] = g[i-1] + (1 if s[i] == '<' else -1) // Update g based on direction
		}
	}

	// Iterate backwards through the string to count valid combinations
	for i := n; i > 0; i-- {
		m[f[i]]++ // Increment the count of the current f value
		// Update the counter with the number of valid combinations found
		cnt += m[f[n] * pow(B, uint64(g[i-1])) + f[i-1]]
	}

	// Output the final count of valid combinations
	fmt.Println(cnt)
}
