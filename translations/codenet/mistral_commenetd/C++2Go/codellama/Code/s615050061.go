
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	B = 13131 // Base number for exponentiation
	N = 500000 + 7 // Maximum size of input string
)

var (
	n int // Number of symbols in input string
	s []byte // Input string
	f []int64 // Intermediate result array
	g []int64 // Exponent array
	map map[int64]int64 // Map to store intermediate results for faster calculation
	cnt int64 // Final result
)

// Function to calculate B raised to the power of k
func pow(a, k int64) int64 {
	if k < 0 { k += (1 << 63) - 1 } // Handle negative exponents by converting them to positive
	t := int64(1) // Initialize result to 1
	for ; k > 0; a *= a, k >>= 1 { // Calculate exponentiation using bitwise right shift and multiplication
		if k & 1 == 1 { t *= a } // If the current bit is 1, add the current base to the result
	}
	return t // Return the result
}

func main() {
//	freopen("code.in", "r", stdin); // Uncomment to read input from a file
//	freopen("code.out", "w", stdout); // Uncomment to write output to a file

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d%s", &n, &s) // Read the number of symbols and the input string from standard input

	// Initialize the first element of f and g arrays
	f = make([]int64, N)
	g = make([]int64, N)
	f[0] = 0
	g[0] = 0

	// Process each symbol in the input string
	for i := 1; i <= n; i++ {
		// Update the current element of f array based on the current symbol
		if s[i] == '+' || s[i] == '-' {
			f[i] = f[i - 1] + (s[i] == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1])
		} else {
			f[i] = f[i - 1]
			g[i] = g[i - 1] + (s[i] == '<' ? -1 : 1)
		}
	}

	// Calculate the final result
	map = make(map[int64]int64)
	for i := n; i > 0; i-- {
		map[f[i]]++
		cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]]
	}

	fmt.Println(cnt) // Print the final result to standard output
}

