

package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define constants and input variables
var (
	n, m, mod int64
	C           [310][310]int64
	pre         [310][310]int64
	f           [310][310]int64
)

func main() {
	// Read input values
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d%d%d\n", &n, &m, &mod)

	// Initialize C array with base cases
	for i := int64(0); i <= n; i++ {
		C[i][0] = 1
		C[i][i] = 1
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
				f[i][j] = (f[i][j] + f[i-k][j]*pre[k][j+1]%mod*C[i-2][k-1]) % mod
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

// The code is now commented and easy to understand.

