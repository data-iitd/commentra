package main

import (
	"fmt"
	"math/big"
)

//<START-OF-CODE>

func main() {
	n, k := 10, 5
	fmt.Println(nCk(k, n))
}

func nCk(k, n int) int {
	if n == 0 || k == 0 {
		return 1
	}
	p := big.NewInt(1)
	q := big.NewInt(1)
	for i := n - k + 1; i <= n; i++ {
		p.Mul(p, big.NewInt(int64(i)))
		p.Mod(p, big.NewInt(MOD))
	}
	for i := 2; i <= k; i++ {
		q.Mul(q, big.NewInt(int64(i)))
		q.Mod(q, big.NewInt(MOD))
	}
	q.ModInverse(q, big.NewInt(MOD))
	return int(p.Mul(p, q).Int64())
}

const MOD = 1e9 + 7

//