package main

import (
	"fmt"
	"math/big"
)

const mod = 1e9 + 7

func init() {
	var i int64
	fac := big.NewInt(1)
	finv := big.NewInt(1)
	inv := big.NewInt(1)
	for i = 2; i < 1000010; i++ {
		fac.Mul(fac, big.NewInt(i))
		inv.Mul(inv, big.NewInt(mod))
		inv.Mod(inv, big.NewInt(i))
		finv.Mul(finv, inv)
		finv.Mod(finv, big.NewInt(mod))
	}
	fac.Mod(fac, big.NewInt(mod))
	finv.Mod(finv, big.NewInt(mod))
	for i = 0; i < 1000010; i++ {
		fact[i] = fac.Int64()
		finv[i] = finv.Int64()
		inv[i] = inv.Int64()
		fac.Mul(fac, big.NewInt(i+1))
		fac.Mod(fac, big.NewInt(mod))
		inv.Mul(inv, big.NewInt(mod))
		inv.Mod(inv, big.NewInt(i+1))
		inv.Mul(inv, big.NewInt(-1))
		inv.Mod(inv, big.NewInt(mod))
		finv.Mul(finv, inv)
		finv.Mod(finv, big.NewInt(mod))
	}
}

func comb(n, k int) int64 {
	if n < k {
		return 0
	}
	return fact[n] * big.NewInt(finv[k]).Mul(big.NewInt(finv[n-k]), big.NewInt(mod)).Int64() % mod
}

func main() {
	var x, y int
	fmt.Scan(&x, &y)
	if (x+y)%3!= 0 {
		fmt.Println(0)
		return
	}
	n := (x+y)/3 + 1
	k := 2*(n-1) - y + 1
	fmt.Println(comb(n-1, k-1))
}

