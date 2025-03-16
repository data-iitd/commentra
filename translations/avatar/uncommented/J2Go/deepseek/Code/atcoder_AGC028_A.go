package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	gcd := new(big.Int).GCD(nil, nil, big.NewInt(int64(n)), big.NewInt(int64(m))).Int64()

	var s, t string
	fmt.Scan(&s, &t)

	count := 0
	for k := 0; k < int(gcd); k++ {
		if s[k*n/int(gcd)] != t[k*m/int(gcd)] {
			count++
		}
	}

	if count > 0 {
		fmt.Println(-1)
	} else {
		nm := new(big.Int).Mul(big.NewInt(int64(n)), big.NewInt(int64(m)))
		div := new(big.Int).Div(nm, big.NewInt(int64(gcd)))
		fmt.Println(div.String())
	}
}

