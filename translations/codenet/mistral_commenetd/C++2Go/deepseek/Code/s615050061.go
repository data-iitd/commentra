package main

import (
	"fmt"
	"math/big"
)

type u64 = *big.Int

const B = "13131" // Base number for exponentiation
const N = 500000 + 7 // Maximum size of input string

var n int // Number of symbols in input string
var s []rune // Input string
var f []*big.Int // Intermediate result array
var g []int // Exponent array
var m map[*big.Int]*big.Int // Map to store intermediate results for faster calculation
var cnt *big.Int // Final result

// Function to calculate B raised to the power of k
func pow(a u64, k *big.Int) *big.Int {
	if k.Sign() < 0 {
		k = new(big.Int).Sub(new(big.Int).Lsh(big.NewInt(1), 63), big.NewInt(1))
		k.Sub(k, big.NewInt(1))
	}
	t := big.NewInt(1) // Initialize result to 1
	for k.Sign() > 0 {
		if new(big.Int).And(k, big.NewInt(1)).Cmp(big.NewInt(1)) == 1 {
			t = new(big.Int).Mul(t, a)
		}
		a = new(big.Int).Mul(a, a)
		k.Rsh(k, 1)
	}
	return t
}

func main() {
	// Read the number of symbols and the input string from standard input
	fmt.Scan(&n)
	var input string
	fmt.Scan(&input)
	s = []rune(input)

	// Initialize the first element of f and g arrays
	f = append(f, big.NewInt(0))
	g = append(g, 0)

	// Process each symbol in the input string
	for i := 1; i <= n; i++ {
		// Update the current element of f array based on the current symbol
		if s[i-1] == '+' || s[i-1] == '-' {
			if s[i-1] == '+' {
				f = append(f, new(big.Int).Add(f[i-1], pow(B, big.NewInt(int64(g[i-1])))))
			} else {
				f = append(f, new(big.Int).Sub(f[i-1], pow(B, big.NewInt(int64(g[i-1])))))
			}
			g = append(g, g[i-1])
		} else {
			f = append(f, f[i-1])
			g = append(g, g[i-1] + (int(s[i-1]) == '<' ? -1 : 1))
		}
	}

	// Initialize the map and final result
	m = make(map[*big.Int]*big.Int)
	cnt = big.NewInt(0)

	// Calculate the final result
	for i := n; i > 0; i-- {
		if _, exists := m[f[i]]; !exists {
			m[f[i]] = big.NewInt(0)
		}
		m[f[i]].Add(m[f[i]], big.NewInt(1))
		cnt.Add(cnt, m[new(big.Int).Add(new(big.Int).Mul(f[n], pow(B, big.NewInt(int64(g[i-1])))), f[i-1])])
	}

	// Print the final result to standard output
	fmt.Println(cnt)
}

