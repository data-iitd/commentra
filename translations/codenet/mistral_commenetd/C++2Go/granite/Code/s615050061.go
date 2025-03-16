

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

const (
	B = 13131 // Base number for exponentiation
	N = 500000 + 7 // Maximum size of input string
)

var (
	n int // Number of symbols in input string
	s string // Input string
	f [N]int64 // Intermediate result array
	g [N]int // Exponent array
	m = make(map[int64]int) // Map to store intermediate results for faster calculation
	cnt int64 // Final result
)

// Function to calculate B raised to the power of k
func pow(a, k int64) int64 {
	if k < 0 {
		k += (1 << 63) - 1 // Handle negative exponents by converting them to positive
	}
	t := int64(1) // Initialize result to 1
	for ; k > 0; a = a * a, k >>= 1 { // Calculate exponentiation using bitwise right shift and multiplication
		if k&1 == 1 {
			t = t * a // If the current bit is 1, add the current base to the result
		}
	}
	return t // Return the result
}

func main() {
	reader := bufio.NewReader(os.Stdin) // Create a reader for standard input
	fmt.Fscanf(reader, "%d", &n) // Read the number of symbols and the input string from standard input
	s, _ = reader.ReadString('\n') // Read the input string until a newline character is encountered
	s = strings.TrimSpace(s) // Remove leading and trailing whitespace from the input string

	// Initialize the first element of f and g arrays
	f[0] = 0
	g[0] = 0

	// Process each symbol in the input string
	for i := 1; i <= n; i++ {
		// Update the current element of f array based on the current symbol
		if s[i-1] == '+' || s[i-1] == '-' {
			f[i] = f[i-1] + (1 - 2*(s[i-1]-'+'))*int64(pow(B, int64(g[i-1]))) // Update the current element of f array based on the current symbol
		} else {
			f[i] = f[i-1]
			g[i] = g[i-1] + (1 - 2*(s[i-1]-'<'))
		}
	}

	// Calculate the final result
	for i := n; i > 0; i-- {
		m[f[i]]++ // Increment the count of the intermediate result in the map
		cnt += int64(m[f[n]*pow(B, int64(g[i-1]))+f[i-1]]) // Add the contribution of the current symbol to the final result
	}

	fmt.Println(cnt) // Print the final result to standard output
}

