package main

import (
	"fmt"
)

const mod = 1e9 + 7
const NMAX = 1000010

var fac [NMAX]int
var finv [NMAX]int
var inv [NMAX]int

func init() {
	fac[0] = 1
	fac[1] = 1
	finv[0] = 1
	finv[1] = 1
	inv[1] = 1
	for i := 2; i < NMAX; i++ {
		fac[i] = fac[i-1] * i % mod
		inv[i] = mod - inv[mod%i]*(mod/i)%mod
		finv[i] = finv[i-1] * inv[i] % mod
	}
}

func C(n, k int) int {
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
	if (X+Y)%3 != 0 {
		fmt.Println(0)
		return
	}
	n := (X + Y) / 3
	k := 2*(n-1) - Y + 1
	fmt.Println(C(n-1, k-1))
}

