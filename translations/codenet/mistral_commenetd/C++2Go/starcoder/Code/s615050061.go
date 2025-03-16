
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Base number for exponentiation
const B = 13131

// Maximum size of input string
const N = 500000 + 7

var (
	n int
	s [N]byte
	f [N]uint64
	g [N]int
	m map[uint64]uint64
	cnt uint64
)

// Function to calculate B raised to the power of k
func pow(a uint64, k int) uint64 {
	if k < 0 {
		k += int(math.MaxUint64) // Handle negative exponents by converting them to positive
	}
	t := uint64(1) // Initialize result to 1
	for ; k > 0; a = a * a {
		if k&1 == 1 {
<<<<<<< HEAD
			t = t * a
=======
			t *= a
>>>>>>> 98c87cb78a (data updated)
		}
		k >>= 1
	}
	return t
}

func main() {
//	fmt.Scanf("%d%s", &n, s[1:]) // Uncomment to read input from a file
//	fmt.Printf("%d\n", cnt) // Uncomment to write output to a file

	fmt.Scanf("%d%s", &n, s[1:]) // Read the number of symbols and the input string from standard input

	// Initialize the first element of f and g arrays
	f[0] = 0
	g[0] = 0

	// Process each symbol in the input string
	for i := 1; i <= n; i++ {
		// Update the current element of f array based on the current symbol
		if s[i] == '+' || s[i] == '-' {
<<<<<<< HEAD
			f[i] = f[i - 1] + uint64(s[i] == '+'? 1 : -1) * pow(B, g[i] = g[i - 1])
=======
			f[i] = f[i - 1] + (s[i] == '+'? 1 : -1) * pow(B, g[i] = g[i - 1])
>>>>>>> 98c87cb78a (data updated)
		} else {
			f[i] = f[i - 1]
			g[i] = g[i - 1] + (s[i] == '<'? -1 : 1)
		}
	}

	// Calculate the final result
	for i := n; i > 0; i-- {
		m[f[i]]++ // Increment the count of the intermediate result in the map
		cnt += m[f[n] * pow(B, g[i - 1]) + f[i - 1]] // Add the contribution of the current symbol to the final result
	}

	fmt.Printf("%d\n", cnt) // Print the final result to standard output
}

