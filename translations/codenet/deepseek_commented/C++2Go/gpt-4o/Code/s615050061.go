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

// pow function to calculate a^k using binary exponentiation
func pow(a, k uint64) uint64 {
	if k < 0 {
		k += (1 << 63) - 1 // Handle negative exponents
	}
	t := uint64(1) // Initialize the result to 1
	for k > 0 {
		if k&1 == 1 {
			t *= a // If the exponent is odd, multiply the result
		}
		a *= a // Square the base
		k >>= 1 // Halve the exponent
	}
	return t // Return the result
}

func main() {
	// Uncomment the following lines if you want to read from a file and write to a file
	// input, _ := os.Open("code.in")
	// defer input.Close()
	// output, _ := os.Create("code.out")
	// defer output.Close()

	fmt.Scanf("%d\n", &n) // Read the input values for n
	var str string
	fmt.Scanf("%s", &str) // Read the string s
	for i := 1; i <= n; i++ {
		s[i] = rune(str[i-1]) // Convert string to rune array
		if s[i] == '+' || s[i] == '-' {
			f[i] = f[i-1] + (uint64(1)*(s[i] == '+') - uint64(1)*(s[i] == '-'))*pow(B, uint64(g[i-1]))
			g[i] = g[i-1]
		} else {
			f[i] = f[i-1]
			g[i] = g[i-1] + (1 * (s[i] == '>') - 1 * (s[i] == '<'))
		}
	}
	for i := n; i > 0; i-- {
		m[f[i]]++
		cnt += m[f[n]*pow(B, uint64(g[i-1]))+f[i-1]]
	}
	fmt.Println(cnt) // Print the count of valid substrings
}

// <END-OF-CODE>
