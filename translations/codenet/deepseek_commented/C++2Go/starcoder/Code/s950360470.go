<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Function to calculate a^n
func pow(a, n int) int {
	res := 1
<<<<<<< HEAD
	for n > 0 {
=======
	for ; n > 0; n >>= 1 {
>>>>>>> 98c87cb78a (data updated)
		if n&1 == 1 {
			res *= a
		}
		a *= a
<<<<<<< HEAD
		n >>= 1
=======
>>>>>>> 98c87cb78a (data updated)
	}
	return res
}

// Function to calculate a^n % mod
func mod_pow(a, n, mod int) int {
	res := 1
<<<<<<< HEAD
	for n > 0 {
=======
	for ; n > 0; n >>= 1 {
>>>>>>> 98c87cb78a (data updated)
		if n&1 == 1 {
			res = res * a % mod
		}
		a = a * a % mod
<<<<<<< HEAD
		n >>= 1
=======
>>>>>>> 98c87cb78a (data updated)
	}
	return res
}

// Function to calculate a^(-1) % mod (only if a % mod!= 0)
func mod_inv(a, mod int) int {
	return mod_pow(a, mod-2, mod)
}

// Function to calculate nCk % mod
func mod_nCk(n, k, mod int) int {
	if n == 0 || k == 0 {
		return 1
	}
	p := 1
	q := 1
	for i := n - k + 1; i <= n; i++ {
		p = p * i % mod
	}
	for i := 2; i <= k; i++ {
		q = q * i % mod
	}
	q = mod_inv(q, mod)
	return p * q % mod
}

func main() {
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
	fmt.Println(mod_nCk(k, n, int(math.Pow10(9)+7)))
}

