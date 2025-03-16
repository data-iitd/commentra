package main

import (
	"fmt"
)

const MAXN = 310

var (
	n, m, mod int64
	C         [MAXN][MAXN]int64
	pre       [MAXN][MAXN]int64
	f         [MAXN][MAXN]int64
)

func main() {
	// Read input values
	fmt.Scan(&n, &m, &mod)

	// Initialize C array with base cases
	C[0][0] = 1
	for i := int64(1); i <= n; i++ {
		// Initialize i-th row with base cases
		C[i][0] = 1
		C[i][i] = 1

		// Calculate C[i][j] using previous rows
		for j := int64(1); j < i; j++ {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod
		}
	}

	// Initialize f and pre arrays for base case
	for i := int64(0); i <= m; i++ {
		f[1][i] = 1
		pre[1][i] = m - i + 1
	}

	// Calculate f and pre arrays for all other rows
	for i := int64(2); i <= n+1; i++ {
		for j := int64(0); j <= m; j++ {
			// Calculate f[i][j] using previous rows and pre arrays
			for k := int64(1); k < i; k++ {
				f[i][j] = (f[i][j] + f[i-k][j]*pre[k][j+1]%mod*C[i-2][k-1]%mod) % mod
			}
		}

		// Calculate pre[i][j] using previous rows and f arrays
		for j := m; j >= 0; j-- {
			pre[i][j] = (pre[i][j+1] + f[i][j]) % mod
		}
	}

	// Print the result
	fmt.Println(f[n+1][0])
}

// <END-OF-CODE>
