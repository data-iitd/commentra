
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math/big"
)

// Modulus value for modular arithmetic
const mod = 1e9 + 7

// Maximum size of the arrays
const NMAX = 1000010

// Arrays for storing factorials, their inverses, and fast inverse
var fac [NMAX]int64
var finv [NMAX]int64
var inv [NMAX]int64

// Initialize the arrays with factorials, inverses, and fast inverse values
func init() {
	fac[0] = fac[1] = 1
	finv[0] = finv[1] = 1
	inv[1] = 1
	for i := 2; i < NMAX; i++ {
		fac[i] = fac[i-1] * int64(i) % mod
		inv[i] = mod - inv[mod%i] * (mod/i) % mod
		finv[i] = finv[i-1] * inv[i] % mod
	}
}

// Calculate the binomial coefficient C(n, k) using the precomputed values
func C(n, k int) int64 {
	if n < k {
		return 0
	}
	if n < 0 || k < 0 {
		return 0
	}
	return fac[n] * (finv[k] * finv[n-k] % mod) % mod
}

func main() {
	init()
	var X, Y int
	fmt.Scan(&X, &Y)
	if (X+Y)%3!= 0 {
		fmt.Println(0)
		return
	}
	n := (X+Y)/3 + 1
	k := 2*(n-1) - Y + 1
	fmt.Println(C(n-1, k-1))
}

