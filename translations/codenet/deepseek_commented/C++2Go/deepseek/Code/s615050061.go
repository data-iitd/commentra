package main

import (
	"fmt"
	"math/big"
)

type u64 uint64

const (
	B  = 13131
	N  = 500000 + 7
)

var (
	n   int
	s   [N]byte
	f   [N]u64
	g   [N]int
	map_ = make(map[u64]u64)
	cnt u64
)

// Define the pow function to calculate a^k using binary exponentiation
func pow(a, k u64) u64 {
	if k < 0 {
		k += (1 << 63) - 1 // Handle negative exponents
	}
	t := u64(1) // Initialize the result to 1
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
	// Uncomment the following lines if you want to read from a file and write to a file
	// fmt.Fscanf(os.Stdin, "%d%s", &n, s[1:])
	// fmt.Fprintf(os.Stdout, "%d\n", cnt)

	fmt.Scanf("%d%s", &n, s[1:]) // Read the input values for n and the string s
	for i := 1; i <= n; i++ {
		if s[i] == '+' || s[i] == '-' {
			f[i] = f[i-1] + u64(big.Int{}.Sub(big.NewInt(1), big.NewInt(0)).Mul(big.NewInt(1), pow(B, u64(g[i-1]))))
		} else {
			f[i] = f[i-1]
		}
		g[i] = g[i-1] + (int(s[i]) - int(s[i-1]))
	}
	for i := n; i > 0; i-- {
		map_[f[i]]++
		cnt += map_[u64(big.Int{}.Mul(f[n], pow(B, u64(g[i-1]))).Add(f[n], f[i-1]))]
	}
	fmt.Println(cnt)
}

