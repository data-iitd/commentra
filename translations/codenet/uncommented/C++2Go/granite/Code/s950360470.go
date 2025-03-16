
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007 //1000000007

//a^n                                                                                  
func pow(a, n int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res *= a
		}
		a *= a
		n >>= 1
	}
	return res
}

//a^n % mod                                                                            
func mod_pow(a, n, mod int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res = res*a % mod
		}
		a = a*a % mod
		n >>= 1
	}
	return res
}

//a^(-1) % mod (only if : a % p!= 0)                                                  
func mod_inv(a, mod int) int {
	return mod_pow(a, mod-2, mod)
}

//nCk % mod                                                                            
func mod_nCk(n, k, mod int) int {
	if n == 0 || k == 0 {
		return 1
	}
	p, q := 1, 1
	for i := n - k + 1; i <= n; i++ {
		p = (p * i) % MOD
	}
	for i := 2; i <= k; i++ {
		q = (q * i) % MOD
	}
	q = mod_inv(q, MOD)
	return (p * q) % MOD
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, k := 0, 0
	fmt.Fscanf(reader, "%d %d\n", &n, &k)
	fmt.Println(mod_nCk(k, n, MOD))
}
