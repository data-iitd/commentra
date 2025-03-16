
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math/big"
)

// Define constants and input variables
<<<<<<< HEAD
var (
	n, m, mod int64
)

// Define 2D arrays and names
var (
	C [310][310]int64
	pre [310][310]int64
	f [310][310]int64
)

// Main function
func main() {
	// Read input values
	fmt.Scanf("%d%d%d", &n, &m, &mod)

	// Initialize C array with base cases
	C[0][0] = 1
	for i := 1; i <= n; i++ {
		// Initialize i-th row with base cases
		C[i][0] = C[i][i] = 1

		// Calculate C[i][j] using previous rows
=======
const mod = 1e9 + 7

func main() {
	// Read input values
	var n, m int64
	fmt.Scanf("%d %d\n", &n, &m)

	// Initialize C array with base cases
	C := make([][]int64, n+1)
	for i := range C {
		C[i] = make([]int64, n+1)
		C[i][0] = 1
		C[i][i] = 1
>>>>>>> 98c87cb78a (data updated)
		for j := 1; j < i; j++ {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod
		}
	}

	// Initialize f and pre arrays for base case
<<<<<<< HEAD
	for i := 0; i <= m; i++ {
		f[1][i] = 1
		pre[1][i] = m-i+1
=======
	f := make([][]int64, n+2)
	pre := make([][]int64, n+2)
	for i := range f {
		f[i] = make([]int64, m+1)
		pre[i] = make([]int64, m+1)
	}
	for i := range f[1] {
		f[1][i] = 1
		pre[1][i] = m - i + 1
>>>>>>> 98c87cb78a (data updated)
	}

	// Calculate f and pre arrays for all other rows
	for i := 2; i <= n+1; i++ {
		for j := 0; j <= m; j++ {
			// Calculate f[i][j] using previous rows and pre arrays
			for k := 1; k < i; k++ {
<<<<<<< HEAD
				f[i][j] += f[i-k][j] * pre[k][j+1] % mod * C[i-2][k-1] % mod
			}
=======
				f[i][j] += f[i-k][j] * pre[k][j+1] * C[i-2][k-1] % mod
			}
			f[i][j] %= mod
>>>>>>> 98c87cb78a (data updated)
		}

		// Calculate pre[i][j] using previous rows and f arrays
		for j := m; j >= 0; j-- {
			pre[i][j] = (pre[i][j+1] + f[i][j]) % mod
		}
	}

	// Print the result
	fmt.Printf("%d\n", f[n+1][0])
}

// The code is now commented and easy to understand.

